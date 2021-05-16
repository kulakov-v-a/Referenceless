static const char* rcsID mUsedVar = "$Id$";

#include "refattrib.h"
#include "attribdataholder.h"
#include "attribdesc.h"
#include "attribdescset.h"
#include "attribfactory.h"
#include "attribparam.h"
#include "attribparamgroup.h"
#include "statruncalc.h"


namespace Attrib
{

	mAttrDefCreateInstance(rAttrib)
    void rAttrib::initClass()
    {
        mAttrStartInitClass

            IntParam* winSize = new IntParam("winSize");

            winSize->setLimits(Interval<int>(0, 10));
            desc->addParam(winSize);

        mAttrEndInitClass
    }

    rAttrib::rAttrib(Desc& desc)
        : Provider(desc)
    {
        if (!isOK()) return;

        mGetInt(winSize_, "winSize");

        inpdata_.allowNull(true);
    }


    bool rAttrib::getInputOutput(int input, TypeSet<int>& res) const
    {
        if (input == 0)
            return Provider::getInputOutput(input, res);

        for (int idx = 0; idx < posandsteeridx_.steeridx_.size(); idx++)
            res += posandsteeridx_.steeridx_[idx];

        return true;
    }

    bool rAttrib::getInputData(const BinID& relpos, int zintv)
    {
        if (inpdata_.isEmpty())
            inpdata_ += 0;
        const DataHolder* inpdata = inputs_[0]->getData(relpos, zintv);
        if (!inpdata) return false;
        inpdata_.replace(0, inpdata);


        dataidx_ = getDataIndex(0);

        return true;
    }

    const BinID* rAttrib::desStepout(int inp, int out) const
    {
        if (inp == 0)
            return &stepout_;

        return 0;
    }

	bool rAttrib::computeData(const DataHolder& output, const BinID& relpos,
		int z0, int nrsamples, int threadid) const
	{
		for (int idx = 0; idx < nrsamples; idx++)
		{
			float outval = 0;
            const float trcval = getInputValue(*inpdata_[0], dataidx_, idx, z0);
				float sum = 0;
				int count = 0;
                outval = trcval / 2;
			

			setOutputValue(output, 0, idx, z0, outval);
		}

		return true;
	}

    const Interval<int>* rAttrib::desZSampMargin(int, int) const
    {
        
            return &sampgate_;

        return 0;
    }


}
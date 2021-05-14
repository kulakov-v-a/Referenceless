
#include "refattribmod.h"
#include "attribprovider.h"

namespace Attrib
{

	mExpClass(RefAttrib) rAttrib : public Provider
	{
        public:
            static void		initClass();
                rAttrib(Desc&);
            static const char* attribName() { return "Referenceless"; }
            static const char* steeringStr() { return "steering"; }
            static const char* stepoutStr() { return "stepout"; }
            void		initSteering() { stdPrepSteering(stepout_); }

        protected:

            ~rAttrib() {}
            static Provider* createInstance(Desc&);
            static void		updateDesc(Desc&);

            bool		allowParallelComputation() const { return true; }

            bool		getInputOutput(int input, TypeSet<int>& res) const;
            bool		getInputData(const BinID&, int zintv);
            bool		computeData(const DataHolder&, const BinID& relpos,
                int z0, int nrsamples, int threadid) const;
            const BinID* desStepout(int, int) const;
            const Interval<int>* desZSampMargin(int, int) const;

            int			winSize_;
            Interval<int>	sampgate_;
            BinID               stepout_;

            struct PosAndSteeridx
            {
                TypeSet<int>	steeridx_;
                TypeSet<BinID>	pos_;
            };

            PosAndSteeridx	posandsteeridx_;

            ObjectSet<const DataHolder> inpdata_;
            int				dataidx_;
            const DataHolder* steeringdata_;
	}
}
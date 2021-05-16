static const char* rcsID mUsedVar = "$Id$";

#include "uirefattrib.h"
#include "C:\Users\yspeh\ODWork\plugins\RefAttrib\refattrib.h"

#include "attribdesc.h"
#include "attribparam.h"
#include "attribparamgroup.h"
#include "survinfo.h"
#include "uiattribfactory.h"
#include "uiattrsel.h"
#include "uigeninput.h"
#include "uisteeringsel.h"
#include "uistepoutsel.h" // местная херабора

using namespace Attrib;

mInitAttribUI(uiRefAttrib, rAttrib, "Referenceless", sKeyBasicGrp())

uiRefAttrib::uiRefAttrib(uiParent* p, bool is2d)
    : uiAttrDescEd(p, is2d, HelpKey("tut", "attrib"))
{
    inpfld_ = createInpFld(is2d);

    winSizefld_ = new uiGenInput(this, "winSize",
        IntInpSpec());
    winSizefld_->attach(alignedBelow, inpfld_);

    setHAlignObj(inpfld_);
}

bool uiRefAttrib::setParameters(const Desc& desc)
{
    if (desc.attribName() != rAttrib::attribName())
        return false;

    mIfGetInt("winSize", winSize, winSizefld_->setValue(winSize));


    return true;
}

bool uiRefAttrib::setInput(const Desc& desc)
{
    putInp(inpfld_, desc, 0);
    return true;
}

bool uiRefAttrib::getParameters(Desc& desc)
{
    if (desc.attribName() != rAttrib::attribName())
        return false;

    mSetInt("winSize", winSizefld_->getFValue());
    

    return true;
}

bool uiRefAttrib::getInput(Desc& desc)
{
    fillInp(inpfld_, desc, 0);
    return true;
}
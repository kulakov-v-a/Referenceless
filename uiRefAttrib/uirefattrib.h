// ui дл€ атриба


#include "uiattrdesced.h" // холера дл€ работы с окошком атриба
#include "uirefattribmod.h"


namespace Attrib { class Desc; }
class uiAttrSel; // какие то классы
class uiGenInput;
class uiSteeringSel;
class uiStepOutSel;

mExpClass(uiRefAttrib) uiRefAttrib : public uiAttrDescEd // инит класса однако
{
	mODTextTranslationClass(uiRefAttrib); //¬озможный перевод?! хз ваще нафиг оно
	
public:

	uiRefAttrib(uiParent*, bool);

protected:
    uiAttrSel* inpfld_;
    uiGenInput* winSizefld_; //пусть короче размер окошка делает
    //uiSteeringSel* steerfld_;
    //uiStepOutSel* stepoutfld_;

    void		winSizeSel(CallBacker*);
    void                steerTypeSel(CallBacker*);

    bool		setParameters(const Attrib::Desc&);
    bool		setInput(const Attrib::Desc&);

    bool		getParameters(Attrib::Desc&);
    bool		getInput(Attrib::Desc&);

    mDeclReqAttribUIFns // € даже представлени€ не имею что это
};
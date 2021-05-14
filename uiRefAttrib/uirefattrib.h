// ui ��� ������


#include "uiattrdesced.h" // ������ ��� ������ � ������� ������
#include "uirefattribmod.h"


namespace Attrib { class Desc; }
class uiAttrSel; // ����� �� ������
class uiGenInput;
class uiSteeringSel;
class uiStepOutSel;

mExpClass(uiRefAttrib) uiRefAttrib : public uiAttrDescEd // ���� ������ ������
{
	mODTextTranslationClass(uiRefAttrib); //��������� �������?! �� ���� ����� ���
	
public:

	uiRefAttrib(uiParent*, bool);

protected:
    uiAttrSel* inpfld_;
    uiGenInput* winSizefld_; //����� ������ ������ ������ ������
    //uiSteeringSel* steerfld_;
    //uiStepOutSel* stepoutfld_;

    void		winSizeSel(CallBacker*);
    void                steerTypeSel(CallBacker*);

    bool		setParameters(const Attrib::Desc&);
    bool		setInput(const Attrib::Desc&);

    bool		getParameters(Attrib::Desc&);
    bool		getInput(Attrib::Desc&);

    mDeclReqAttribUIFns // � ���� ������������� �� ���� ��� ���
};
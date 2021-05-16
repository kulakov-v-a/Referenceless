//������� ����� ��� ������� uiRefAttrib

static const char* rcsID mUsedVar = "$Id$";


#include "uirefattribmod.h" // ����������� ��� ������
#include "uirefattribdeps.h"

#include "uirefattrib.h"

#include "filepath.h" // ���� ��� ����� ��� ��� ������, �� �� �� �����
#include "ioman.h"
#include "ioobj.h"
#include "oddirs.h"
#include "ptrman.h"
#include "seistype.h"
#include "survinfo.h"

#include "odplugin.h" // ����� ������� �����, ������ � ���������� ��� �������(�� ���)


static const int cRefIdx = -1100;

mExternC(uiRefAttrib) int GetuiRefAttribPluginType(); // ���������� ��� �������
mExternC(uiRefAttrib) PluginInfo* GetuiRefAttribPluginInfo(); // ���������� ���� �� �������
mExternC(uiRefAttrib) const char* InituiRefAttribPlugin(int, char**); //�������������� ������

int GetuiRefAttribPluginType()
{
    return PI_AUTO_INIT_LATE; // �������� ����� ����� �����
}

PluginInfo* GetuiRefAttribPluginInfo()
{
    mDefineStaticLocalObject(PluginInfo, info, );
    info.dispname_ = "������ ��� ������������ �������������(GUI)";
    info.productname_ = "Referenceless";
    info.creator_ = "kulakov-v-a";
    info.version_ = "0.1";
    info.text_ =
        "�������� ����������, �����.\n"
        "� ���� ������.";
    return &info;
}

const char* InituiRefAttribPlugin(int argc, char** argv)
{

    uiRefAttrib::initClass();

    return nullptr;
}
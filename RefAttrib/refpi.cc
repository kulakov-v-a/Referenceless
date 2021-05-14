// плагин с расчетами (real-work-do ©)


static const char* rcsID mUsedVar = "$Id$";

#include "refattribmod.h"
#include "refattrib.h"
#include "odplugin.h"


mExternC(RefAttrib) int GetRefAttribPluginType();
mExternC(RefAttrib) PluginInfo* GetRefAttribPluginInfo();
mExternC(RefAttrib) const char* InitRefAttribPlugin(int, char**);

int GetRefAttribPluginType()
{
    return PI_AUTO_INIT_EARLY;
}


PluginInfo* GetRefAttribPluginInfo()
{
    mDefineStaticLocalObject(PluginInfo, info, );
    info.dispname_ = "Безэталонный атрибут (Base)";
    info.productname_ = "Referenceless";
    info.creator_ = "kulakov-v-a";
    info.version_ = "1";
    info.text_ =
        "da\n"
        "net";
    return &info;
}


const char* InitRefAttribPlugin(int argc, char** argv)
{
    Attrib::rAttrib::initClass();

    return nullptr;
}

//Входная точка для плагина uiRefAttrib

static const char* rcsID mUsedVar = "$Id$";


#include "uirefattribmod.h" // Зависимости для сборки
#include "uirefattribdeps.h"

#include "uirefattrib.h"

#include "filepath.h" // хрен его пойми зач эти пакеты, но че то общее
#include "ioman.h"
#include "ioobj.h"
#include "oddirs.h"
#include "ptrman.h"
#include "seistype.h"
#include "survinfo.h"

#include "odplugin.h" // супер главная хренб, видимо с прототипом для плагина(хз аще)


static const int cRefIdx = -1100;

mExternC(uiRefAttrib) int GetuiRefAttribPluginType(); // Возвращает тип плагина
mExternC(uiRefAttrib) PluginInfo* GetuiRefAttribPluginInfo(); // возвращает инфо по плагину
mExternC(uiRefAttrib) const char* InituiRefAttribPlugin(int, char**); //Инициализирует плагин

int GetuiRefAttribPluginType()
{
    return PI_AUTO_INIT_LATE; // загрузка после инита всего
}

PluginInfo* GetuiRefAttribPluginInfo()
{
    mDefineStaticLocalObject(PluginInfo, info, );
    info.dispname_ = "Плагин для безэталонной классификации(GUI)";
    info.productname_ = "Referenceless";
    info.creator_ = "kulakov-v-a";
    info.version_ = "0.1";
    info.text_ =
        "Заведись пожалуйста, срань.\n"
        "Я тебя умоляю.";
    return &info;
}

const char* InituiRefAttribPlugin(int argc, char** argv)
{

    uiRefAttrib::initClass();

    return nullptr;
}
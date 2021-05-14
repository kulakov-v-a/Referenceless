static const char* rcsID mUsedVar = "$Id$";

#include "uirefattrib.h"
// тут еще дожен бытб инклуд класса с просчетом этого дела, но его еще не создал

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

mInitAttribUI(uiRefAttrib, Tutorial, "Referenceless", sKeyBasicGrp())
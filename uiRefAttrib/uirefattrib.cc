static const char* rcsID mUsedVar = "$Id$";

#include "uirefattrib.h"
// ��� ��� ����� ���� ������ ������ � ��������� ����� ����, �� ��� ��� �� ������

#include "attribdesc.h"
#include "attribparam.h"
#include "attribparamgroup.h"
#include "survinfo.h"
#include "uiattribfactory.h"
#include "uiattrsel.h"
#include "uigeninput.h"
#include "uisteeringsel.h"
#include "uistepoutsel.h" // ������� ��������

using namespace Attrib;

mInitAttribUI(uiRefAttrib, Tutorial, "Referenceless", sKeyBasicGrp())
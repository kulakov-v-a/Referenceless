

set(OD_MODULE_NAME uiRefAttrib)
set(OD_IS_PLUGIN 1 )
set(OD_MODULE_DEPS uiODMain RefAttrib)
set(OD_MODULE_SOURCES uiRefAttribPI.cc uirefattrib.cc)
SET( OD_PLUGIN_ALO_EXEC ${OD_MAIN_EXEC} )
SET( OD_NO_ALO_ENTRY 1 )
OD_INIT_MODULE()


#-----------------------------------------------------------------------------
set(MODULE_NAME ExecutionModelTour)

#-----------------------------------------------------------------------------
SEMMacroBuildCLI(
  NAME ${MODULE_NAME}
  LOGO_HEADER ${Slicer_SOURCE_DIR}/Resources/BillsLogo.h
  TARGET_LIBRARIES MRMLCore
  INCLUDE_DIRECTORIES
    ${MRMLCore_INCLUDE_DIRS}
  )

#-----------------------------------------------------------------------------
if(BUILD_TESTING)
  add_subdirectory(Testing)
endif()

set(KIT qSlicer${MODULE_NAME}Module)

#-----------------------------------------------------------------------------
set(KIT_TEST_SRCS
  qSlicerCamerasModuleWidgetTest1.cxx
  vtkSlicerCamerasModuleLogicCopyImportedCamerasTest.cxx
  )

#-----------------------------------------------------------------------------
slicerMacroConfigureModuleCxxTestDriver(
  NAME ${KIT}
  SOURCES ${KIT_TEST_SRCS}
  WITH_VTK_DEBUG_LEAKS_CHECK
  )

#-----------------------------------------------------------------------------
simple_test(qSlicerCamerasModuleWidgetTest1)
simple_test(vtkSlicerCamerasModuleLogicCopyImportedCamerasTest)

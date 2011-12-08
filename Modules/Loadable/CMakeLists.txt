
include(${Slicer_CMAKE_DIR}/SlicerMacroBuildQtModule.cmake)

set(qtmodules
  AtlasCreator
  Colors
  Transforms
  Annotations
  Data
  FetchMI
  #Measurements
  Models
  ModelMirror
  ModelTransform
  #FiberBundles
  SceneViews
  SlicerWelcome
  Tractography
  TractographyDisplay
  ViewControllers
  Volumes
  TractographyFiducialSeeding # tractography depends of Volumes
  CropVolume
  VolumeRendering # Volume Rendering depends of Volumes
  )
if(BUILD_TESTING)
  list(APPEND qtmodules ModuleTemplate)
endif()

foreach(module ${qtmodules})
  list(FIND Slicer_QTLOADABLEMODULES_DISABLED ${module} _module_disabled)
  if(${_module_disabled} STREQUAL "-1")
    add_subdirectory(${module})
  endif()
endforeach(module)

if(Slicer_BUILD_EMSegment)
  # NOTE: EMSegment source code is checkout from Slicer3 repository using
  #       "External_EMSegment.cmake".
  add_subdirectory(
    ${EMSegment_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}/EMSegment
    )
endif()
# FindDPP.cmake
find_path(DPP_INCLUDE_DIRS dpp/dpp.h)
find_library(DPP_LIBRARIES dpp)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(DPP DEFAULT_MSG DPP_INCLUDE_DIRS DPP_LIBRARIES)

if (DPP_FOUND)
    set(DPP_INCLUDE_DIRS ${DPP_INCLUDE_DIRS})
    set(DPP_LIBRARIES ${DPP_LIBRARIES})
endif()
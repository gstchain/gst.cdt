include(ExternalProject)
# if no cdt root is given use default path
if(GSTIO_CDT_ROOT STREQUAL "" OR NOT GSTIO_CDT_ROOT)
   find_package(gstio.cdt)
endif()

ExternalProject_Add(
   send_inline_project
   SOURCE_DIR ${CMAKE_SOURCE_DIR}/src
   BINARY_DIR ${CMAKE_BINARY_DIR}/send_inline
   CMAKE_ARGS -DCMAKE_TOOLCHAIN_FILE=${GSTIO_CDT_ROOT}/lib/cmake/gstio.cdt/GstioWasmToolchain.cmake
   UPDATE_COMMAND ""
   PATCH_COMMAND ""
   TEST_COMMAND ""
   INSTALL_COMMAND ""
   BUILD_ALWAYS 1
)
cmake_minimum_required( VERSION 3.5 )

set(GSTIO_VERSION_MIN "1.4")
set(GSTIO_VERSION_SOFT_MAX "1.4")
#set(GSTIO_VERSION_HARD_MAX "")

find_package(gstio)

### Check the version of gstio
set(VERSION_MATCH_ERROR_MSG "")
GSTIO_CHECK_VERSION(VERSION_OUTPUT "${GSTIO_VERSION}"
                                   "${GSTIO_VERSION_MIN}"
                                   "${GSTIO_VERSION_SOFT_MAX}"
                                   "${GSTIO_VERSION_HARD_MAX}"
                                   VERSION_MATCH_ERROR_MSG)
if(VERSION_OUTPUT STREQUAL "MATCH")
   message(STATUS "Using gstio version ${GSTIO_VERSION}")
elseif(VERSION_OUTPUT STREQUAL "WARN")
   message(WARNING "Using gstio version ${GSTIO_VERSION} even though it exceeds the maximum supported version of ${GSTIO_VERSION_SOFT_MAX}; continuing with configuration, however build may fail.\nIt is recommended to use gstio version ${GSTIO_VERSION_SOFT_MAX}.x")
else() # INVALID OR MISMATCH
   message(FATAL_ERROR "Found gstio version ${GSTIO_VERSION} but it does not satisfy version requirements: ${VERSION_MATCH_ERROR_MSG}\nPlease use gstio version ${GSTIO_VERSION_SOFT_MAX}.x")
endif(VERSION_OUTPUT STREQUAL "MATCH")


enable_testing()

configure_file(${CMAKE_SOURCE_DIR}/contracts.hpp.in ${CMAKE_BINARY_DIR}/contracts.hpp)

include_directories(${CMAKE_BINARY_DIR})

file(GLOB INT_TESTS "*.cpp" "*.hpp")

add_gstio_test( integration_tests ${INT_TESTS} )

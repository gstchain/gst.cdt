file(GLOB HEADERS "*.hpp"
                  "*.h")

add_library(gstio
            gstiolib.cpp
            crypto.cpp
            ${HEADERS})

add_library(gstio_malloc
            malloc.cpp
            ${HEADERS})

add_library(gstio_dsm
            simple_malloc.cpp
            ${HEADERS})

add_library(gstio_cmem
            memory.cpp
            ${HEADERS})

add_native_library(native_gstio
                   gstiolib.cpp
                   crypto.cpp
                   malloc.cpp
                   ${HEADERS})

set_target_properties(gstio_malloc PROPERTIES LINKER_LANGUAGE C)

target_include_directories(gstio PUBLIC
                                 ${CMAKE_SOURCE_DIR}/libc/musl/include
                                 ${CMAKE_SOURCE_DIR}/libc/musl/src/internal
                                 ${CMAKE_SOURCE_DIR}/libc/musl/src/crypt
                                 ${CMAKE_SOURCE_DIR}/libc/musl/arch/gst
                                 ${CMAKE_SOURCE_DIR}/libcxx/include
                                 ${CMAKE_SOURCE_DIR}
                                 ${CMAKE_SOURCE_DIR}/boost/include)

target_link_libraries( gstio c c++ )
add_dependencies( native_gstio gstio )

add_custom_command( TARGET gstio POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:gstio> ${BASE_BINARY_DIR}/lib )
add_custom_command( TARGET gstio_malloc POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:gstio_malloc> ${BASE_BINARY_DIR}/lib )
add_custom_command( TARGET gstio_dsm POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:gstio_dsm> ${BASE_BINARY_DIR}/lib )
add_custom_command( TARGET gstio_cmem POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:gstio_cmem> ${BASE_BINARY_DIR}/lib )
add_custom_command( TARGET native_gstio POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:native_gstio> ${BASE_BINARY_DIR}/lib )

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/../gstiolib DESTINATION ${BASE_BINARY_DIR}/include FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp")

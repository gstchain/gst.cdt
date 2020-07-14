configure_file(${CMAKE_CURRENT_SOURCE_DIR}/gstio-cc.cpp.in ${CMAKE_BINARY_DIR}/gstio-cc.cpp)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/gstio-cpp.cpp.in ${CMAKE_BINARY_DIR}/gstio-cpp.cpp)

add_tool(gstio-cc)
add_tool(gstio-cpp)

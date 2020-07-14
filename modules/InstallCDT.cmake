add_custom_command( TARGET GstioClang POST_BUILD COMMAND mkdir -p ${CMAKE_BINARY_DIR}/bin )
macro( gstio_clang_install file )
   set(BINARY_DIR ${CMAKE_BINARY_DIR}/gstio_llvm/bin)
   add_custom_command( TARGET GstioClang POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${BINARY_DIR}/${file} ${CMAKE_BINARY_DIR}/bin/ )
   install(FILES ${BINARY_DIR}/${file}
      DESTINATION ${CDT_INSTALL_PREFIX}/bin
      PERMISSIONS OWNER_READ OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE)
endmacro( gstio_clang_install )

macro( gstio_clang_install_and_symlink file symlink )
   set(BINARY_DIR ${CMAKE_BINARY_DIR}/gstio_llvm/bin)
   add_custom_command( TARGET GstioClang POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${BINARY_DIR}/${file} ${CMAKE_BINARY_DIR}/bin/ )
   add_custom_command( TARGET GstioClang POST_BUILD COMMAND cd ${CMAKE_BINARY_DIR}/bin && ln -sf ${file} ${symlink} )
   install(FILES ${BINARY_DIR}/${file}
      DESTINATION ${CDT_INSTALL_PREFIX}/bin
      PERMISSIONS OWNER_READ OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE)
   install(CODE "execute_process( COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_INSTALL_PREFIX}/bin)")
   install(CODE "execute_process( COMMAND ${CMAKE_COMMAND} -E create_symlink ${CDT_INSTALL_PREFIX}/bin/${file} ${CMAKE_INSTALL_PREFIX}/bin/${symlink})")
endmacro( gstio_clang_install_and_symlink )

macro( gstio_tool_install file )
   set(BINARY_DIR ${CMAKE_BINARY_DIR}/tools/bin)
   add_custom_command( TARGET GstioTools POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${BINARY_DIR}/${file} ${CMAKE_BINARY_DIR}/bin/ )
   install(FILES ${BINARY_DIR}/${file}
      DESTINATION ${CDT_INSTALL_PREFIX}/bin
      PERMISSIONS OWNER_READ OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE)
endmacro( gstio_tool_install )

macro( gstio_tool_install_and_symlink file symlink )
   set(BINARY_DIR ${CMAKE_BINARY_DIR}/tools/bin)
   add_custom_command( TARGET GstioTools POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${BINARY_DIR}/${file} ${CMAKE_BINARY_DIR}/bin/ )
   install(FILES ${BINARY_DIR}/${file}
      DESTINATION ${CDT_INSTALL_PREFIX}/bin
      PERMISSIONS OWNER_READ OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE)
   install(CODE "execute_process( COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_INSTALL_PREFIX}/bin)")
   install(CODE "execute_process( COMMAND ${CMAKE_COMMAND} -E create_symlink ${CDT_INSTALL_PREFIX}/bin/${file} ${CMAKE_INSTALL_PREFIX}/bin/${symlink})")
endmacro( gstio_tool_install_and_symlink )

macro( gstio_cmake_install_and_symlink file symlink )
   set(BINARY_DIR ${CMAKE_BINARY_DIR}/modules)
   install(CODE "execute_process( COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_INSTALL_PREFIX}/lib/cmake/gstio.cdt)")
   install(CODE "execute_process( COMMAND ${CMAKE_COMMAND} -E create_symlink ${CDT_INSTALL_PREFIX}/lib/cmake/gstio.cdt/${file} ${CMAKE_INSTALL_PREFIX}/lib/cmake/gstio.cdt/${symlink})")
endmacro( gstio_cmake_install_and_symlink )

macro( gstio_libraries_install)
   execute_process(COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/lib)
   execute_process(COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/include)
   install(DIRECTORY ${CMAKE_BINARY_DIR}/lib/ DESTINATION ${CDT_INSTALL_PREFIX}/lib)
   install(DIRECTORY ${CMAKE_BINARY_DIR}/include/ DESTINATION ${CDT_INSTALL_PREFIX}/include)
endmacro( gstio_libraries_install )

gstio_clang_install_and_symlink(llvm-ranlib gstio-ranlib)
gstio_clang_install_and_symlink(llvm-ar gstio-ar)
gstio_clang_install_and_symlink(llvm-nm gstio-nm)
gstio_clang_install_and_symlink(llvm-objcopy gstio-objcopy)
gstio_clang_install_and_symlink(llvm-objdump gstio-objdump)
gstio_clang_install_and_symlink(llvm-readobj gstio-readobj)
gstio_clang_install_and_symlink(llvm-readelf gstio-readelf)
gstio_clang_install_and_symlink(llvm-strip gstio-strip)

gstio_clang_install(opt)
gstio_clang_install(llc)
gstio_clang_install(lld)
gstio_clang_install(ld.lld)
gstio_clang_install(ld64.lld)
gstio_clang_install(clang-7)
gstio_clang_install(wasm-ld)

gstio_tool_install_and_symlink(gstio-pp gstio-pp)
gstio_tool_install_and_symlink(gstio-wast2wasm gstio-wast2wasm)
gstio_tool_install_and_symlink(gstio-wasm2wast gstio-wasm2wast)
gstio_tool_install_and_symlink(gstio-cc gstio-cc)
gstio_tool_install_and_symlink(gstio-cpp gstio-cpp)
gstio_tool_install_and_symlink(gstio-ld gstio-ld)
gstio_tool_install_and_symlink(gstio-abigen gstio-abigen)
gstio_tool_install_and_symlink(gstio-abidiff gstio-abidiff)
gstio_tool_install_and_symlink(gstio-init gstio-init)

gstio_clang_install(../lib/LLVMGstioApply${CMAKE_SHARED_LIBRARY_SUFFIX})
gstio_clang_install(../lib/LLVMGstioSoftfloat${CMAKE_SHARED_LIBRARY_SUFFIX})
gstio_clang_install(../lib/gstio_plugin${CMAKE_SHARED_LIBRARY_SUFFIX})

gstio_cmake_install_and_symlink(gstio.cdt-config.cmake gstio.cdt-config.cmake)
gstio_cmake_install_and_symlink(GstioWasmToolchain.cmake GstioWasmToolchain.cmake)
gstio_cmake_install_and_symlink(GstioCDTMacros.cmake GstioCDTMacros.cmake)

gstio_libraries_install()

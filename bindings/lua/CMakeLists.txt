find_package(Lua REQUIRED)
set_source_files_properties("nauticalua.i" PROPERTIES CPLUSPLUS TRUE)

SWIG_ADD_MODULE(nauticalua lua "nauticalua.i")
SWIG_LINK_LIBRARIES(nauticalua ${LUA_LIBRARIES})
include_directories(${LUA_INCLUDE_DIR})
set_target_properties(${SWIG_MODULE_nauticalua_REAL_NAME} PROPERTIES PREFIX "")

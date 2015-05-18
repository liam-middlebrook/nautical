find_package(Lua REQUIRED)
set_source_files_properties("nauticalua.i" PROPERTIES CPLUSPLUS TRUE)

set(SWIG_MODULE_nauticalua_EXTRA_DEPS ${interface_files})
include_directories(${LUA_INCLUDE_DIR})

set(swig_runtime swigruntime.lua.h)
add_custom_command(
	OUTPUT ${swig_runtime}
	COMMAND
		${SWIG_EXECUTABLE} -Wall -c++ -lua -external-runtime ${swig_runtime}
)

SWIG_ADD_MODULE(nauticalua lua "nauticalua.i")
SWIG_LINK_LIBRARIES(nauticalua ${LUA_LIBRARIES} nautical-base)
set_target_properties(${SWIG_MODULE_nauticalua_REAL_NAME} PROPERTIES PREFIX "")
add_library(nsl_lua lualoader.cpp ${swig_runtime})
target_link_libraries(nsl_lua ${LUA_LIBRARIES} nautical-base)
target_include_directories(nsl_lua PUBLIC ${LUA_INCLUDE_DIR} ".")

install(
	TARGETS ${SWIG_MODULE_nauticalua_REAL_NAME}
	DESTINATION ${NAUTICAL_SHARE_BASE}/bindings/lua
)


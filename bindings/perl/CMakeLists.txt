find_package(PerlLibs REQUIRED)
set_source_files_properties("nauticalpl.i" PROPERTIES CPLUSPLUS TRUE)

set(SWIG_MODULE_nauticalpl_EXTRA_DEPS ${interface_files})

SWIG_ADD_MODULE(nauticalpl perl "nauticalpl.i")
SWIG_LINK_LIBRARIES(nauticalpl ${PERL_LIBRARY} nautical-base)
include_directories(${PERL_INCLUDE_PATH})
add_definitions(
	"-Wno-unused-parameter"
	"-Wno-unused-variable"
	"-Wno-pedantic"
	"-Wno-literal-suffix"
)


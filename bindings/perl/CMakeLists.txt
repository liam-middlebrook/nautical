find_package(PerlLibs REQUIRED)
set_source_files_properties("nauticalpl.i" PROPERTIES CPLUSPLUS TRUE)

SWIG_ADD_MODULE(nauticalpl perl "nauticalpl.i")
SWIG_LINK_LIBRARIES(nauticalpl ${PERL_LIBRARY})
include_directories(${PERL_INCLUDE_PATH})
add_definitions(
	"-Wno-unused-parameter"
	"-Wno-unused-variable"
	"-Wno-pedantic"
	"-Wno-literal-suffix"
)


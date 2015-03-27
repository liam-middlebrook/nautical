find_package(PythonLibs REQUIRED)
set_source_files_properties("nauticalpy.i" PROPERTIES CPLUSPLUS TRUE)

set(CMAKE_SWIG_FLAGS -builtin -O -modern -Wall)

set(SWIG_MODULE_nauticalpy_EXTRA_DEPS ${interface_files})
include_directories(${PYTHON_INCLUDE_DIRS} ".")
add_definitions(
	"-Wno-unused-parameter"
	"-Wno-unused-variable"
)


SWIG_ADD_MODULE(nauticalpy python "nauticalpy.i")
SWIG_LINK_LIBRARIES(nauticalpy ${PYTHON_LIBRARIES} nautical-base)
add_library(nsl_python PythonLoader.cpp)
target_link_libraries(nsl_python ${PYTHON_LIBRARIES} nautical-base)


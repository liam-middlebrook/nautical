find_package(PythonLibs REQUIRED)
set_source_files_properties("nauticalpy.i" PROPERTIES CPLUSPLUS TRUE)

set(CMAKE_SWIG_FLAGS -O -modern -Wall)

set(SWIG_MODULE_nauticalpy_EXTRA_DEPS ${interface_files})
include_directories(${PYTHON_INCLUDE_DIRS} ".")
add_definitions(
	"-Wno-unused-parameter"
	"-Wno-unused-variable"
	"-Wno-missing-field-initializers"
	"-Wno-deprecated-register"
	"-DSWIG_TYPE_TABLE=nauticalpy"
)

set(swig_runtime swigruntime.py.h)
add_custom_command(
	OUTPUT ${swig_runtime}
	COMMAND
	${SWIG_EXECUTABLE} -Wall -c++ -python -external-runtime ${swig_runtime}
)


SWIG_ADD_MODULE(nauticalpy python "nauticalpy.i")
SWIG_LINK_LIBRARIES(nauticalpy ${PYTHON_LIBRARIES} nautical-base)
add_library(nsl_python pythonloader.cpp ${swig_runtime})
target_link_libraries(nsl_python ${PYTHON_LIBRARIES} nautical-base)
target_include_directories(nsl_python PUBLIC ${PYTHON_INCLUDE_DIRS} ".")

install(
	TARGETS ${SWIG_MODULE_nauticalpy_REAL_NAME}
	DESTINATION ${NAUTICAL_SHARE_BASE}/bindings/python
)

install(
	FILES ${CMAKE_CURRENT_BINARY_DIR}/nauticalpy.py
	DESTINATION ${NAUTICAL_SHARE_BASE}/bindings/python
)


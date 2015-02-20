find_package(PythonLibs REQUIRED)
set_source_files_properties("nauticalpy.i" PROPERTIES CPLUSPLUS TRUE)

SWIG_ADD_MODULE(nauticalpy python "nauticalpy.i")
SWIG_LINK_LIBRARIES(nauticalpy ${PYTHON_LIBRARIES})
include_directories(${PYTHON_INCLUDE_DIRS})

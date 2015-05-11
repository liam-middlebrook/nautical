cmake_minimum_required(VERSION 3.0.2)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_LIST_DIR}/CMake)
find_package(CUnit REQUIRED)
find_package(FreeImage REQUIRED)
find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)
find_package(PkgConfig REQUIRED)
find_package(rapidjson REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)

include_directories(
    "include"
)

if(NOT MSVC)
    add_definitions(
        -std=c++11
        -Wall
        -Wextra
        -pedantic
    )
endif()

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(h_files
    "include/engine.h"
    "include/gamecomponent.h"
    "include/gameobject.h"
    "include/script.h"
    "include/transform.h"
    "include/util.h"
    "include/components/rendercomponent.h"
    "include/graphics/color.h"
    "include/graphics/shaderloader.h"
    "include/graphics/textureloader.h"
    "include/graphics/window.h"
    "include/math/matrix3.h"
    "include/math/matrix4.h"
    "include/math/vector2.h"
    "include/math/vector3.h"
    "include/math/vector4.h"
    "include/systems/input/keyboard.h"
    "include/systems/renderer.h"
)

#####
# Core library

add_library(nautical-base
    ${h_files}
    "src/components/rendercomponent.cpp"
    "src/engine.cpp"
    "src/gameobject.cpp"
    "src/gameobject.cpp"
    "src/graphics/shaderloader.cpp"
    "src/graphics/textureloader.cpp"
    "src/graphics/window.cpp"
    "src/systems/input/keyboard.cpp"
    "src/systems/renderer.cpp"
    "src/util.cpp"
)

#####
# SWIG libraries

find_package(SWIG)
set(nautical_bind_libs)
if(SWIG_FOUND)
	include(UseSWIG)
    add_definitions("-DNAUTICAL_SWIG")

	file(GLOB interface_files "bindings/lib/*" nautical.i)
	set_source_files_properties(${interface_files} PROPERTIES CPLUSPLUS TRUE)
	set_source_files_properties(bindings/nautical.i PROPERTIES DEPENDS "${interface_files}")
	macro(add_swig_language lang default)
		string(TOUPPER "${lang}" upperlang)
		string(TOLOWER "${lang}" lowerlang)
		option(INTERFACE_${upperlang} "Enable ${lang} SWIG interface" ${default})
		if(INTERFACE_${upperlang})
            add_definitions("-DNAUTICAL_BIND_${upperlang}")
            include_directories(
                bindings/${lowerlang}
                ${CMAKE_CURRENT_BINARY_DIR}/bindings/${lowerlang}
            )
			add_subdirectory(bindings/${lowerlang})
            list(APPEND nautical_bind_libs nsl_${lowerlang})
		endif()
	endmacro()

    add_swig_language(Lua FALSE)
	#add_swig_language(Perl FALSE)
	add_swig_language(Python TRUE)
endif()

#####
# Main executable

add_executable(nautical
    ${h_files}
    "src/main.cpp"
    ${nautical_bind_files}
)

target_link_libraries(nautical
    nautical-base
    ${nautical_bind_libs}
)

#####
# Testing executable

add_executable(nautical-tests
    ${h_files}
    "tests/main.cpp"
    "tests/test.h"
    "tests/test_list.h"
    "tests/matrix3.cpp"
    "tests/matrix3.h"
    "tests/matrix4.cpp"
    "tests/matrix4.h"
    "tests/vector2.cpp"
    "tests/vector2.h"
    "tests/vector3.cpp"
    "tests/vector3.h"
    "tests/vector4.cpp"
    "tests/vector4.h"
)

target_include_directories(nautical-tests
    PUBLIC tests ${CUNIT_INCLUDE_DIRS}
)
target_link_libraries(nautical-base
    ${GLEW_LIBRARIES}
    ${GLFW_LIBRARIES}
    ${FREEIMAGE_LIBRARIES}
    ${OPENGL_LIBRARIES}
)
target_link_libraries(nautical-tests ${CUNIT_LIBRARY})

enable_testing()

foreach(tst Vector2 Vector3 Vector4 Matrix3 Matrix4)
    add_test(
        NAME ${tst}
        COMMAND nautical-tests ${tst}
    )
endforeach()

file(COPY
    "resources/vert.glsl"
    "resources/frag.glsl"
    "resources/config.json"
     DESTINATION ${CMAKE_BINARY_DIR})

# vim: ts=4 sw=4 et

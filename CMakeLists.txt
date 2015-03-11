cmake_minimum_required(VERSION 3.0.2)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_LIST_DIR}/CMake)
find_package(CUnit REQUIRED)
find_package(IniParser REQUIRED)
find_package(PkgConfig REQUIRED)
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

set(h_files
    "include/gamecomponent.h"
    "include/gameobject.h"
    "include/nauticalscript.h"
    "include/transform.h"
    "include/util.h"
    "include/math/matrix3.h"
    "include/math/matrix4.h"
    "include/math/vector2.h"
    "include/math/vector3.h"
    "include/math/vector4.h"
)
set(libraries X11 glfw GL GLEW m stdc++ iniparser)

#####
# Main executable

add_executable(nautical
    ${h_files}
    "src/main.cpp"
    "src/gameobject.cpp"
    "src/util.cpp"
    "src/graphics/window.cpp"
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
target_link_libraries(nautical
    ${GLFW_LIBRARIES}
    ${INIPARSER_LIBRARIES}
)
target_link_libraries(nautical-tests ${CUNIT_LIBRARY})

enable_testing()

foreach(tst Vector2 Vector3 Vector4 Matrix3 Matrix4)
    add_test(
        NAME ${tst}
        COMMAND nautical-tests ${tst}
    )
endforeach()
# vim: ts=4 sw=4 et

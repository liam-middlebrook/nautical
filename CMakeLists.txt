cmake_minimum_required(VERSION 3.0.2)

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
	"include/util.h"
	"include/math/matrix3.h"
	"include/math/matrix4.h"
	"include/math/vector2.h"
	"include/math/vector3.h"
	"include/math/vector4.h"
)
set(libraries X11 glfw GL GLEW m stdc++)

#####
# Main executable

add_executable(nautical
	${h_files}
	"src/main.cpp"
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
	PUBLIC tests
)

target_link_libraries(nautical-tests cunit)

enable_testing()

foreach(tst Vector2 Vector3 Vector4 Matrix3 Matrix4)
	add_test(
		NAME ${tst}
		COMMAND nautical-tests ${tst}
	)
endforeach()

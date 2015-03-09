#ifndef TEST_LIST_H_
#define TEST_LIST_H_

// Begin Test Suite Declarations

#include "vector2.h"
#include "vector3.h"
#include "vector4.h"
#include "matrix3.h"
#include "matrix4.h"

static const SuiteDef suites[] = {{"Vector2", tests_vector2},
                                  {"Vector3", tests_vector3},
                                  {"Vector4", tests_vector4},
                                  {"Matrix3", tests_matrix3},
                                  {"Matrix4", tests_matrix4},
                                  {nullptr, nullptr}};

#endif

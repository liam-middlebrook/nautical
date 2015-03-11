#pragma once

#include <math.h>

#define PI acos(-1.0)

template <typename T>
inline bool tol(const T& a, const T& b, const T& tol = 0.00001)
{
    return fabs(a - b) < tol;
}

template <typename T>
inline void swap(T& a, T& b)
{
    T c = T(a);
    a = b;
    b = c;
}

template <typename T>
inline T degreesToRadians(const T& val)
{
    return val * (PI / 180.0);
}

template <typename T>
inline T radiansToDegrees(const T& val)
{
    return val * (180.0 / PI);
}

void write_string_to_file(const char* filename, const char* string);

int does_file_exist(const char* filename);

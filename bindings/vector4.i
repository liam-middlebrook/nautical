// vim: ft=swig
%{
#include "math/vector4.h"
%}
%include "math/vector4.h"
%template(Vector4i) nautical::math::Vector4<int>;
%template(Vector4f) nautical::math::Vector4<float>;
%template(Vector4d) nautical::math::Vector4<double>;
%template(Vector4b) nautical::math::Vector4<bool>;

// vim: ft=swig
%{
#include "math/vector2.h"
%}
%include "math/vector2.h"
%template(Vector2i) nautical::math::Vector2<int>;
%template(Vector2f) nautical::math::Vector2<float>;
%template(Vector2d) nautical::math::Vector2<double>;
%template(Vector2b) nautical::math::Vector2<bool>;

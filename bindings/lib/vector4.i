// vim: ft=swig
%{
#include "math/vector4.h"
%}
%extend nautical::math::Vector4 {
    nautical_accessors
    %rename(zero)    ZERO;
    %rename(one)     ONE;
    %rename(right)   RIGHT;
    %rename(up)      UP;
    %rename(forward) FORWARD;
    %rename(ana)     ANA;
}
%include "math/vector4.h"
%template(Vector4i) nautical::math::Vector4<int>;
%template(Vector4f) nautical::math::Vector4<float>;
%template(Vector4d) nautical::math::Vector4<double>;
%template(Vector4b) nautical::math::Vector4<bool>;

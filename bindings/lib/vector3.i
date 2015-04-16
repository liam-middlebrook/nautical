// vim: ft=swig
%{
#include "math/vector3.h"
%}
%extend nautical::math::Vector3 {
    nautical_accessors
    %rename(zero)    ZERO;
    %rename(one)     ONE;
    %rename(right)   RIGHT;
    %rename(up)      UP;
    %rename(forward) FORWARD;
}
%include "math/vector3.h"
%template(Vector3i) nautical::math::Vector3<int>;
%template(Vector3f) nautical::math::Vector3<float>;
%template(Vector3d) nautical::math::Vector3<double>;
%template(Vector3b) nautical::math::Vector3<bool>;

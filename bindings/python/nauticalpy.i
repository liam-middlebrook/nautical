// vim: ft=swig
%module nauticalpy
%include <std_string.i>
%feature("autodoc", "2");

%{
#include <sstream>
%}
%ignore operator <<;
%define nautical_accessors
    %ignore operator =;
    %ignore operator T*;
    %ignore operator [];
    T& __setitem__(int i, const T& val) {
        return ((*$self)[i] = val);
    }
    T __getitem__(int i) {
        return (*$self)[i];
    }
    %feature("python:slot", "tp_str", functype="reprfunc") __str__;
    std::string __str__() {
        std::ostringstream ss;
        ss << *($self);
        return ss.str();
    }
%enddef

%extend nautical::math::Vector2 {
    nautical_accessors
    %rename(zero)    ZERO;
    %rename(one)     ONE;
    %rename(right)   RIGHT;
    %rename(up)      UP;
}
%extend nautical::math::Vector3 {
    nautical_accessors
    %rename(zero)    ZERO;
    %rename(one)     ONE;
    %rename(right)   RIGHT;
    %rename(up)      UP;
    %rename(forward) FORWARD;
}
%extend nautical::math::Vector4 {
    nautical_accessors
    %rename(zero)    ZERO;
    %rename(one)     ONE;
    %rename(right)   RIGHT;
    %rename(up)      UP;
    %rename(forward) FORWARD;
    %rename(ana)     ANA;
}

%include "../vector2.i"
%include "../vector3.i"
%include "../vector4.i"

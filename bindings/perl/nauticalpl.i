// vim: ft=swig
%module nauticalpl
%extend nautical::math::Vector2 {
    %ignore operator =;
    %ignore operator [];
    %ignore operator T*;
    %ignore operator *=;
    %ignore operator /=;
}
%include "../vector2.i"

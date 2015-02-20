// vim: ft=swig
%module nauticalpy
%feature("autodoc", "2");
%extend nautical::math::Vector2 {
    %ignore operator =;
    %ignore operator T*;
    %ignore operator [];
    T& __setitem__(int i, const T& val) {
        return ((*$self)[i] = val);
    }
    T __getitem__(int i) {
        return (*$self)[i];
    }
}
%extend nautical::math::Vector3 {
    %ignore operator =;
    %ignore operator T*;
    %ignore operator [];
    T& __setitem__(int i, const T& val) {
        return ((*$self)[i] = val);
    }
    T __getitem__(int i) {
        return (*$self)[i];
    }
}
%extend nautical::math::Vector4 {
    %ignore operator =;
    %ignore operator T*;
    %ignore operator [];
    T& __setitem__(int i, const T& val) {
        return ((*$self)[i] = val);
    }
    T __getitem__(int i) {
        return (*$self)[i];
    }
}
%include "../vector2.i"
%include "../vector3.i"
%include "../vector4.i"

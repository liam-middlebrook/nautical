// vim: ft=swig
%module nauticalua

%define nautical_lang_accessors
    T& __setitem__(int i, const T& val) {
        return ((*$self)[i] = val);
    }
    T __getitem__(int i) const {
        return (*$self)[i];
    }
%enddef

%include "../nautical.i"

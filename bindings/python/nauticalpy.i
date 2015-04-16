// vim: ft=swig
%module(directors="1") nauticalpy
%feature("autodoc", "2");

%define nautical_lang_accessors
    %ignore operator =;
    %ignore operator [];
    T& __setitem__(int i, const T& val) {
        return ((*$self)[i] = val);
    }
    T __getitem__(int i) const {
        return (*$self)[i];
    }
    %feature("python:slot", "tp_str", functype="reprfunc") __str__;
%enddef

%include "../nautical.i"

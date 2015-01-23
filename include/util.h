#ifndef UTILS_H_
#define UTILS_H_

template<typename T>
inline void swap(T& a, T& b)
{
    T c = T(a);
    a = b;
    b = c;
};

#endif

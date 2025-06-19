#ifndef MY_TYPE_TRAITS_H
#define MY_TYPE_TRAITS_H

//类型萃取
// 默认模板：不是指针
template<typename T>
struct my_is_pointer {
    static const int value = 0;
};

// 偏特化模板：是指针
template<typename T>
struct my_is_pointer<T*> {
    static const int value = 1;
};

#endif //MY_TYPE_TRAITS_H

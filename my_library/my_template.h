#ifndef MY_TEMPLATE_H
#define MY_TEMPLATE_H

#include<cstdio>
//函数模板：用于生成函数的模板
//模板函数：函数模板的实例化，例如my_swap<double>(a,b)
template<typename T>
void my_swap(T& a, T& b)
{
    printf("通用模板\n");
    T tmp = a;
    a = b;
    b = tmp;
}

//特化
void my_swap(int& a, int& b);

#endif //MY_TEMPLATE_H

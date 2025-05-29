#include<iostream>
#include "my_template.h"
#include "my_operator.h"
using namespace std;

template<class T>
class my_vector {
public:
    typedef T value_type;
    typedef T* iterator;//迭代器指针
    typedef T& reference;//引用

    my_vector(int len=0) :m_len(len),m_Data(nullptr),start(nullptr),pos(0) {

    }
protected:
    iterator m_Data;//指向数据的指针
    iterator start;//起始地址
    int m_len;//数据长度
    int pos;//当前位置
};
int main() {
    /*
    my_operator测试
    Complex a(1, 2), b(3, 4);
    a += b;
    a.print();
    a *= b;
    a.print();
    */
    /*
    my_template测试
    int a=1, b=2;
    double c=1.1, d=2.2;
    my_swap(a, b);
    my_swap(c, d);
    cout<<a<<" "<<b<<endl;
    cout<<c<<" "<<d<<endl;
    return 0;
    */
}
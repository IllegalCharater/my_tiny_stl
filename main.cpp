#include<iostream>
#include <vector>
#include "my_template.h"
#include "my_operator.h"
using namespace std;

template<class T>
class my_vector {
public:
    typedef T value_type;//类型
    typedef T* iterator;//迭代器指针
    typedef T& reference;//引用

    my_vector(int len=0) :m_Data(nullptr),start(nullptr),m_len(len),pos(0) {
        if (len > 0) {
            //创建数组
            m_Data = new T[len];
            start = m_Data;
        }
    }

    ~my_vector() {
        if (m_Data) {
            delete[] m_Data;
            m_Data = nullptr;
        }
    }

    void push_back(const T& data) {

        if(pos==m_len) {//扩容
            int new_len = m_len * 2;
            T* new_data = new T[new_len];
            for (int i = 0; i < m_len; i++) {
                new_data[i] = m_Data[i];
            }
            delete[] m_Data;
            m_Data = new_data;
            m_len = new_len;
        }
        m_Data[pos++] = data;
    }

    value_type pop_back() {
        return m_Data[--pos];
    }

    int size() {
        return pos;
    }

    int capacity() {
        return m_len;
    }
    iterator begin() {
        return start;
    }

    iterator end() {
        return start + pos;
    }

    reference operator[](int index) {
        if(index<=pos)
            return m_Data[index];
        else {
            printf("越界");
            return 0;
        }
    }
protected:
    iterator m_Data;//指向数据的指针
    iterator start;//起始地址
    int m_len;//数据长度
    int pos;//当前位置
};
int main() {
    my_vector<int> vec(10);
    for (int i = 0; i < vec.capacity(); i++) {
        vec.push_back(i);
    }
    for(my_vector<int>::iterator it=vec.begin(); it!=vec.end();it++) {
        cout<<*it<<" ";
    }
    cout<<endl;
    for(int i:vec) {
        cout<<i<<" ";
    }
    cout<<endl;
    for(int i=0; i<vec.size(); i++) {
        cout<<vec[i]<<" ";
    }
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
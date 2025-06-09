#include<iostream>
#include "my_template.h"
#include "my_operator.h"
#include "my_vector.h"
using namespace std;

class Student {
public:
    Student(int size=0) : size(size), name(nullptr) {
        if(size> 0) {
            name = new char[size];
        }
        cout<<"constructor"<<endl;
    }

    //拷贝构造函数  深拷贝
    Student(const Student& stu) {
        size = stu.size;
        name=new char[size];
        for (int i = 0; i < size; i++) {
            name[i] = stu.name[i];
        }
        cout<<"copy constructor"<<endl;
    }

    //浅拷贝
    //指针悬挂问题
    //移动构造函数
    Student(Student&& stu) {
        size=stu.size;
        name=stu.name;
        stu.name=nullptr;
        cout<<"move constructor"<<endl;
    }

    ~Student() {
        delete[] name;
        cout<<"delete"<<endl;
    }

private:
    int size;
    char* name;
};

Student create_student() {
    return Student(5);
}

int main() {
    vector<Student> school;
    //school.push_back(5);//一次构造一次拷贝
    cout<<"-----------------"<<endl;
    // Student stu(create_student());
    // school.push_back(stu);//一次构造一次拷贝
    cout<<"------------------"<<endl;
    //school.push_back(create_student());//一次构造一次移动
    cout<<"-------------------"<<endl;
    Student stu(5);
    school.push_back(std::move(stu));//移动语义
    /*my_vector测试
    my_vector<int> vec(10);
    for (int i = 0; i < vec.capacity(); i++) {
        vec.push_back(i);
    }
    vec.push_back(10);
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
    cout<<endl;
    cout<<vec.size()<<endl;
    cout<<vec.capacity()<<endl;
    cout<<vec[vec.size()]<<endl;
    cout<<vec;
    */
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
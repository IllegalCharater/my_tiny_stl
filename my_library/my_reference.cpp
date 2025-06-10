//
// Created by 任安佳 on 25-6-10.
//

#include "my_reference.h"
#include <iostream>
using  namespace std;

    Student::Student(int size) : size(size), name(nullptr) {
        if(size> 0) {
            name = new char[size];
        }
        cout<<"constructor"<<endl;
    }

    //拷贝构造函数  深拷贝
    Student::Student(const Student& stu) {
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
    Student::Student(Student&& stu) {
        size=stu.size;
        name=stu.name;
        stu.name=nullptr;
        cout<<"move constructor"<<endl;
    }

    Student::~Student() {
        delete[] name;
        cout<<"delete"<<endl;
    }



Student create_student() {
    return Student(5);
}
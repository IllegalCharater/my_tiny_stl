//
// Created by 任安佳 on 25-6-10.
//

#ifndef MY_REFERENCE_H
#define MY_REFERENCE_H

class Student {
public:
    Student(int size=0);

    //拷贝构造函数  深拷贝
    Student(const Student& stu);

    //浅拷贝
    //指针悬挂问题
    //移动构造函数
    Student(Student&& stu) ;

    ~Student() ;

private:
    int size;
    char* name;
};

Student create_student() ;

#endif //MY_REFERENCE_H

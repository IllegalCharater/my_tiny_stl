#include<iostream>
#include "my_template.h"
#include "my_operator.h"
#include "my_vector.h"
#include "my_reference.h"
#include "my_list.h"
#include "my_type_traits.h"
using namespace std;

int main() {
    //my_type_traits测试
    cout<<"int:"<<my_is_pointer<int>::value<<endl;
    cout<<"int*:"<<my_is_pointer<int*>::value<<endl;
    /*
    my_list测试
    int  a[5]={1,2,3,4,5};
    printVec(a,a+5);
    my_list<int>  list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    printContiner(list.begin(),list.end());
    list.pop_back();
    printContiner(list.begin(),list.end());
    /*
    my_reference测试
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
    */
    /*
    my_vector测试
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
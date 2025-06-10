#include<iostream>
#include "my_template.h"
#include "my_operator.h"
#include "my_vector.h"
#include "my_reference.h"
using namespace std;

//简单的list
template<typename T>
//节点
struct list_node {
    list_node<T>* prev;
    list_node<T>* next;
    T data;
};
//list
template<typename T>
struct my_list {
    typedef  list_node<T>* iterator;
    my_list() {
        node==new list_node<T>;
        node->next=node;
        node->prev=node;
    }
    iterator begin() {
        return node->next;
    }
    iterator end() {
        return node;
    }

    void insert(iterator pos,const T& value) {
        iterator tmp=new list_node<T>;
        tmp->data=value;
        tmp->next=pos->next;
        tmp->prev=pos;
        pos->next->prev=tmp;
        pos->next=tmp;
    }

    void erase(iterator pos) {
        pos->next->prev=pos->prev;
        pos->prev->next=pos->next;
        delete pos;
    }

    void push_back(const T& value) {
        insert(node,value);
    }

    iterator pop_back() {
        iterator tmp=node->prev;
        erase(node->prev);
        return tmp;
    }
private:
    iterator node;//链表的结尾
};

template<typename T>
void  printVec(T begin,T end) {
    while(begin!=end) {
        cout<<*begin<<" ";
        begin++;
    }
}

template<typename T>
void  printList(list_node<T>* begin,list_node<T>* end) {
    while(begin!=end) {
        cout<<begin->data<<" ";
        begin=begin->next;
    }
}

int main() {
    //int  a[5]={1,2,3,4,5};
    //printVec(a,a+5);
    my_list<int>  list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    printList(list.begin(),list.end());
    /*my_reference测试
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
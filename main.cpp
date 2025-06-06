#include<iostream>
#include <vector>
#include "my_template.h"
#include "my_operator.h"
#include "my_vector.h"
using namespace std;

int main() {
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
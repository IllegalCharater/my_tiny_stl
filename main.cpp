#include<iostream>
#include "my_template.h"
#include "my_operator.h"

using namespace std;



int main() {

    Complex a(1, 2), b(3, 4);
    a += b;
    a.print();
    a *= b;
    a.print();
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
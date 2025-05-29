#ifndef MY_OPERATOR_H
#define MY_OPERATOR_H

class Complex {
    double real;
    double image;
public:
    Complex():real(0), image(0) {}
    Complex(double r, double i):real(r), image(i) {}

    Complex operator+(const Complex& c) const ;
    Complex operator-(const Complex& c) const ;
    Complex operator*(const Complex& c) const;

    Complex& operator+=(const Complex& c) ;
    Complex& operator-=(const Complex& c) ;
    Complex& operator*=(const Complex& c) ;

    void  print() const;
};


#endif //MY_OPERATOR_H

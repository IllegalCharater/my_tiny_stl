#include "my_operator.h"
#include <cstdio>
    Complex Complex::operator+(const Complex& c) const {
        return Complex(this->real + c.real, this->image + c.image);
    }
    Complex Complex::operator-(const Complex& c) const {
        return Complex(this->real - c.real, this->image - c.image);
    }
    Complex Complex::operator*(const Complex& c) const {
        return Complex(this->real * c.real - this->image * c.image, this->real * c.image + this->image * c.real);
    }

    Complex& Complex::operator+=(const Complex& c) {
        this->real += c.real;
        this->image += c.image;
        return *this;
    }
    Complex& Complex::operator-=(const Complex& c) {
        this->real -= c.real;
        this->image -= c.image;
        return *this;
    }
    Complex& Complex::operator*=(const Complex& c) {
        double tmp_real = this->real * c.real - this->image * c.image;
        double tmp_image = this->real * c.image + this->image * c.real;
        this->real = tmp_real;
        this->image = tmp_image;
        return *this;
    }
    void Complex::print() const {
        printf("(%f, %f)\n", this->real, this->image);
    }
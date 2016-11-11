///////////////////////////////////////////////////////////////////////////////
//                   ALL STUDENTS COMPLETE THESE SECTIONS
// Title:            p4
// Files:            main.cpp
// Semester:         368-3 Spring 2016
//
// Author:          Chenyuan
// Email:            czhang356@wisc.edu
// CS Login:         chenyuan
// Lecturer's Name:  Deb

#include "ComplexNumber.hpp"
#include <iostream>
// constructors
ComplexNumber:: ComplexNumber(){
    real = 0;
    imag = 0;
}

ComplexNumber:: ComplexNumber(double real_part, double imaginary_part){
    real = real_part;
    imag = imaginary_part;
}

ComplexNumber:: ComplexNumber(const ComplexNumber & rhs){
    real = rhs.real;
    imag = rhs.imag;
}

// named member functions
void ComplexNumber:: print(ostream & out ) const{
    if (imag > 0) {
        out << real << " + " << imag << "i";
        return;
    }
    else{
        out << real << " - " << imag * -1 << "i";
    }
}

bool ComplexNumber:: equals(const ComplexNumber & rhs) const{
    if(real == rhs.real && imag == rhs.imag)
        return true;
    return false;
}

// assignment operators
const  ComplexNumber & ComplexNumber:: operator=(const ComplexNumber & rhs){
   // self-assignment check
    if(*this == rhs)
        return *this;
    
    real = rhs.real;
    imag = rhs.imag;
    return *this;
}
const ComplexNumber & ComplexNumber:: operator+=(const ComplexNumber & rhs){
    real = real + rhs.real;
    imag = imag + rhs.imag;
    return *this;
}
const ComplexNumber & ComplexNumber:: operator-=(const ComplexNumber & rhs){
    real = real - rhs.real;
    imag = imag - rhs.imag;
    return *this;
}
const ComplexNumber & ComplexNumber:: operator*=(const ComplexNumber & rhs){
//    cout << "real is " << real << "\n";
//    cout << "rhs.image is " << rhs.imag << endl;
//    cout << "img is " << imag << endl;
//    cout << "rhs.real is " << rhs.real << endl;
    double curr =real;
    real = real * rhs.real - imag * rhs.imag;
    imag = curr * rhs.imag + imag * rhs.real;
        return *this;
}

// arithmetic operators
ComplexNumber operator+(const ComplexNumber & lhs, const ComplexNumber & rhs){
    ComplexNumber complexNumber;
    
    complexNumber = lhs;
    complexNumber += rhs;
    
    return complexNumber;
    
}
ComplexNumber operator-(const ComplexNumber & lhs, const ComplexNumber & rhs){
    ComplexNumber complexNumber;
    
    complexNumber = lhs;
    complexNumber -= rhs;
    
    return complexNumber;
    
}
ComplexNumber operator*(const ComplexNumber & lhs, const ComplexNumber & rhs){
    ComplexNumber complexNumber;
    
    complexNumber = lhs;
    complexNumber *= rhs;
    
    return complexNumber;
}

// relational operators
bool operator==(const ComplexNumber & lhs, const ComplexNumber & rhs){
    if(lhs.equals(rhs))
        return true;
        
    return false;
}
bool operator!=(const ComplexNumber & lhs, const ComplexNumber & rhs){
    if(lhs.equals(rhs))
        return false;
    
    return true;
}

// I/O operators
ostream & operator<<(ostream & out, const ComplexNumber & n){
    
    n.print(out);
    return out;
}
istream & operator>>(istream & in, ComplexNumber & n){
    double real = 0;
    double imaginary = 0;
    string buffer = "";
    char sign = ' ';
    
    in >> real;
    in >> sign;
    in >> buffer;
    // get rid of the i and get the imaginary digit
    buffer.pop_back();
    imaginary = atof(buffer.c_str());
    
    if (sign == '-') {
        imaginary = imaginary * -1;
    }
    
    ComplexNumber complexnumber = ComplexNumber(real, imaginary);
    n = complexnumber;
    
    return in;
    
}


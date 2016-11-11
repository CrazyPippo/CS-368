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


#include <iostream>
#include "ComplexNumber.cpp"
using namespace std;

int main(int argc, const char * argv[]) {
    
    ComplexNumber complexNumber1;
    ComplexNumber complexNumber2;
    
    // initialize two complex numbers
    cout << "Enter a complex number C1: " << "\n";
    cin >> complexNumber1;
    cout << "Enter a complex number C2: " << "\n";
    cin >> complexNumber2;
    
    // arithematic operations on two complex numbers
    cout << "For C1 = " << complexNumber1 << " and C2 = " << complexNumber2 << " : " << "\n";
    cout << "C1 + C2 = " << complexNumber1 + complexNumber2 << "\n";
    cout << "C1 - C2 = " << complexNumber1 - complexNumber2 << "\n";
    cout << "C1 * C2 = " << complexNumber1 * complexNumber2 << "\n";
    cout << "C1 == C2 is " << (complexNumber1 == complexNumber2? "true":"false") << "\n";
    cout << "C1 != C2 is " << (complexNumber1 == complexNumber2? "false":"true") << "\n";
    cout << "After C1 += C2, C1 = " << complexNumber1.operator+=(complexNumber2) << "\n";
    complexNumber1 -= complexNumber2; // reset
    cout << "After C1 -= C2, C1 = " << complexNumber1.operator-=(complexNumber2) << "\n";
    complexNumber1 += complexNumber2; // reset
    cout << "After C1 *= C2, C1 = " << complexNumber1.operator*=(complexNumber2) << "\n";
    
    
    
    return 0;
}

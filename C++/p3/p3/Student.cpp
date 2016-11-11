//
//  Student.cpp
//  P3
//
//  Created by Pippo on 4/4/16.
//  Copyright © 2016 Pippo. All rights reserved.
//

#include <stdio.h>
#include "Student.h"
#include <iostream>
// constuctors
Student:: Student (){
    studentID = 0;
    credits = 0;
    GPA = 0;
}

Student:: Student(int id){
    studentID = id;
    credits = 0;
    GPA = 0;
}

Student:: Student(int id, int cr, double gpa){
    studentID = id;
    credits = cr;
    GPA = gpa;
}

// copy constructor
Student:: Student (const Student& s){
    studentID = s.studentID;
    credits = s.credits;
    GPA = s.GPA;
}

// destructor
Student:: ~Student(){
    printf("Student deleted\n");
}

// assignment
 Student& Student:: operator=(const Student& rhs){
     studentID = rhs.studentID;
     credits = rhs.credits;
     GPA = rhs.GPA;
    return *this;
}

// Accessors
int Student:: getID() const{
    return studentID;
}

int Student:: getCredits() const{
    return credits;
}

double Student:: getGPA() const{
    return GPA;
}

// other methods

void Student:: update(char grade, int cr){
    // convert grade to number
    double numberGrade = 0;
    if ( grade == 'A')
        numberGrade = 4.0;
    else if ( grade == 'B')
        numberGrade = 3.0;
    else if ( grade == 'C')
        numberGrade = 2.0;
    else if ( grade == 'D')
        numberGrade = 1.0;
    else if ( grade == 'F')
        numberGrade = 0;

    
    // update GPA and credits
    GPA = (GPA * credits + numberGrade * cr) / (credits + cr);
    credits = credits + cr;
}

void Student:: print() const{
    std::cout << studentID << ", " << credits << ", " << GPA;
}
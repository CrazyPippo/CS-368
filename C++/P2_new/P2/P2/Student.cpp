//
//  Student.cpp
//  P2
//
//  Created by Pippo on 2/26/16.
//  Copyright © 2016 Pippo. All rights reserved.
//
#include "Student.h"
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

// constructor
Student:: Student (int id, int nCourses){
    studentID = id;
    nCourses = nCourses;
}

float Student:: getGPA(){
    
    int totalCredits = 0;
    double totalGrades = 0;
    // loop the courses
    for (int i = 0; i < Courses.size(); i++) {
        double grade = 0;
        transform(Courses.at(i).grade.begin(), Courses.at(i).grade.end(), Courses.at(i).grade.begin(),::toupper); // convert grade to upper case
        
        //get the double GPA according to string grade
        if ( Courses.at(i).grade == "A")
            grade = 4.0;
        else if (Courses.at(i).grade == "AB")
            grade = 3.5;
        else if ( Courses.at(i).grade == "B")
            grade = 3.0;
        else if ( Courses.at(i).grade == "BC")
            grade = 2.5;
        else if ( Courses.at(i).grade == "C")
            grade = 2.0;
        else if ( Courses.at(i).grade == "D")
            grade = 1.0;
        else if ( Courses.at(i).grade == "F")
            grade = 0;
        
        totalGrades = totalGrades + grade *   Courses.at(i).credits;
        totalCredits = totalCredits +   Courses.at(i).credits;
    }
    
    return totalGrades / totalCredits;
}

int Student:: getNumCourses(){
    return nCourses;
}

void Student:: addStudentCourseInfo(int courseNumber, int credits, char* grade ){
    Coursetype newCourse;
    newCourse.courseNum = courseNumber;
    newCourse.credits = credits;
    newCourse.grade = grade;
    Courses.push_back(newCourse);
}

bool Student:: tookCourse(int courseNumber){
    for(int i = 0; i < Courses.size(); i++){
        if (Courses.at(i).courseNum == courseNumber)
            return true;
    }
    
    return false;
}

int Student:: getId(void){
    return   studentID;
}




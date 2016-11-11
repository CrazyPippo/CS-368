//                   ALL STUDENTS COMPLETE THESE SECTIONS
// Title:            (P2)
// Files:            (P2.cpp)
// Semester:         (cs368-C++) Spring 2016
//
// Author:           Chenyuan Zhang
// Email:            czhang356@wisc.edu
// CS Login:         chenyuan
// Lecturer's Name:  DEB

#include <stdio.h>
#include "Database.h"
#include <ctype.h>
#include <iostream>
// constructor
Database:: Database(int Nstudents){
    numStudents =Nstudents;
}

void Database:: addStudent(Student student){
    students.push_back(student);
}

int Database:: getNumStudents(){
    return numStudents;
}

void Database:: dataProcess(char command, int commandValue){
    command = tolower(command);
    
    switch (command) {
        case 'h':
            cout << "You can enter the following valid commands:\nn: Get number of student in the database\nc num: Get number of students who took course 'num'. Also prints student IDs\ng student_ID: Get GPA of student student_ID\np num: Get number of students with GPA>num. Also print student IDs\nq: Quit\n";
            break;
        case 'n':
            cout << this->getNumStudents() <<"\n";
            break;
        case 'c':
        {   bool validCourse = false;
            if(commandValue >= 1000){
            cout << "Invalid Input\n";
            break;
        }
        
            int count = 0;
            vector<int> ids;
            // get the student list
            for (int i = 0; i < students.size(); i++) {
                if (students.at(i).tookCourse(commandValue)){
                    ids.push_back(students.at(i).getId());
                    count++;
                    validCourse = true;
                }
            }
            
            // print number of students and their ids
                 cout << count << "\n";

           
            for(int i = 0; i < ids.size(); i++)
                cout << ids.at(i) << " ";
            if (validCourse) {
                   cout << "\n";
            }
         
            break;
        }
        case 'g':
        {   if(commandValue < 10000){
            cout << "Invalid Input\n";
            break;
        }
            float gpa = 0;
            for(int i = 0; i < students.size(); i++){
                if(students.at(i).getId() == commandValue)
                    gpa = students.at(i).getGPA();
            }
            cout << gpa << "\n";
            break;}
        case 'p':
        {   if(commandValue < 0 || commandValue > 4){
            cout << "Invalid Input\n";
            break;
        }
            vector<int> ids;
            int count = 0;
            for(int i = 0; i < students.size(); i++){
                if(students.at(i).getGPA() > double(commandValue)){
                    ids.push_back(students.at(i).getId());
                    count++;
                }
            }
            cout << count << "\n";
            // display ids
            for(int i = 0; i < ids.size(); i++){
                cout << ids.at(i);
            }
            cout << "\n";
                break;}
        case 'q':
            exit(0);
            
        default:{
            cout << "Invalid Command. Need help?\nYou can enter the following valid commands:\nn: Get number of student in the database\nc num: Get number of students who took course 'num'. Also prints student IDs\ng student_ID: Get GPA of student student_ID\np num: Get number of students with GPA>num. Also print student IDs\nq: Quit\n";
            break;

        }
    }
}


//
//  main.cpp
//  P3
//
//  Created by Pippo on 4/4/16.
//  Copyright © 2016 Pippo. All rights reserved.
//

#include <iostream>
#include <string>
#include "Student.cpp"
#include "SortedList.cpp"
int main(int argc, const char * argv[]) {
    
    // student class test
    Student student1 = Student(540, 3, 4.0); // constructor test
    Student student2 = Student(student1);   // copy constructor test
    Student student3; // assignemnt test
    student3 = student1;
    
    // sortedlist class test
    SortedList list1 = SortedList();
    
    SortedList list2 = SortedList(list1);
}

//
//  main.cpp
//  P2
//
//  Created by Pippo on 2/26/16.
//  Copyright © 2016 Pippo. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Database.h"
#include "Student.h"
using namespace std;


vector<string> splitString(string str){
    vector<string> tokens;
    stringstream ss(str);
    string buf;
    while (ss >> buf) {
        tokens.push_back(buf);
    }
    return tokens;
}

void initialize_database(Database* &database, ifstream &inputFile){
    int counter = 0;
    string str;
    
    Student* student_ptr = nullptr;
    while (getline(inputFile, str)) {
        // initialize database
        if (counter == 0) {
            database = new Database(stoi(str));
            counter++;
            continue;
        }

        // split the string each line in the file
        vector<string> info = splitString(str);
        
        if (info.size() == 1) {
            cout << "Total " << stoi(info[0]) << " scanned\n";
        }
        
        else if (info.size() == 2){ // add student
            Student student(stoi(info[0]), stoi(info[1]));
            
            student_ptr = &student;
        }
        
        else if (info.size() == 0){
            cout << "the file readed is empty\n";
            exit(1);
        }
        
        else{ // initialize the course info
        
            for (int i = 0; i < info.size(); i+=3) {
                int y = i + 1;
                int z = i + 2;
                char* curr = new char (info[z].length() + 1);
                strcpy(curr, info[z].c_str());
                student_ptr -> addStudentCourseInfo(stoi(info[i]), stoi(info[y]), curr);
                delete curr;
            }
            database -> addStudent(*(student_ptr));
    }
        
    }
    
    
}



int main(int argc, const char * argv[]) {
   
    Database* database = nullptr;
    ifstream inputFile;
    
    if (argc != 2) {
        printf("Invalid file\n");
        return 1;
    }
    
    // open the file
    inputFile.open(argv[1]);
    if (!inputFile.is_open()) {
        printf("Invalid file\n");
        return 1;
    }
    
    // process file
    initialize_database(database, inputFile);
    
    // main command loop
    vector<string> command;
    string roughCommand;
    while (1) {
        cout << "<";
        getline(cin, roughCommand);
        command = splitString(roughCommand);
        if(command.size() == 2)
            database -> dataProcess(command[0][0], stoi(command[1]));
        else
            database->dataProcess(command[0][0], 0);
    }
    
    //inputFile.close();
    //delete database;
    
    return 0;
}


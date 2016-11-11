///////////////////////////////////////////////////////////////////////////////
//                   ALL STUDENTS COMPLETE THESE SECTIONS
// Title:            p5
// Files:            findWord.cpp
// Semester:         (CS 368 - C++) Spring 2016
//
// Author:           Chenyuan Zhang
// Email:            czhang356@wisc.edu
// CS Login:         chenyuan
// Lecturer's Name:  Dep

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

vector<string> splitString( const string& str){
    vector<string> tokens;
    stringstream ss(str);
    string buf;
    while (ss >> buf) {
        tokens.push_back(buf);
    }
    return tokens;
}



int main(int argc, char *argv[]) {
    
    ifstream file;
    string line = ""; // each line of the file
    vector<string> matchedLines;
    vector<string> splittedStrings;
    int numberOfLines = 0;
    int counter = 0;
    
    // need to implement the welcome message.......
    
    
    
    
    // open file
   
    file.open(argv[2]);
        // print error message if the file cannot be opened or does not exist
    if (!file.is_open() ||!file.good()) {
        cout << "File cannot be opened or does not exist\nProgram terminated" << endl;
        exit(1);
    }
    
    cout << "Searching for '" << argv[1] << "' in file '" << argv[2] << "'" << endl;
    
    
    // search the text in the file
    while (getline(file,line)) {
        bool firstApperance = true;
        numberOfLines++;
        // split each line
        splittedStrings = splitString(line);
        // check if there is a match
        for (int i = 0; i < splittedStrings.size(); i++) {
            
            if (splittedStrings.at(i).find(argv[1]) != string::npos) {
                if(firstApperance){
                    // add this line to the matched lines if match
                    // increment the counter if match found
                    matchedLines.push_back(to_string(numberOfLines) + " : " + line);
                    counter++;
                    firstApperance = false;
                }
                else{
                    counter++;
                }
            }
        }
    }
    
    // display the result
    
    for (int i = 0; i < matchedLines.size(); i++) {
        cout << matchedLines.at(i) << endl;
    }
    cout << "# occurrences of '" << argv[1] << "'" << " = " << counter << endl;
    
    
    
    
    
    
    
    
    
    
    
    
    
    file.close();
    return 0;
}


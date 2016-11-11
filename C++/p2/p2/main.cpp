//                   ALL STUDENTS COMPLETE THESE SECTIONS
// Title:            (P1)
// Files:            (p1.cpp)
// Semester:         (cs368-C++) Spring 2016
//
// Author:           Chenyuan Zhang
// Email:            czhang356@wisc.edu
// CS Login:         chenyuan
// Lecturer's Name:  DEB

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include "main.h"
using namespace std; // like import in Java



int main(int argc, const char * argv[]) {
   // variables
    unsigned const MAX_SIZE = 100;
    double myArray[MAX_SIZE];
    
    cout << "Welcome!\n";
    
    run(myArray, MAX_SIZE);
    
    return 0;
}
/*
 display main menu
*/
void mainMenu(){
    cout << "1) Feed array input\n" << "2) Determine the minimum element in the array\n" << "3) Determine the maximum element in the array\n" << "4) Sort the array of integers\n" << "5) Determine the average of the elements in the array\n" << "6) Randomly generate aray elements within a specific range\n" << "7) Print the elements of the array\n" << "8) Exit program\n";
}
/*
 read user input for operation number
*/

unsigned int prompt(){
    int choice = 0;
    
    cout <<"Enter your choice: \n";
    cin >> choice;
    if(choice < 1 || choice > 8){
        cout << "Invalid input, please try again\n";
        choice = prompt();
    }
    return choice;
}

/*
 craete the array of max size and assgign values to each element from user input
*/
unsigned int feedArray(double myArray[], int MAX_SIZE){
    int size =  checkSize(MAX_SIZE);
    printf("the size is %d\n", size);
    cout <<"Enter the numbers: ";
    // assign inputs to array elements
    for(int i = 0; i < size; i++)
        cin >> setprecision(3) >> myArray[i];
    return size;
}

/*
 print the minimum value out of the array
*/
void printMin(double myArray[], int size){
    double min = myArray[0];
    for(int i = 1; i < size; i++){
        if( myArray[i] <  min)
            min = myArray[i];
    }
    cout << "Minimum element in array: " << setprecision(3) << min << "\n";
}

/*
 print the maxium value out of the array
*/
void printMax(double myArray[], int size){
    double max = myArray[0];
    //cout << "the min is initialized to " << *arrayPointer << "\n";
    for(int i = 1; i < size; i++){
        if(myArray[i] > max)
            max = myArray[i];
    }
    
   cout << "Maximum element in array: " << max << "\n";
}
 

/*
selections sort the array and display it
*/
void sortAndDisplay(double myArray[], int size){
    //selection sort
    int minIndex;
    double temp;
    
    for(int i = 0; i < size; i++){
        // find the smallest one
        minIndex = i;
        
        for(int m = i + 1; m < size; m++){
            if(myArray[m] < myArray[minIndex])
                minIndex = m;
        }
        // swap
        temp = myArray[i];
        myArray[i] = myArray[minIndex];
        myArray[minIndex] = temp;
    }
    displayElements(myArray, size);
}
/*
 compute the average value out of the array
*/
void computeAverage(double myArray[], int size){
    double average = 0;
    double sum = 0;
    
    for(int i = 0; i < size; i++)
        sum = myArray[i] + sum;
    average = sum / size;
    printf("The average of the elements is: %.3f\n", average);
}
/*
 generate random values in a range and put them in the array
*/

int generateRandomElements(double myArray[], int MAX_SIZE){
    int seed = 1000;
    srand(seed);
    int lowerBound = 0;
    int upperBound = 0;
    int size = checkSize(MAX_SIZE);
    
    // check range
    bool validRange = false;
    while(!validRange){
        cout<< "Emter the lower range for elements: ";
        cin >> lowerBound;
        cout<< "Emter the upper range for elements: ";
        cin >> upperBound;
        
        if(lowerBound > upperBound)
            cout << "Lower bound is bigger than upper bound!";
        else    validRange = true;
    }
    
    // generate numbers wuthin the range and assign each to the array
    for(int i = 0; i < size; i++){
        myArray[i] = lowerBound + ((double)rand() / RAND_MAX) * (upperBound - lowerBound + 1);
    }
    
    return size;
}

void displayElements(double myArray[], int size){
    cout << "The elements of the array are: ";
    for(int i = 0; i < size; i++)
        cout << setprecision(3) <<myArray[i] << " ";
    cout << "\n";
}

/*
 check whether the the array size is bigger than 1000
*/
unsigned int checkSize(int MAX_SIZE){
    int size = 0;
    bool validSize = false;
    while(!validSize){
        cout <<"Enter the number of elements in the array: ";
        cin >> size;
        
        if(size > MAX_SIZE || size <= 0)
            cout<< "Invalid size\n";
        else    validSize = true;
    }
    return size;
}

void clearArray(double myArray[], int size){
    for(int i = 0; i < size; i++)
        myArray[i] = 0;
}

/*
 core function: do operations according to user input
*/
void run(double myArray[], int MAX_SIZE){
    int size = 0;
    bool arrayCreated = false;
    int choice = 0;
    while(1){
        mainMenu();
        choice = prompt();
        switch (choice) {
            case 1:
                size = feedArray(myArray, MAX_SIZE);
                arrayCreated = true;
                break;
            case 2:
                if(!arrayCreated)
                    printf("array has not been created yet!\n");
                else
                    printMin(myArray, size);
                break;
            case 3:
                if(!arrayCreated)
                    printf("array has not been created yet!\n");
                else
                    printMax(myArray, size);
                break;
            case 4:
                if(!arrayCreated)
                    printf("array has not been created yet!\n");
                else
                    sortAndDisplay(myArray, size);
                break;
            case 5:
                if(!arrayCreated)
                    printf("array has not been created yet!\n");
                else
                    computeAverage(myArray, size);
                break;
            case 6:
                // clear the array before assigning new values
                clearArray(myArray, size);
                size = generateRandomElements(myArray, MAX_SIZE);
                displayElements(myArray, size);
                arrayCreated = true;
                break;
            case 7:
                if(!arrayCreated)
                    printf("array has not been created yet!\n");
                else
                    displayElements(myArray, size);
                break;
            case 8:
                cout<< "Exiting the program!\nThank you!\n";
                exit(0);
                
                break;
                
        }
    }
}



//
//  main.h
//  p2
//
//  Created by Pippo on 2/15/16.
//  Copyright © 2016 Pippo. All rights reserved.
//

#ifndef main_h
#define main_h
void mainMenu();
unsigned int prompt();
unsigned int feedArray(double myArray[], int MAX_SIZE);
void printMin(double myArray[], int size);
void printMax(double myArray[], int size);
void sortAndDisplay(double myArray[], int size);
void computeAverage(double myArray[], int size);
int generateRandomElements(double myArray[], int MAX_SIZE);
void displayElements(double myArray[], int size);
void run(double myArray[], int MAX_SIZE);
unsigned int checkSize(int MAX_SIZE);
void clearArray(double myArray[], int size);

#endif /* main_h */

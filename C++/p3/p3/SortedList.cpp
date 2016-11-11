//
//  SortedList.cpp
//  P3
//
//  Created by Pippo on 4/4/16.
//  Copyright © 2016 Pippo. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "SortedList.h"
typedef  struct Listnode Listnode;
void SortedList:: freeList(Listnode* head){
    

}

SortedList:: Listnode* SortedList:: copyList(Listnode* S){
    Listnode* head = new Listnode;
    
    // copy data to the new head
    Listnode* curr1 = head;
    Listnode* curr2 = S;
    while (curr2->next != NULL) {
        // copy the "student" property
        Student st = Student(*(curr2-> student));
        curr1-> student = &st;
        // allocate memory for next
        curr1-> next = new Listnode;
        
        // update counter
        curr1 = curr1-> next;
        curr2 = curr2-> next;
    }
    
    // update last node
    Student std = Student(*(curr2-> student));
    curr1-> student = &std;
    
    return head;
}

// constructor
SortedList:: SortedList(){
    head = new Listnode;
    head ->student = NULL;
    head ->next = NULL;
}

// cppy constructor
SortedList:: SortedList (const SortedList& S){
    head = copyList(S.head);
    
}

// assignment
SortedList& SortedList:: operator=(const SortedList& S){
    
    // self-assignment check
    if(this == &S)
        return *this;
    // deallocate any previous memory
    freeList(head);
    // copy list
    head = copyList(S.head);
    return *this;
}

// destructor

SortedList:: ~SortedList(){
    freeList(head);
    printf("destructor called\n");
}


// methods

bool SortedList:: insert(Student* s){
    
    // argument check
    if (s == NULL) {
        printf("The student pointer is null");
        return false;
    }
    
    // case: head is empty
    
    if (head == NULL){
        head = new Listnode;
        // deep copy student
        head-> student = s;
        return true;
    }
    
    // head is not empty
    else{
        
        // initialize the insert node
        Listnode* insertNode = new Listnode;
        insertNode-> student = s;
        
        // case: insert at head
        if(s-> getID() < head-> student-> getID()){
            
            insertNode-> next = head;
            // update head
            head = insertNode;
            
            return true;
        }
        
        // general case
       
        Listnode* previousNode = head;
        Listnode* curr = head;
        // find the previous node and afternode
        while(s-> getID() > curr-> student-> getID() && curr != NULL){
            
            previousNode = curr;
            curr = curr-> next;
        }
        // insert
        previousNode-> next = insertNode;
        insertNode-> next = curr;
        
        return true;
    }
}

Student* SortedList:: find(int studentID){
    Listnode* curr = head;
    while (curr != NULL) {
        if(curr-> student-> getID() == studentID)
            return curr->student;
    }
    return NULL;
}

Student* SortedList:: remove(int studentID){

    Listnode* curr = head;
    Listnode* previousNode = NULL;
    Student* std_ptr = NULL;
    
    while (curr != NULL) {
        
        if(curr-> student-> getID() == studentID){
            // case1: remove head
            if(curr == head){
                std_ptr = curr->student;
                head = curr->next;
                delete curr; // delete the node and free memory
                return std_ptr;
            }
            
            // case2: remove tail
            if(curr-> next == NULL){
                std_ptr = curr-> student;
                delete curr;
                return std_ptr;
            }
            
            // case 3: remove middle node
            previousNode-> next = curr-> next;
            std_ptr = curr-> student;
            delete curr;
            return std_ptr;
            
            
            
        }
        previousNode = curr;
        curr = curr-> next;
    }
    return NULL;
}


void SortedList:: print() const{
    Listnode* curr = head;
    while (curr != NULL) {
        curr-> student-> print();
    }
}



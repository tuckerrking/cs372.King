//
// File:   assignment1.cpp
// Author: Tucker King
// Purpose:
// Illustrate some of the bad thins that can happen with
// pointers
//
//
//  main.cpp
//  Assignment_1
//
//  Created by Tucker King on 8/23/21.
//

/* This program uses three main functions and one helper function to perform the following operations:
        - Function 1: Allocate a large array of integers in the heap, storing a pointer to that data. It then initializes a second pointer to the same location in memory. Then it performs an array delete of the first pointer, and prints the first ten integers pointed to by the second pointer.
        
        - Function 2: Similarly to function 1, allocates a large array of integers in the heap and sets two pointers to the location of that array. It then performs a regular delete on the first pointer, and prints the address of the second pointer and the first ten elements of the array that pointer is referencing.
 
        - Helper function: This function defines a pointer to a C++ string object and then uses a new to create a new string on the stack. In the return for this function, the dereference operator is used to return the string just allocated on the heap.
 
        - Function 3: Defines a string object, set to be whatever is returned from the helper function and prints that string.
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

void problem_1() {
    int *pointer_1;
    pointer_1 = new int[1000];
    
    for(int i = 0; i < 1000; i++) {
        pointer_1[i] = i;
    }
    
    int *pointer_2;
    pointer_2 = pointer_1;
    
    delete []pointer_1;
    
    for(int j = 0; j < 10; j++) {
        cout << pointer_2[j] << " ";
    }
    cout << endl;
    
    //delete []pointer_2;
}

void problem_2() {
    int *pointer_1;
    pointer_1 = new int[1000];
    
    for(int i = 0; i < 1000; i++) {
        pointer_1[i] = i;
    }
    
    int *pointer_2;
    pointer_2 = pointer_1;
    
    delete pointer_1;
    
    cout << pointer_2 << endl;
    for(int j = 0; j < 10; j++) {
        cout << pointer_2[j] << " ";
    }
    cout << endl;
    
    //delete pointer_2;
}

string problem_3() {
    string *str_pointer;
    str_pointer = new string[100];
    
    for(int i = 0; i < 100; i++) {
        str_pointer[i] = 'a';
    }
    
    return *str_pointer;
}

void problem_3_helper(string pointer) {
    for(int i = 0; i < 100; i++) {
        cout << pointer[i];
    }
    cout << endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    problem_1();
    
    problem_2();
    
    problem_3_helper(problem_3());
    
    return 0;
}

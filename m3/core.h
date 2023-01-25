/*
*****************************************************************************
                        Assignment 1 - Milestone 3
Full Name  : Kuldeepsinh Sandipsinh Mahida
Student ID#: 167547215
Email      : kmahida@myseneca.ca
Section    : NGG
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

// SAFE-GUARD: 
// It is good practice to apply safe-guards to header files
// Safe-guard's ensures only 1 copy of the header file is used in the project build
// The macro name should be mirroring the file name with _ for spaces, dots, etc.

// !!! DO NOT DELETE THE BELOW 2 LINES !!!
#ifndef CORE_H
#define CORE_H

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// 
// Copy your work done from Milestone #2 (core.h) into this file
// 
// NOTE:
// - Organize your functions into the below categories
// - Make sure the core.c file also lists these functions in the same order!
// - Be sure to provide a BRIEF comment for each function prototype
// - The comment should also be copied to the core.c function definition
//
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


//////////////////////////////////////
// USER INTERFACE FUNCTIONS
//////////////////////////////////////

// Clear the standard input buffer
void clearInputBuffer(void);

// Wait for user to input the "enter" key to continue
void suspend(void);


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// FUNCTION PROTOTYPES
// Clear the standard input buffer
void clearInputBuffer(void);
// Wait for user to input the "enter" key to continue
void suspend(void);


//  1-> take integer as input and return it
int inputInt();
//  2-> function to accept a positive integer from user
int inputIntPositive();
//  3-> function to accept a range and return value
int inputIntRange(int, int);
//  4-> function to accept character array and return character
char inputCharOption(const char[]);
//  5-> functons with three inputs and no return type.
void inputCString(char*, int, int);
//  6-> function to take character string input and print it. 
void displayFormattedPhone(const char*);



// !!! DO NOT DELETE THE BELOW LINE !!!
#endif // !CORE_H
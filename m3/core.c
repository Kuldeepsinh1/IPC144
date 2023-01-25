/******************************************************************************
                        Assignment 1 - Milestone 3
Full Name  : Kuldeepsinh Sandipsinh Mahida
Student ID#: 167547215
Email      : kmahida1@myseneca.ca
Section    : NGG

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "core.h"


// Clear the standard input buffer
void clearInputBuffer(void)
{
    while (getchar() != '\n')
    {
        ;
    }
}
// Wait for the user to input the "enter" key to continue
void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}
// Get a valid integer from keyboard
int inputInt(void)
{
    char newline = 'x';
    int  value;
    while (newline != '\n')
    {
        // read an integer value as user input
        scanf("%d%c", &value, &newline);
        // if newline is found break out of the loop
        if (newline == '\n')
        {
            break;
        }
        // if newline is not found, clear the buffer
        // and display the error message
        else
        {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }

    }
    // return the valid integer inputted by the user
    return value;
}
// Get a valid integer from keyboard and validate if greater than 0
int inputIntPositive(void)
{
    // read an integer value as user input
    int value = inputInt();
    // if value is less than or equal to 0
    // display the error message and get another input from user
    while (value <= 0)
    {
        printf("Error! Value must be > 0: ");
        value = inputInt();
    }
    // return the valid integer inputted by the user
    return value;
}
// Get a valid integer from keyboard and validate if within a range of values
int inputIntRange(int lower_limit, int upper_limit)
{
    int value = inputInt();
    // if value is not within the range of values
    // display the error message and get another input from user
    while (value < lower_limit || value > upper_limit)
    {
        printf("ERROR! Value must be between %d and %d inclusive: ", lower_limit, upper_limit);
        value = inputInt();
    }
    // return the valid integer inputted by the user
    return value;
}
// Get a single character from keyboard and validate if it matches any character in a given string
char inputCharOption(const char matchstring[]) {
    int flag = 0, i;
    char char_value = '0';
    char char_value1 = '0';
    int loop = 1;
    for (i = 0; matchstring[i] != '\0'; i++)
    {
        flag++;
    }
    while (loop)
    {
        scanf("%c%c", &char_value, &char_value1);

        if (char_value1 == '\n')
        {
            for (i = 0; i < flag && loop; i++)
            {
                if (char_value == matchstring[i])
                {
                    loop = 0;
                }
            }
            if (loop)
            {

                printf("ERROR: Character must be one of [%s]: ",
                    matchstring);
            }
        }
        else
        {
            clearInputBuffer();
            printf("ERROR: Character must be one of [%s]: ",
                matchstring);
        }
    }
    return char_value;
}
// Get a C string from keyboard and validate if its length is within a given range
void inputCString(char* inputString, int minLen, int maxLen)
{
    char tempString[100];
    while (1)
    {
        // clear the input buffer
        // clearInputBuffer();
        // get a string as user input (spaces are allowed)
        scanf(" %[^\n]%*c", tempString);
        if (minLen == maxLen)
        {
            // Display error message
            if (strlen(tempString) != minLen)
            {
                printf("Invalid %d-digit number! Number: ", minLen);
            }
            // user input is valid so break out of the loop
            else
            {
                break;
            }
        }
        else
        {
            // Display error message
            if (strlen(tempString) > maxLen)
            {
                printf("ERROR: String length must be no more than %d chars: ", maxLen);
            }
            // Display error message
            else if (strlen(tempString) < minLen)
            {
                printf("Error! String length must be between %d and %d chars: ", minLen, maxLen);
            }
            // user input is valid so break out of the loop
            else
            {
                break;
            }
        }
    }
    // copy the temp string to the input string
    strcpy(inputString, tempString);
}
// Display an array of 10 character digits as a formatted phone number
void displayFormattedPhone(const char* phone_number)
{
    // if phone_number is NULL, display the required string and exit the function
    if (phone_number == NULL)
    {
        printf("(___)___-____");
        return;
    }
    int i = 0;
    int count = 0;
    int len = strlen(phone_number);
    for (i = 0; i < len; i++)
    {
        if (phone_number[i] >= '0' && phone_number[i] <= '9')
        {
            count++;

        }
    }
    // if phone_number length is not equal to 10 or has non-digit characters,
    // display the required string and exit the function
    if (len != 10 || len != count)
    {
        printf("(___)___-____");
    }
    // display the formatted phone number
    else
    {
        printf("(%c%c%c)%c%c%c-%c%c%c%c",
            phone_number[0],
            phone_number[1],
            phone_number[2],
            phone_number[3],
            phone_number[4],
            phone_number[5],
            phone_number[6],
            phone_number[7],
            phone_number[8],
            phone_number[9]);
    }
}
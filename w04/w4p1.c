/*
*****************************************************************************
                          Workshop - #4 (P1)
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

int main(void)
{
    int iteration,i;
    char looptype;
    printf("+----------------------+");
    printf("\nLoop application STARTED");
    printf("\n+----------------------+");
    // we use do while loop here so that it runs atleast 1 time 
    do
    {
        printf("\n\nD = do/while | W = while | F = for | Q = quit");
        printf("\nEnter loop type and the number of times to iterate (Quit=Q0): ");
        scanf(" %c%d",&looptype,&iteration);
        if (looptype != 'D' && looptype != 'W' && looptype != 'F' && looptype != 'Q')
        {
            printf("ERROR: Invalid entered value(s)!");
        }
        // do while
        if (looptype == 'D')
        {
            if (iteration >= 3 && iteration <= 20)
            {
                printf("DO-WHILE: ");
                do
                {
                    printf("D");
                    iteration = iteration - 1;
                }
                while (iteration != 0);
            }
            else
            {
                printf("ERROR: The number of iterations must be between 3-20 inclusive!");
            }
        }
        // while
        if (looptype == 'W')
        {
            if (iteration >= 3 && iteration <= 20)
            {
                printf("WHILE   : ");
                while (iteration != 0)
                {
                    printf("W");
                    iteration = iteration - 1;
                }
            }
            else
            {
                printf("ERROR: The number of iterations must be between 3-20 inclusive!");
            }
        }
        // for
        if (looptype == 'F')
        {
            if (iteration >= 3 && iteration <= 20)
            {
                printf("FOR     : ");
                for (i = 1; i <= iteration; i++)
                {
                    printf("F");

                }
            }
            else
            {
                printf("ERROR: The number of iterations must be between 3-20 inclusive!");
            }
        }
        if (looptype == 'Q')
        {
            if (iteration != 0)
            {
                printf("ERROR: To quit, the number of iterations should be 0!");
                looptype = 'k';// if iteration is not 0 then we change looptype to any random value but Q
                // so that main while loop does not exit and that value k would get over written above
                // when we take users input.
            }
            
           
        }

    } 
    while (looptype != 'Q');
    printf("\n+--------------------+");
    printf("\nLoop application ENDED");
    printf("\n+--------------------+\n");
    return 0;
}
/*
*****************************************************************************
                          Workshop - #5 (P2)
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
#define MIN_YEAR 2012 
#define MAX_YEAR 2022
#define LOG_DAYS 3

int main(void)
{
    const int JAN = 1, DEC = 12;
    int month, year;
    int flag = -1;
    int i;
    double morning[LOG_DAYS];
    double evening[LOG_DAYS];
    int mornflag[LOG_DAYS];
    int evenflag[LOG_DAYS];
    double totalmorn=0;
    double totaleven=0;

    printf("General Well-being Log");
    printf("\n======================");
    do
    {
        printf("\nSet the year and month for the well-being log (YYYY MM): ");
        scanf("%d %d", &year, &month);
        if (year < MIN_YEAR || year > MAX_YEAR)// checking if year entered is in requuired range
        {
            printf("   ERROR: The year must be between 2012 and 2022 inclusive");
        }
        if (month < JAN || month > DEC)// checking if month entered is in required range
        {
            if (year < MIN_YEAR || year > MAX_YEAR)// for proper printing indentation
            {
                printf("\n");
            }
            printf("   ERROR: Jan.(1) - Dec.(12)");
        }
        if ((year >= MIN_YEAR && year <= MAX_YEAR) && (month >= JAN && month <= DEC))//if inputs are correct change flag value to break loop.
        {
            flag = 0;
        }
    } while (flag != 0);
    printf("\n*** Log date set! ***\n");// final output printing
    for (i = 0;i < LOG_DAYS;i++)
    {
        printf("\n");
        switch (month)
        {
        case 1:
            if(i<=9)
                printf("%d-JAN-0%d", year,i+1);
            else
                printf("%d-JAN-%d", year, i+1);
            break;
        case 2:
            if (i <= 9)
                printf("%d-FEB-0%d", year, i+1);
            else
                printf("%d-FEB-%d", year, i + 1);
            break;
        case 3:
            if (i <= 9)
                printf("%d-MAR-0%d", year, i + 1);
            else
                printf("%d-MAR-%d", year, i + 1);
            break;
        case 4:
            if (i <= 9)
                printf("%d-APR-0%d", year, i + 1);
            else
                printf("%d-APR-%d", year, i + 1);
            break;
        case 5:
            if (i <= 9)
                printf("%d-MAY-0%d", year, i + 1);
            else
                printf("%d-MAY-%d", year, i + 1);
            break;
        case 6:
            if (i <= 9)
                printf("%d-JUN-0%d", year, i + 1);
            else
                printf("%d-JUN-%d", year, i + 1);
            break;
        case 7:
            if (i <= 9)
                printf("%d-JUL-0%d", year, i + 1);
            else
                printf("%d-JUL-%d", year, i + 1);
            break;
        case 8:
            if (i <= 9)
                printf("%d-AUG-0%d", year, i + 1);
            else
                printf("%d-AUG-%d", year, i + 1);
            break;
        case 9:
            if (i <= 9)
                printf("%d-SEP-0%d", year, i + 1);
            else
                printf("%d-SEP-%d", year, i + 1);
            break;
        case 10:
            if (i <= 9)
                printf("%d-OCT-0%d", year, i + 1);
            else
                printf("%d-OCT-%d", year, i + 1);
            break;
        case 11:
            if (i <= 9)
                printf("%d-NOV-0%d", year, i + 1);
            else
                printf("%d-NOV-%d", year, i + 1);
            break;
        case 12:
            if (i <= 9)
                printf("%d-DEC-0%d", year, i + 1);
            else
                printf("%d-DEC-%d", year, i + 1);
            break;
        }
        printf("\n");
        do
        {
            printf("   Morning rating (0.0-5.0): ");
            scanf("%lf", &morning[i]);
            if (morning[i] < 0 || morning[i] > 5)
            {
                printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            }
            else
            {
                mornflag[i] = 1;
            }
        } while(mornflag[i] != 1);
        totalmorn = totalmorn + morning[i];
        do
        {
            printf("   Evening rating (0.0-5.0): ");
            scanf("%lf", &evening[i]);
            if (evening[i] < 0 || evening[i] > 5)
            {
                printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            }
            else
            {
                evenflag[i] = 1;
            }
        } while (evenflag[i] != 1);
        totaleven = totaleven + evening[i];
        
    }
    printf("\nSummary\n=======");
    printf("\nMorning total rating: %0.3lf", totalmorn);
    printf("\nEvening total rating:  %0.3lf", totaleven);
    printf("\n----------------------------");
    printf("\nOverall total rating: %0.3lf\n", (totalmorn + totaleven));
    printf("\nAverage morning rating:  %0.1lf", totalmorn / 3);
    printf("\nAverage evening rating:  %0.1lf", totaleven / 3);
    printf("\n----------------------------");
    printf("\nAverage overall rating:  %0.1lf\n",(((totalmorn / 3)+(totaleven / 3))/2));

    return 0;
}
/*
*****************************************************************************
                          Workshop - #6 (P1)
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
#define MINITEMS 1
#define MAXITEMS 10
int main(void)
{
    int flag1 = -1;
    int flag2 = -1;
    int flag3 = -1;
    int flag4 = -1;
    int flag5 = -1;
    const double minmonthlyincome = 500.00;
    const double maxmonthlyincome = 400000.00;
    double monthlyincome;
    int noofitems;
    int i;
    double totalcost = 0;
    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+");
    do
    {
        printf("\n\nEnter your monthly NET income: $");
        scanf("%lf", &monthlyincome);
        if (monthlyincome >= minmonthlyincome && monthlyincome <= maxmonthlyincome)
        {
            flag1 = 0;
        }
        else
        {
            if (monthlyincome < minmonthlyincome)
            {
                printf("ERROR: You must have a consistent monthly income of at least $500.00");
            }
            if (monthlyincome > maxmonthlyincome)
            {
                printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00");
            }
        }
    } while (flag1 != 0);
    do
    {
        printf("\nHow many wish list items do you want to forecast?: ");
        scanf("%d", &noofitems);
        if (noofitems >= MINITEMS && noofitems <= MAXITEMS)
        {
            flag2 = 0;
        }
        else
        {
            printf("ERROR: List is restricted to between 1 and 10 items.\n");
        }
    } while (flag2 != 0);
    double cost[10];
    int priority[10];
    char financing[10];
    for (i = 0; i < noofitems; i++)
    {
        flag3 = -1;
        flag4 = -1;
        flag5 = -1;
        printf("\nItem-%d Details:", i + 1);
        do
        {
            printf("\n   Item cost: $");
            scanf("%lf", &cost[i]);
            if (cost[i] > 100.00)
            {
                flag5 = 0;
            }
            else
            {
                printf("      ERROR: Cost must be at least $100.00");
            }
        } while (flag5 != 0);
        totalcost = totalcost + cost[i];
        do
        {
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf("%d", &priority[i]);
            if (priority[i] > 0 && priority[i] < 4)
            {
                flag3 = 0;
            }
            else
            {
                printf("      ERROR: Value must be between 1 and 3\n");
            }
        } while (flag3 != 0);
        do
        {
            printf("   Does this item have financing options? [y/n]: ");
            scanf(" %c", &financing[i]);
            if (financing[i] == 'y' || financing[i] == 'n')
            {
                flag4 = 0;
            }
            else
            {
                printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
            }
        } while (flag4 != 0);
    }
    printf("\nItem Priority Financed        Cost");
    printf("\n---- -------- -------- -----------");
    for (i = 0; i < noofitems; i++)
    {
        printf("\n%3d%7d%9c%15.2lf", i + 1, priority[i], financing[i], cost[i]);
    }
    printf("\n---- -------- -------- -----------");
    printf("\n                      $ %0.2lf", totalcost);
    printf("\n\nBest of luck in all your future endeavours!\n");
    return 0;
}
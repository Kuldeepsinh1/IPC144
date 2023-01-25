/*
*****************************************************************************
                          Workshop - #6 (P2)
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
    const double minmonthlyincome = 500.00;
    const double maxmonthlyincome = 400000.00;
    double monthlyincome;
    double cost[10];
    int priority[10];
    char financing[10];
    int noofitems;
    int i;
    double totalcost = 0;
    int selection = -1;// in selection the value 0 plays a important role so we dont want it to be zero by default
    int filter;
    int years;
    int month;
    double prioritytotalcost = 0;
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
    flag1 = -1;
    do
    {
        printf("\nHow many wish list items do you want to forecast?: ");
        scanf("%d", &noofitems);
        if (noofitems >= MINITEMS && noofitems <= MAXITEMS)
        {
            flag1 = 0;
        }
        else
        {
            printf("ERROR: List is restricted to between 1 and 10 items.\n");
        }
    } while (flag1 != 0);
    for (i = 0; i < noofitems; i++)
    {
        flag1 = -1;
        printf("\nItem-%d Details:", i + 1);
        do
        {
            printf("\n   Item cost: $");
            scanf("%lf", &cost[i]);
            if (cost[i] > 100.00)
            {
                flag1 = 0;
            }
            else
            {
                printf("      ERROR: Cost must be at least $100.00");
            }
        } while (flag1 != 0);
        flag1 = -1;
        totalcost = totalcost + cost[i];
        do
        {
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf("%d", &priority[i]);
            if (priority[i] > 0 && priority[i] < 4)
            {
                flag1 = 0;
            }
            else
            {
                printf("      ERROR: Value must be between 1 and 3\n");
            }
        } while (flag1 != 0);
        flag1 = -1;
        do
        {
            printf("   Does this item have financing options? [y/n]: ");
            scanf(" %c", &financing[i]);
            if (financing[i] == 'y' || financing[i] == 'n')
            {
                flag1 = 0;
            }
            else
            {
                printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
            }
        } while (flag1 != 0);
    }
    printf("\nItem Priority Financed        Cost");
    printf("\n---- -------- -------- -----------");
    for (i = 0; i < noofitems; i++)
    {
        printf("\n%3d%7d%9c%15.2lf", i + 1, priority[i], financing[i], cost[i]);
    }
    printf("\n---- -------- -------- -----------");
    printf("\n                      $ %0.2lf", totalcost);
    do
    {
        flag1 = -1;
        do
        {
            printf("\n\nHow do you want to forecast your wish list?\n 1. All items (no filter)\n");
            printf(" 2. By priority\n 0. Quit/Exit\nSelection: ");
            scanf("%d", &selection);
            if (selection >= 0 && selection <= 2)
            {
                flag1 = 0;
            }
            else
            {
                printf("\nERROR: Invalid menu selection.");
            }
        } while (flag1 != 0);
        flag1 = -1;
        if (selection == 1)
        {
            printf("\n====================================================");
            printf("\nFilter:   All items");
            printf("\nAmount:   $%0.2lf",totalcost);
            years = ( totalcost / monthlyincome ) / 12;           
            month = (int)((totalcost / monthlyincome) * 100) % 1200;
            if (month % 100 != 0)
            {
                month = month / 100;
                month = month + 1;
                if (month == 12)
                {
                    years = years + 1;
                    month = 0;
                }
            }
            for (i = 0; i < noofitems ; i++)
            {
                if (financing[i] == 'y')
                {
                    flag1 = 0;
                }             
            }
            printf("\nForecast: %d years, %d months", years,month);
            if (flag1 == 0)
            {
                printf("\nNOTE: Financing options are available on some items.");
                printf("\n      You can likely reduce the estimated months.");
            }
            printf("\n====================================================");
        }
        if (selection == 2)
        {
            flag1 = -1;
            do
            {
                printf("\nWhat priority do you want to filter by? [1-3]: ");
                scanf("%d", &filter);
                if (filter > 0 && filter < 4)
                {
                    flag1 = 0;
                }
                else
                {
                    printf("   ERROR: Value must be between 1 and 3\n");
                }
            } while (flag1 != 0);
            flag1 = -1;
            prioritytotalcost = 0;
            for (i = 0; i < noofitems; i++)
            {
                if (priority[i] == filter)
                {
                    prioritytotalcost = prioritytotalcost + cost[i];
                    if (financing[i] == 'y')
                    {
                        flag1 = 0;
                    }
                }
            }
            printf("\n====================================================");
            printf("\nFilter:   by priority (%d)",filter);
            printf("\nAmount:   $%0.2lf",prioritytotalcost);
            years = (prioritytotalcost / monthlyincome) / 12;
            month = (int)((prioritytotalcost / monthlyincome) * 100) % 1200;
            if (month % 100 != 0)
            {
                month = month / 100;
                month = month + 1;
                if (month == 12)
                {
                    years = years + 1;
                    month = 0;
                }
            }
            printf("\nForecast: %d years, %d months", years, month);
            if (flag1 == 0)
            {
                printf("\nNOTE: Financing options are available on some items.");
                printf("\n      You can likely reduce the estimated months.");
            }
            printf("\n====================================================");

        }
        if (selection == 0)
        {
            flag2 = 0;
        }
    } while (flag2 != 0);
    printf("\nBest of luck in all your future endeavours!\n");
    return 0;
}
/*
*****************************************************************************
                          Workshop - #4 (P2)
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
    int flag_other_shopping = -1;
    int amount_of_apples, amount_of_oranges, amount_of_pears;
    int amount_of_tomatoes, amount_of_cabbages;

    int flagapple = -1;
    int flagorange = -1;
    int flagpear = -1;
    int flagtomatoe = -1;
    int flagcabbage = -1;

    int pickapple, pickorange, pickpear, picktomatoe, pickcabbage;
    // this do while loop will keep going till we enter zero for shopping repeat question
    do
    {
        printf("Grocery Shopping");
        printf("\n================");
        //taking shopping input
        // 
        // 
        //taking value for no of apples
        do
        {
            printf("\nHow many APPLES do you need? : ");
            scanf("%d", &amount_of_apples);
            if (amount_of_apples < 0)
            {
                printf("ERROR: Value must be 0 or more.");
            }
            else
            {
                flagapple = 0;
            }
        } 
        while (flagapple != 0);
        //taking value for no of oranges
        do
        {
            printf("\nHow many ORANGES do you need? : ");
            scanf("%d", &amount_of_oranges);
            if (amount_of_oranges < 0)
            {
                printf("ERROR: Value must be 0 or more.");
            }
            else
            {
                flagorange = 0;
            }
        } while (flagorange != 0);
        //taking value for no of pears
        do
        {
            printf("\nHow many PEARS do you need? : ");
            scanf("%d", &amount_of_pears);
            if (amount_of_pears < 0)
            {
                printf("ERROR: Value must be 0 or more.");
            }
            else
            {
                flagpear = 0;
            }
        } while (flagpear != 0);
        //taking value for no of tomatoes
        do
        {
            printf("\nHow many TOMATOES do you need? : ");
            scanf("%d", &amount_of_tomatoes);
            if (amount_of_tomatoes < 0)
            {
                printf("ERROR: Value must be 0 or more.");
            }
            else
            {
                flagtomatoe = 0;
            }
        } while (flagtomatoe != 0);
        //taking value for no of cabbages
        do
        {
            printf("\nHow many CABBAGES do you need? : ");
            scanf("%d", &amount_of_cabbages);
            if (amount_of_cabbages < 0)
            {
                printf("ERROR: Value must be 0 or more.");
            }
            else
            {
                flagcabbage = 0;
            }
        } while (flagcabbage != 0);
        //picking the quantities as per shopping 
        //
        //
        printf("\n--------------------------");
        printf("\nTime to pick the products!");
        printf("\n--------------------------");
        // picking apple
        if (amount_of_apples > 0)
        {
            printf("\n");
            do
            {
                printf("\nPick some APPLES... how many did you pick? : ");
                scanf("%d",&pickapple);
                if (pickapple > amount_of_apples)
                {
                    printf("You picked too many... only %d more APPLE(S) are needed.",amount_of_apples);
                }
                else if (pickapple <= 0)
                {
                    printf("ERROR: You must pick at least 1!");
                }
                else
                {
                    amount_of_apples = amount_of_apples - pickapple;
                    if (amount_of_apples != 0)
                    {
                        printf("Looks like we still need some APPLES...");
                    }
                }
            } while (amount_of_apples != 0);
            printf("Great, that's the apples done!");
        }
        // picking orange
        if (amount_of_oranges > 0)
        {
            printf("\n");
            do
            {
                printf("\nPick some ORANGES... how many did you pick? : ");
                scanf("%d", &pickorange);
                if (pickorange > amount_of_oranges)
                {
                    printf("You picked too many... only %d more ORANGE(S) are needed.", amount_of_oranges);
                }
                else if (pickorange <= 0)
                {
                    printf("ERROR: You must pick at least 1!");
                }
                else
                {
                    amount_of_oranges = amount_of_oranges - pickorange;
                    if (amount_of_oranges != 0)
                    {
                        printf("Looks like we still need some ORANGES...");
                    }
                }
            } while (amount_of_oranges != 0);
            printf("Great, that's the oranges done!");
        }
        // picking pear
        if (amount_of_pears > 0)
        {
            printf("\n");
            do
            {
                printf("\nPick some PEARS... how many did you pick? : ");
                scanf("%d", &pickpear);
                if (pickpear > amount_of_pears)
                {
                    printf("You picked too many... only %d more PEAR(S) are needed.", amount_of_pears);
                }
                else if (pickpear <= 0)
                {
                    printf("ERROR: You must pick at least 1!");
                }
                else
                {
                    amount_of_pears = amount_of_pears - pickpear;
                    if (amount_of_pears != 0)
                    {
                        printf("Looks like we still need some PEARS...");
                    }
                }
            } while (amount_of_pears != 0);
            printf("Great, that's the pears done!");
        }
        // picking tomatoe
        if (amount_of_tomatoes > 0)
        {
            printf("\n");
            do
            {
                printf("\nPick some TOMATOES... how many did you pick? : ");
                scanf("%d", &picktomatoe);
                if (picktomatoe > amount_of_tomatoes)
                {
                    printf("You picked too many... only %d more TOMATO(ES) are needed.", amount_of_tomatoes);
                }
                else if (picktomatoe <= 0)
                {
                    printf("ERROR: You must pick at least 1!");
                }
                else
                {
                    amount_of_tomatoes = amount_of_tomatoes - picktomatoe;
                    if (amount_of_tomatoes != 0)
                    {
                        printf("Looks like we still need some TOMATOES...");
                    }
                }
            } while (amount_of_tomatoes != 0);
            printf("Great, that's the tomatoes done!");
        }
        // picking cabbage
        if (amount_of_cabbages > 0)
        {
            printf("\n");
            do
            {
                printf("\nPick some CABBAGES... how many did you pick? : ");
                scanf("%d", &pickcabbage);
                if (pickcabbage > amount_of_cabbages)
                {
                    printf("You picked too many... only %d more CABBAGE(S) are needed.", amount_of_cabbages);
                }
                else if (pickcabbage <= 0)
                {
                    printf("ERROR: You must pick at least 1!");
                }
                else
                {
                    amount_of_cabbages = amount_of_cabbages - pickcabbage;
                    if (amount_of_cabbages != 0)
                    {
                        printf("Looks like we still need some CABBAGES...");
                    }
                }
            } while (amount_of_cabbages != 0);
            printf("Great, that's the cabbages done!");
        }
        printf("\n\nAll the items are picked!");
        printf("\n\nDo another shopping? (0=NO): ");
        scanf("%d", &flag_other_shopping);
        printf("\n");
    }
    while (flag_other_shopping != 0);
    printf("Your tasks are done for today - enjoy your free time!\n");
    return 0;
}
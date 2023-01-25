/*
*****************************************************************************
                          Workshop - #3 (P2)
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
    // You will need this when converting from grams to pounds (lbs)
    const double GRAMS_IN_LBS = 453.5924;
    char typec1, typec2, typec3;
    char grindsc1, grindsc2, grindsc3;
    int bagwc1, bagwc2, bagwc3;
    char creamc1, creamc2, creamc3;
    double tc1, tc2, tc3;
    // variables to take and store customer input
    char cstrength, coffeecream, maker;
    int dailyserving;
    // Note:
    // You can convert Celsius to Fahrenheit given the following formula:
    // fahrenheit = ((celsius * 1.8) + 32.0);
    // printing the pattern and taking user inputs
    printf("Take a Break - Coffee Shop");
    printf("\n==========================");
    printf("\n\nEnter the coffee product information being sold today...");
    // taking input from employee about the available coffe types
    // coffee type 1
    printf("\n\nCOFFEE-1...");
    printf("\nType ([L]ight,[B]lend): ");
    scanf(" %c", &typec1);
    printf("Grind size ([C]ourse,[F]ine): ");
    scanf(" %c", &grindsc1);
    printf("Bag weight (g): ");
    scanf("%d", &bagwc1);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &creamc1);
    printf("Ideal serving temperature (Celsius): ");
    scanf("%lf", &tc1);
    // coffee type 2
    printf("\nCOFFEE-2...");
    printf("\nType ([L]ight,[B]lend): ");
    scanf("  %c", &typec2);
    printf("Grind size ([C]ourse,[F]ine): ");
    scanf(" %c", &grindsc2);
    printf("Bag weight (g): ");
    scanf("%d", &bagwc2);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &creamc2);
    printf("Ideal serving temperature (Celsius): ");
    scanf("%lf", &tc2);
    // coffee type 3
    printf("\nCOFFEE-3...");
    printf("\nType ([L]ight,[B]lend): ");
    scanf(" %c", &typec3);
    printf("Grind size ([C]ourse,[F]ine): ");
    scanf(" %c", &grindsc3);
    printf("Bag weight (g): ");
    scanf("%d", &bagwc3);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &creamc3);
    printf("Ideal serving temperature (Celsius): ");
    scanf("%lf", &tc3);
    /* the first thing to print is that is coffee type light so the user has liberty to enter 'L' and 'l' and we check if 
       typec1 stores l or L if yes it will print 1 or else 0
       similar logic is used to print for blend , course , fine and cream
       we directly print values for weight in grams and temperature in (C) from user input
       and conversion formula for lbs and (F) are provided
     */
    printf("\n---+---------------+---------------+---------------+-------+--------------");
    printf("\n   |    Coffee     |    Coffee     |   Packaged    | Best  |   Serving");
    printf("\n   |     Type      |  Grind Size   |  Bag Weight   | Served| Temperature");
    printf("\n   +---------------+---------------+---------------+ With  +--------------");
    printf("\nID | Light | Blend | Course | Fine |  (G) | Lbs    | Cream |   (C) |   (F)");
    printf("\n---+---------------+---------------+---------------+-------+--------------");
    printf("\n 1 |   %d   |   %d   |    %d   |   %d  |  %d |  %0.3lf |   %d   |  %0.1lf | %0.1lf", (typec1 == 'l' || typec1 == 'L'), (typec1 == 'b' || typec1 == 'B'), (grindsc1 == 'c' || grindsc1 == 'C'), (grindsc1 == 'f' || grindsc1 == 'F'), bagwc1, (double)(bagwc1 / GRAMS_IN_LBS), (creamc1 == 'y' || creamc1 == 'Y'), tc1, ((tc1 * 1.8) + 32.0));
    printf("\n 2 |   %d   |   %d   |    %d   |   %d  |  %d |  %0.3lf |   %d   |  %0.1lf | %0.1lf", (typec2 == 'l' || typec2 == 'L'), (typec2 == 'b' || typec2 == 'B'), (grindsc2 == 'c' || grindsc2 == 'C'), (grindsc2 == 'f' || grindsc2 == 'F'), bagwc2, (double)(bagwc2 / GRAMS_IN_LBS), (creamc2 == 'y' || creamc2 == 'Y'), tc2, ((tc2 * 1.8) + 32.0));
    printf("\n 3 |   %d   |   %d   |    %d   |   %d  | %d |  %0.3lf |   %d   |  %0.1lf | %0.1lf", (typec3 == 'l' || typec3 == 'L'), (typec3 == 'b' || typec3 == 'B'), (grindsc3 == 'c' || grindsc3 == 'C'), (grindsc3 == 'f' || grindsc3 == 'F'), bagwc3, (double)(bagwc3 / GRAMS_IN_LBS), (creamc3 == 'y' || creamc3 == 'Y'), tc3, ((tc3 * 1.8) + 32.0));
    // asking for the users choices and storing it in variables so that we can compare it with available options  
    printf("\n\nEnter how you like your coffee and the coffee maker equipment you use...");
    printf("\n\nCoffee strength ([M]ild,[R]ich): ");
    scanf(" %c", &cstrength);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &coffeecream);
    printf("Typical number of daily servings: ");
    scanf("%d", &dailyserving);
    printf("Maker ([R]esidential,[C]ommercial): ");
    scanf(" %c", &maker);
    // when we directly print values in print statement by providing conditions ,the conditions tends to get very big
    // so what my method does is that it changes the values t oa more easily comparable form
    /* for instance we store 1 instead of m(or M) in cstrength and 1 in typec1, typec2, typec3 instead of
    * l(or L) and in case user enters r(or R) in cstrength it stores 2 in it and in typec1 also we put 2 for b(or B)
    * so while printing answer we just need to check if cstrength matches to typec1 if yes it print 1 or else 0
    */ 
    if (cstrength == 'm' || cstrength == 'M')
    {
        cstrength = '1';
    }
    else
    {
        cstrength = '2';
    }
    if (typec1 == 'l' || typec1 == 'L')
    {
        typec1 = '1';
    }
    else
    {
        typec1 = '2';
    }
    if (typec2 == 'l' || typec2 == 'L')
    {
        typec2 = '1';
    }
    else
    {
        typec2 = '2';
    }
    if (typec3 == 'l' || typec3 == 'L')
    {
        typec3 = '1';
    }
    else
    {
        typec3 = '2';
    }
    // same method as above is used to perform the calculation for maker and grindsc1 , grindsc2 and grindsc3
    if (maker == 'r' || maker == 'R')
    {
        maker = '1';
    }
    else
    {
        maker = '2';
    }
    if (grindsc1 == 'c' || grindsc1 == 'C')
    {
        grindsc1 = '1';
    }
    else
    {
        grindsc1 = '2';
    }
    if (grindsc2 == 'c' || grindsc2 == 'C')
    {
        grindsc2 = '1';
    }
    else
    {
        grindsc2 = '2';
    }
    if (grindsc3 == 'c' || grindsc3 == 'C')
    {
        grindsc3 = '1';
    }
    else
    {
        grindsc3 = '2';
    }
    // here we change the value of daily serving to its bag weight equivalent hence again we just have to check
    // vlues matches or not
    // for instance if there are 1, 2, 3 or 4 daily servings then also coffee bag weight should be 250g and 
    // here we we convert daily serving to 250 if daily serving is 1,2,3,or 4 so if bag weight for type1 coffe is 250
    // it will match and print 1
    if (dailyserving > 0 && dailyserving < 5)
    {
        dailyserving = 250;
    }
    else if (dailyserving > 4 && dailyserving < 10)
    {
        dailyserving = 500;
    }
    else
    {
        dailyserving = 1000;
    }
    if (bagwc1 >= 0 && bagwc1 <= 250)
    {
        bagwc1 = 250;
    }
    if (bagwc2 >= 0 && bagwc2 <= 250)
    {
        bagwc2 = 250;
    }
    if (bagwc3 >= 0 && bagwc3 <= 250)
    {
        bagwc3 = 250;
    }
    // the method to check for coffecream and creamc1 equivalency was easy but tricky beacause the values entered
    // user are are in two different cases that is if one has 'y' and other has 'Y' stored in it and then we check if 
    // it is equal or not the answer will come 0 despite 1 so here i convert all answers in coffeecream and creamc1 in
    // upper case to tackle above mentioned problem.
    if (coffeecream == 'y' || coffeecream == 'Y')
    {
        coffeecream = 'Y';
    }
    else
    {
        coffeecream = 'N';
    }
    if (creamc1 == 'y' || creamc1 == 'Y')
    {
        creamc1 = 'Y';
    }
    else
    {
        creamc1 = 'N';
    }
    if (creamc2 == 'y' || creamc2 == 'Y')
    {
        creamc2 = 'Y';
    }
    else
    {
        creamc2 = 'N';
    }
    if (creamc3 == 'y' || creamc3 == 'Y')
    {
        creamc3 = 'Y';
    }
    else
    {
        creamc3 = 'N';
    }
    
    //
    printf("\nThe below table shows how your preferences align to the available products:");
    printf("\n\n--------------------+--------------------+-------------+-------+--------------");
    printf("\n  |     Coffee      |       Coffee       |  Packaged   | With  |   Serving");
    printf("\nID|      Type       |     Grind Size     | Bag Weight  | Cream | Temperature");
    printf("\n--+-----------------+--------------------+-------------+-------+--------------");
    printf("\n 1|       %d         |         %d          |      %d      |   %d   |      %d", (typec1 == cstrength), (grindsc1 == maker), (bagwc1 == dailyserving), (coffeecream == creamc1), ((maker == '1' && (tc1 >= 60.0 && tc1 < 70.0)) || (maker == '2' && tc1 >= 70.0)));
    printf("\n 2|       %d         |         %d          |      %d      |   %d   |      %d", (typec2 == cstrength), (grindsc2 == maker), (bagwc2 == dailyserving), (coffeecream == creamc2), ((maker == '1' && (tc2 >= 60.0 && tc2 < 70.0)) || (maker == '2' && tc2 >= 70.0)));
    printf("\n 3|       %d         |         %d          |      %d      |   %d   |      %d", (typec3 == cstrength), (grindsc3 == maker), (bagwc3 == dailyserving), (coffeecream == creamc3), ((maker == '1' && (tc3 >= 60.0 && tc3 < 70.0)) || (maker == '2' && tc3 >= 70.0)));
    // repeating the above process to print again but this time we are not changing values of coffe option
    // available but just the freshly input of users choices which we are taking from next line 
    printf("\n\nEnter how you like your coffee and the coffee maker equipment you use...");
    printf("\n\nCoffee strength ([M]ild,[R]ich): ");
    scanf(" %c", &cstrength);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &coffeecream);
    printf("Typical number of daily servings: ");
    scanf("%d", &dailyserving);
    printf("Maker ([R]esidential,[C]ommercial): ");
    scanf(" %c", &maker);
    if (cstrength == 'm' || cstrength == 'M')
    {
        cstrength = '1';
    }
    else
    {
        cstrength = '2';
    }
    if (maker == 'r' || maker == 'R')
    {
        maker = '1';
    }
    else
    {
        maker = '2';
    }
    if (dailyserving > 0 && dailyserving < 5)
    {
        dailyserving = 250;
    }
    else if (dailyserving > 4 && dailyserving < 10)
    {
        dailyserving = 500;
    }
    else
    {
        dailyserving = 1000;
    }
    if (coffeecream == 'y' || coffeecream == 'Y')
    {
        coffeecream = 'Y';
    }
    else
    {
        coffeecream = 'N';
    }
    printf("\nThe below table shows how your preferences align to the available products:");
    printf("\n\n--------------------+--------------------+-------------+-------+--------------");
    printf("\n  |     Coffee      |       Coffee       |  Packaged   | With  |   Serving");
    printf("\nID|      Type       |     Grind Size     | Bag Weight  | Cream | Temperature");
    printf("\n--+-----------------+--------------------+-------------+-------+--------------");
    printf("\n 1|       %d         |         %d          |      %d      |   %d   |      %d", (typec1 == cstrength), (grindsc1 == maker), (bagwc1 == dailyserving), (coffeecream == creamc1), ((maker == '1' && (tc1 >= 60.0 && tc1 < 70.0)) || (maker == '2' && tc1 >= 70.0)));
    printf("\n 2|       %d         |         %d          |      %d      |   %d   |      %d", (typec2 == cstrength), (grindsc2 == maker), (bagwc2 == dailyserving), (coffeecream == creamc2), ((maker == '1' && (tc2 >= 60.0 && tc2 < 70.0)) || (maker == '2' && tc2 >= 70.0)));
    printf("\n 3|       %d         |         %d          |      %d      |   %d   |      %d", (typec3 == cstrength), (grindsc3 == maker), (bagwc3 == dailyserving), (coffeecream == creamc3), ((maker == '1' && (tc3 >= 60.0 && tc3 < 70.0)) || (maker == '2' && tc3 >= 70.0)));
    printf("\n\nHope you found a product that suits your likes!");
    printf("\n\n");
    return 0;
}
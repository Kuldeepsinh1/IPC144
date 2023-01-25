/*
*****************************************************************************
                          Workshop - #3 (P1)
Full Name  : 
Student ID#: 
Email      : 
Section    : 

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#include <stdio.h>

int main(void)
{
    // You must use this variable in #3 data analysis section!
    const double testValue = 330.99;
    const int pid1 = 111;
    const int pid2 = 222;
    const int pid3 = 111;
    const double pricep1 = 111.49;
    const double pricep2 = 222.99;
    const double pricep3 = 334.49;
    const char tax1 = 'Y';
    const char tax2 = 'N';
    const char tax3 = 'N';
    double average = (pricep1 + pricep2 + pricep3) / 3;
    printf("Product Information");
    printf("\n===================");
    printf("\nProduct-1 (ID:%d)",pid1);
    printf("\n  Taxed: %c", tax1);
    printf("\n  Price: $%0.4lf",pricep1);
    printf("\n\nProduct-2 (ID:%d)", pid2);
    printf("\n  Taxed: %c", tax2);
    printf("\n  Price: $%0.4lf", pricep2);
    printf("\n\nProduct-3 (ID:%d)", pid3);
    printf("\n  Taxed: %c", tax3);
    printf("\n  Price: $%0.4lf", pricep3);
    printf("\n\nThe average of all prices is: $%0.4lf",average);
    printf("\n\nAbout Relational and Logical Expressions!");
    printf("\n========================================");
    printf("\n1. These expressions evaluate to TRUE or FALSE");
    printf("\n2. FALSE: is always represented by integer value 0");
    printf("\n3. TRUE : is represented by any integer value other than 0");
    printf("\n\nSome Data Analysis...");
    printf("\n=====================");
    //q1
    if (tax1 == 'Y')// there are two methods to print answer yes or no (1 or 0) this is method 1
    {
        printf("\n1. Is product 1 taxable? -> 1");
    }
    else
    {
        printf("\n1. Is product 1 taxable? -> 0");
    }
    //q2
    if (tax2 == 'N' && tax3 == 'N')
    {
        printf("\n\n2. Are products 2 and 3 both NOT taxable (N)? -> 1");
    }
    else
    {
        printf("\n\n2. Are products 2 and 3 both NOT taxable (N)? -> 0");
    }
    //q3
    printf("\n\n3. Is product 3 less than testValue ($%0.2lf)? -> %d", testValue, (testValue > pricep3));//method2
    /* I am using method 2 because I dont know which is the preffered method and method 2 is easier to type
       and I demonstrated both equal times so that if there is a requirement to use if else it gets satisfied
    */
    //q4
    printf("\n\n4. Is the price of product 3 more than both product 1 and 2 combined? -> %d",(pricep3>(pricep1+pricep2)));
    //q5
    printf("\n\n5. Is the price of product 1 equal to or more than the price difference");
    printf("\n   of product 3 LESS product 2? ->  %d (price difference: $%0.2lf)", (pricep1 > (pricep3 - pricep2)), (pricep3 - pricep2));
    //q6
    printf("\n\n6. Is the price of product 2 equal to or more than the average price? -> %d",(pricep2>=average));
    //q7
    printf("\n\n7. Based on product ID, product 1 is unique -> %d", (pid1 != pid2 && pid1 != pid3));
    //q8
    printf("\n\n8. Based on product ID, product 2 is unique -> %d", (pid2 != pid1 && pid2 != pid3));
    //q9
    printf("\n\n9. Based on product ID, product 3 is unique -> %d", (pid3 != pid1 && pid3 != pid2));
    printf("\n\n\n");
    return 0;
}
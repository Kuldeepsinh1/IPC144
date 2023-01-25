/*
*****************************************************************************
                          Workshop - #2 (P1)
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
    const double TAX = 0.13;
    const char patSize = 'S';
    double ssp, msp, lsp;//ssp-small shirt price msp-medium shirt price and lsp-large shirt price
    int quantity;// to take the quantity os shirt pat will buy
    int sub_total,tax,total;// to calculate total value of products without tax 
    printf("Set Shirt Prices");// printing as per requirements
    printf("\n================");
    printf("\nEnter the price for a SMALL shirt: $");
    scanf("%lf",&ssp);// taking price from user
    printf("Enter the price for a MEDIUM shirt: $");
    scanf("%lf",&msp);
    printf("Enter the price for a LARGE shirt: $");
    scanf("%lf",&lsp);
    printf("\nShirt Store Price List");
    printf("\n======================");
    printf("\nSMALL  : $%0.2lf", ssp);
    printf("\nMEDIUM : $%0.2lf", msp);
    printf("\nLARGE  : $%0.2lf",lsp);
    printf("\n\nPatty's shirt size is '%c'",patSize);
    printf("\nNumber of shirts Patty is buying: ");
    scanf("%d",&quantity);
    sub_total = (ssp*1000) * quantity;
    tax = sub_total * TAX;
    /*for instance the price of small shirt is 17.96
    then the price for for 8 shirt will be 143.68
    and tax would be 18.6784
    but we multiply by 1000 hence price for 8 shirt become 143680
    and count tax on that which will come out as 18678.4 but as tax is int variable it stores 18678
    then we check if last digit is zero if yes then no need to round off
    and if not then zero it goes in if
    and 18678 gets divided by 10 and as the data type is int it becomes 1867
    then we add 1 (1867 becomes 1868)
    and again multiply by 10 (1868 becomes 18680)
    */
    if (tax % 10 != 0)
    {
        tax = tax / 10;
        tax++;
        tax = tax * 10;
    }
    total = tax + sub_total;
    // as tax and sub total are multiplied by 1000 we need to divide all 3 results by 1000 in end
    printf("\nPatty's shopping cart...");
    printf("\nContains : %d shirts",quantity);
    printf("\nSub-total: $%0.4lf",(double)sub_total/1000); 
    printf("\nTaxes    : $ %0.4lf",(double)tax/1000);
    printf("\nTotal    : $%0.4lf", (double)total/1000);
    printf("\n");
    return 0;
}
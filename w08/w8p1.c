/*
*****************************************************************************
                          Workshop - #8 (P1)
Full Name  : kuldeepsinh sandipsinh mahida
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

// System Libraries
#include <stdio.h>

// User Libraries
#include "w8p1.h"

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* pointer1)
{
	int flag = -1;
	int valuein;
	do {
		scanf("%d", &valuein);
		if (valuein > 0)
		{
			flag = 0;
		}
		else
		{
			printf("ERROR: Enter a positive value: "); 
		}

	} while (flag != 0);
	if (pointer1 != NULL)
	{
		*pointer1 = valuein;
	}
	return valuein;
}

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* pointer2)
{
	int flag = -1;
	double valuein;
	do {
		scanf("%lf", &valuein);
		if (valuein > 0.0)
		{
			flag = 0;
		}
		else
		{
			printf("ERROR: Enter a positive value: ");
		}

	} while (flag != 0);
	if (pointer2 != NULL)
	{
		*pointer2 = valuein;
	}
	return valuein;
}

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int numpro)
{
	printf("Cat Food Cost Analysis\n");
	printf("======================\n\n");
	printf("Enter the details for %d dry food bags of product data for analysis.\n", CHECKMAXPROD);
	printf("NOTE: A 'serving' is %dg\n", GRAMS_PER_SERVE);
}


// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int seqnum)
{
	struct CatFoodInfo c1;
	int flag;
	printf("\nCat Food Product #%d\n", seqnum);
	printf("--------------------\n");
	flag = -1;
	printf("SKU           : ");
	do {
		scanf("%d", &c1.sku);
		if (c1.sku <= 0)
			printf("ERROR: Enter a positive value: ");
		else
			flag = 0;
	} while (flag != 0);
	flag = -1;
	printf("PRICE         : $");
	do {
		scanf("%lf", &c1.price);
		if (c1.price <= 0)
			printf("ERROR: Enter a positive value: ");
		else
			flag = 0;
	} while (flag != 0);

	flag = -1;
	printf("WEIGHT (LBS)  : ");
	do {
		scanf("%lf", &c1.weightlbs);
		if (c1.weightlbs <= 0)
			printf("ERROR: Enter a positive value: ");
		else
			flag = 0;
	} while (flag != 0);

	flag = -1;
	printf("CALORIES/SERV.: ");
	do {
		scanf("%d", &c1.claorie);
		if (c1.claorie <= 0)
			printf("ERROR: Enter a positive value: ");
		else
			flag = 0;
	} while (flag != 0);
	return c1;
};

// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("\nSKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(int sku, double* price, int claorie, double* weightlbs)
{
	printf("%07d %10.2lf %10.1lf %8d\n", sku, *price, *weightlbs, claorie);
}

// 7. Logic entry point
void start()
{
	int i;
	struct CatFoodInfo c1[CHECKMAXPROD] = { { 0 } };
	openingMessage(CHECKMAXPROD);
	for (i = 0; i < CHECKMAXPROD; i++)
	{
		c1[i] = getCatFoodInfo(i + 1);
	}
	displayCatFoodHeader();
	for (i = 0; i < CHECKMAXPROD; i++)
	{
		displayCatFoodData(c1[i].sku, &c1[i].price, c1[i].claorie , &c1[i].weightlbs);
	}
}
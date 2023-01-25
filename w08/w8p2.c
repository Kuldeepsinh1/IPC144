/*
*****************************************************************************
                          Workshop - #8 (P2)
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


// System Libraries
#include <stdio.h>

// User-Defined Libraries
#include "w8p2.h"

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
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(int sku, double* price, int claorie, double* weightlbs)
{
	printf("%07d %10.2lf %10.1lf %8d\n", sku, *price, *weightlbs, claorie);
}

// ----------------------------------------------------------------------------
// PART-2
// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg(const double* LBS, double* kg)
{
	double kgs;
	kgs = *LBS / LBStoKGS;
	if (kg != NULL)
	{
		*kg = kgs;
	}
	return kgs;
}
// 9. convert lbs: g (call convertKG, then * 1000)
int convertLbsG(const double* LBS, int* gram)
{
	int grams;
	grams = (*LBS / LBStoKGS) * 1000;
	if (gram != NULL)
	{
		*gram = grams;
	}
	return grams;
}
// 10. convert lbs: kg and g
void convertLbs(const double* LBS, double* kgresult, int* gramresult)
{
	double Kilogram;
	Kilogram = *LBS / LBStoKGS;
	if (kgresult != NULL)
	{
		*kgresult = Kilogram;
	}
	int gram;
	gram = (*LBS / LBStoKGS) * 1000;
	if (gramresult != NULL)
	{
		*gramresult = gram;
	}
}
// 11. calculate: servings based on gPerServ
double calculateServings(const double gram, const double totalgrams, double* number)
{
	double total_serving;
	total_serving = totalgrams / gram;
	if (number != NULL)
	{
		*number = total_serving;
	}
	return total_serving;
}
// 12. calculate: cost per serving
double calculateCostPerServing(const double* proprice, const double* totalserving,double* num1)
{
	double cost_serving;
	cost_serving = *proprice / *totalserving;
	if (num1 != NULL)
	{
		*num1 = cost_serving;
	}
	return cost_serving;
}
// 13. calculate: cost per calorie
double calculateCostPerCal(const double* proprice, const int* calorie, double* num2)
{
	double cost_calorie = *proprice / *calorie;
	if (num2 != NULL)
		*num2 = cost_calorie;
	return cost_calorie;
}
// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo c1)
{
	struct ReportData r1 = { 0 };
	r1.uniqsku = c1.sku;
	r1.proprice = c1.price;
	r1.suggcalorieperserve = c1.claorie;
	r1.lbs = c1.weightlbs;
	r1.kgs = convertLbsKg(&c1.weightlbs, &r1.kgs);
	r1.grams = convertLbsG(&c1.weightlbs, &r1.grams);
	r1.totalservings = calculateServings(GRAMS_PER_SERVE, r1.grams, &r1.totalservings);
	r1.costperserve = calculateCostPerServing(&c1.price, &r1.totalservings, &r1.costperserve);
	calculateCostPerCal(&c1.price, &c1.claorie, &r1.costcalorieperserve);
	r1.costcalorieperserve /= r1.totalservings;
	return r1;
}
// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
	printf("\nAnalysis Report (Note: Serving = %dg)\n", GRAMS_PER_SERVE);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}
// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData r1, const int cheapest)
{
	if (cheapest != 0)
	{
		printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf ***\n", r1.uniqsku, r1.proprice, r1.lbs, r1.kgs, r1.grams, r1.suggcalorieperserve, r1.totalservings, r1.costperserve, r1.costcalorieperserve);
	}
	else
		printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf\n", r1.uniqsku, r1.proprice, r1.lbs, r1.kgs, r1.grams, r1.suggcalorieperserve, r1.totalservings, r1.costperserve, r1.costcalorieperserve);
}
// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo c1)
{
	printf("\n");
	printf("Final Analysis\n");
	printf("--------------\n");
	printf("Based on the comparison data, the PURRR-fect economical option is:\n");
	printf("SKU:%07d Price: $%.2lf\n\nHappy shopping!\n", c1.sku, c1.price);
}
// ----------------------------------------------------------------------------

// 7. Logic entry point
void start(void)
{
	
	int i;
	int index = 0;
	double cheapest=1;
	struct CatFoodInfo c1[CHECKMAXPROD] = { { 0 } };
	struct ReportData r1[CHECKMAXPROD] = { {0} };
	openingMessage(CHECKMAXPROD);
	for (i = 0; i < CHECKMAXPROD; i++)
	{
		c1[i] = getCatFoodInfo(i + 1);
	}
	printf("\n");
	displayCatFoodHeader();
	for (i = 0; i < CHECKMAXPROD; i++)
	{
		displayCatFoodData(c1[i].sku, &c1[i].price, c1[i].claorie, &c1[i].weightlbs);
	}
	for (i = 0; i < CHECKMAXPROD; i++)
	{
		r1[i] = calculateReportData(c1[i]);
		if (r1[i].costcalorieperserve < cheapest)
		{
			cheapest = r1[i].costcalorieperserve;
			index = i;
		}
	}
	displayReportHeader();
	for (i = 0; i < CHECKMAXPROD; i++)
	{
		displayReportData(r1[i], i == index ? index + 1 : 0);
	}
	displayFinalAnalysis(c1[index]);
}

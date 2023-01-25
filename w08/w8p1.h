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
#define CHECKMAXPROD 3
#define GRAMS_PER_SERVE 64

// ----------------------------------------------------------------------------
// structures
struct CatFoodInfo
{
    int sku;
    double price;
    int claorie;
    double weightlbs;
};



// ----------------------------------------------------------------------------
// function prototypes

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* pointer1);

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* pointer2);

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int numPro);

// 4. Get user input for the details of cat food product
struct CatFoodInfo displayCatInfo(const int seqnum);

// 5. Display the formatted table header
void displayCatFoodHeader(void);

// 6. Display a formatted record of cat food data
void displayCatFoodData(int sku,double* price,int claorie,double* weightlbs);

// 7. Logic entry point
void start(void);

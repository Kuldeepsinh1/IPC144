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


// ----------------------------------------------------------------------------
// defines/macros
#define CHECKMAXPROD 3
#define GRAMS_PER_SERVE 64
#define LBStoKGS 2.20462

// ----------------------------------------------------------------------------
// structures
struct CatFoodInfo
{
    int sku;
    double price;
    int claorie;
    double weightlbs;
};
struct ReportData
{
    int uniqsku;
    double proprice;
    int suggcalorieperserve;
    double lbs;
    double kgs;
    int grams;
    double totalservings;
    double costperserve;
    double costcalorieperserve;
};

// ----------------------------------------------------------------------------
// function prototypes

// PART-1

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
void displayCatFoodData(int sku, double* price, int claorie, double* weightlbs);

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg
double convertLbsKg(const double* LBS, double* kg);

// 9. convert lbs: g
int convertLbsG(const double* LBS, int* gram);

// 10. convert lbs: kg / g
void convertLbs(const double* LBS, double* kgresult, int* gramresult);

// 11. calculate: servings based on gPerServ
double calculateServings(const double gram, const double totalgrams, double* number);

// 12. calculate: cost per serving
double calculateCostPerServing(const double* proprice, const double* totalserving, double* num1);

// 13. calculate: cost per calorie
double calculateCostPerCal(const double* proprice, const int* calorie, double* num2);

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo c1);

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void);

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData r1, const int cheapest);

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo c1);

// ----------------------------------------------------------------------------

// 7. Logic entry point 
void start(void);

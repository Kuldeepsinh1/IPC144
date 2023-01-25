/*
*****************************************************************************
                        Assignment 1 - Milestone 3
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
#include<string.h>


// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"


//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's the patient table header (table format)
void displayPatientTableHeader(void)
{
    printf("Pat.# Name            Phone#\n"
        "----- --------------- --------------------\n");
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient* patient, int fmt)
{
    if (fmt == FMT_FORM)
    {
        printf("Name  : %s\n"
            "Number: %05d\n"
            "Phone : ", patient->name, patient->patientNumber);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
    else
    {
        printf("%05d %-15s ", patient->patientNumber,
            patient->name);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's appointment schedule headers (date-specific or all records)
void displayScheduleTableHeader(const struct Date* date, int isAllRecords)
{
    printf("Clinic Appointments for the Date: ");

    if (isAllRecords)
    {
        printf("<ALL>\n\n");
        printf("Date       Time  Pat.# Name            Phone#\n"
            "---------- ----- ----- --------------- --------------------\n");
    }
    else
    {
        printf("%04d-%02d-%02d\n\n", date->year, date->month, date->day);
        printf("Time  Pat.# Name            Phone#\n"
            "----- ----- --------------- --------------------\n");
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display a single appointment record with patient info. in tabular format
void displayScheduleData(const struct Patient* patient,
    const struct Appointment* appoint,
    int includeDateField)
{
    if (includeDateField)
    {
        printf("%04d-%02d-%02d ", appoint->date.year, appoint->date.month,
            appoint->date.day);
    }
    printf("%02d:%02d %05d %-15s ", appoint->time.hour, appoint->time.min,
        patient->patientNumber, patient->name);

    displayFormattedPhone(patient->phone.number);

    printf(" (%s)\n", patient->phone.description);
}


//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu
void menuMain(struct ClinicData* data)
{
    int selection;
    int flag = -1;

    do {
        printf("Veterinary Clinic System\n"
            "=========================\n"
            "1) PATIENT     Management\n"
            "2) APPOINTMENT Management\n"
            "-------------------------\n"
            "0) Exit System\n"
            "-------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
        switch (selection)
        {
        case 0:
            printf("Are you sure you want to exit? (y|n): ");
            selection = !(inputCharOption("yn") == 'y');
            putchar('\n');
            if (!selection)
            {
                printf("Exiting system... Goodbye.\n\n");
                flag = 0;
            }
            break;
        case 1:
            menuPatient(data->patients, data->maxPatient);
            break;
        case 2:
            menuAppointment(data);
            break;
        }
    } while (flag != 0);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
    int selection;

    do {
        printf("Patient Management\n"
            "=========================\n"
            "1) VIEW   Patient Data\n"
            "2) SEARCH Patients\n"
            "3) ADD    Patient\n"
            "4) EDIT   Patient\n"
            "5) REMOVE Patient\n"
            "-------------------------\n"
            "0) Previous menu\n"
            "-------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 5);
        putchar('\n');
        switch (selection)
        {
        case 1:
            displayAllPatients(patient, max, FMT_TABLE);
            suspend();
            break;
        case 2:
            searchPatientData(patient, max);
            break;
        case 3:
            addPatient(patient, max);
            suspend();
            break;
        case 4:
            editPatient(patient, max);
            break;
        case 5:
            removePatient(patient, max);
            suspend();
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient edit
void menuPatientEdit(struct Patient* patient)
{
    int selection;

    do {
        printf("Edit Patient (%05d)\n"
            "=========================\n"
            "1) NAME : %s\n"
            "2) PHONE: ", patient->patientNumber, patient->name);

        displayFormattedPhone(patient->phone.number);

        printf("\n"
            "-------------------------\n"
            "0) Previous menu\n"
            "-------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');

        if (selection == 1)
        {
            printf("Name  : ");
            inputCString(patient->name, 1, NAME_LEN);
            putchar('\n');
            printf("Patient record updated!\n\n");
        }
        else if (selection == 2)
        {
            inputPhoneData(&patient->phone);
            printf("Patient record updated!\n\n");
        }

    } while (selection);
}


// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Appointment Management
void menuAppointment(struct ClinicData* data)
{
    int selection;

    do {
        printf("Appointment Management\n"
            "==============================\n"
            "1) VIEW   ALL Appointments\n"
            "2) VIEW   Appointments by DATE\n"
            "3) ADD    Appointment\n"
            "4) REMOVE Appointment\n"
            "------------------------------\n"
            "0) Previous menu\n"
            "------------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 4);
        putchar('\n');
        switch (selection)
        {
        case 1:
            viewAllAppointments(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 2:
            viewAppointmentSchedule(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 3:
            addAppointment(data->appointments, data->maxAppointments,
                data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 4:
            removeAppointment(data->appointments, data->maxAppointments,
                data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        }
    } while (selection);
}


// ---------------------------------------------------------------------------
// !!! INSERT/COPY YOUR MS#2 FUNCTION DEFINITIONS BELOW... !!!
// Note: Maintain the same order/sequence as it is listed in the header file
//       Properly organize/categorize any new functions accordingly
// ---------------------------------------------------------------------------
// 
// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (Copy your code from MS#2)
void displayAllPatients(const struct Patient patient[], int max, int fmt)
{
    int i;
    int flag = 0;
    // check if there are no eligible records to display
    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber != 0)
        {

            flag = -1;

            break;
        }
    }
    if (flag == 0)
    {
        printf("*** No records found ***\n");
    }
    else
    {
        // display the table header
        displayPatientTableHeader();
        for (i = 0; i < max; i++)
        {
            // display a single eligible patient record
            if (patient[i].patientNumber != 0)
                displayPatientData(&patient[i], fmt);
        }
    }
    putchar('\n');
}

// Search for a patient record based on patient number or phone number
// (Copy your code from MS#2)
void searchPatientData(const struct Patient patient[], int max)
{
    int selection;
    // display the search options
    do
    {
        printf("Search Options\n"
            "==========================\n"
            "1) By patient number\n"
            "2) By phone number\n"
            "..........................\n"
            "0) Previous menu\n"
            "..........................\n"
            "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');

        if (selection == 1)
        {
            searchPatientByPatientNumber(patient, max);
            suspend();
        }
        else if (selection == 2)
        {
            searchPatientByPhoneNumber(patient, max);
            suspend();
        }
    } while (selection);
}

// Add a new patient record to the patient array
// (Copy your code from MS#2)

void addPatient(struct Patient patient[], int max)
{
    int i;
    int free_index;
    int flag = 0;

    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber == 0)
        {

            flag = -1;
            free_index = i;

            break;
        }
    }

    if (flag == 0)
    {
        printf("ERROR: Patient listing is FULL!\n");
    }

    else
    {
        patient[free_index].patientNumber = nextPatientNumber(patient, max);
        inputPatient(&patient[free_index]);
        printf("*** New patient record added ***\n");
    }
    putchar('\n');
}

// Edit a patient record from the patient array
// (Copy your code from MS#2)

void editPatient(struct Patient patient[], int max)
{

    printf("Enter the patient number: ");
    int num = inputInt();

    int index = findPatientIndexByPatientNum(num, patient, max);
    putchar('\n');

    if (index == -1)
    {
        printf("ERROR: Patient record not found!\n");
    }
    else
    {
        // call the menuPatientEdit() function using the index
        menuPatientEdit(&patient[index]);
    }
}

// Remove a patient record from the patient array
// (Copy your code from MS#2)
void removePatient(struct Patient patient[], int max)
{
    // get the patient number as user input
    printf("Enter the patient number: ");
    int num = inputInt();

    // using the patient number, get the index in the patient array
    int index = findPatientIndexByPatientNum(num, patient, max);
    putchar('\n');

    // if index is -1, patient number is not existing
    if (index == -1)
    {
        printf("ERROR: Patient record not found!\n");
    }
    else
    {
        // remove the patient in the array using the index
        printf("Name  : %s\n", patient[index].name);
        printf("Number: %05d\n", patient[index].patientNumber);
        printf("Phone : ");
        displayFormattedPhone(patient[index].phone.number);
        printf(" (%s)\n", patient[index].phone.description);
        printf("\nAre you sure you want to remove this patient record? (y/n): ");
        char answer;
        answer = inputCharOption("yn");
        if (answer == 'n')
        {
            printf("Operation aborted.\n");
        }
        else
        {
            patient[index].patientNumber = 0;
            printf("Patient record has been removed!\n");
        }
    }
    putchar('\n');
}

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Milestone #3 mandatory functions...
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// View ALL scheduled appointments
// Todo:
void viewAllAppointments(struct ClinicData* data)
{
    int i = 0, j = 0;
    int size = 0;
    //Calculate the size of the appoiment array
    size = calculateSizeOfAppointmentsArray(data->appointments, data->maxAppointments);
    //Sorting the appointment
    sortingAppoint(data->appointments, size);
    if (data)
    {
        displayScheduleTableHeader(&data->appointments->date, 1);
        for (i = 0; i < data->maxAppointments; i++)
        {
            for (j = 0; j < data->maxPatient; j++)
            {
                if (data->appointments[i].patientNumber == data->patients[j].patientNumber)
                {
                    displayScheduleData(&data->patients[j], &data->appointments[i], 1);
                    break;
                }
            }
        }
        putchar('\n');
    }
    else
    {
        printf("*** No records found ***\n\n");
    }
}

// View appointment schedule for the user input date
// Todo:
void viewAppointmentSchedule(struct ClinicData* data)
{
    int i, j;
    int size = 0;
    struct Date userInput = { '\0' };
    //Prompt user to enter date and validate them
    checkLeapYear(&userInput);
    putchar('\n');
    //Calculate the size of the appoinment array
    size = calculateSizeOfAppointmentsArray(data->appointments, data->maxAppointments);
    displayScheduleTableHeader(&userInput, 0);
    for (i = 0; i < size; i++)
    {
        //Find the exact date
        if (userInput.year == data->appointments[i].date.year &&
            userInput.month == data->appointments[i].date.month && userInput.day == data->appointments[i].date.day)
        {
            for (j = 0; j < size; j++)
            {
                if (data->appointments[i].patientNumber == data->patients[j].patientNumber)
                {
                    displayScheduleData(&data->patients[j], &data->appointments[i], 0);
                }
            }
        }
    }
    putchar('\n');
}
// Add an appointment record to the appointment array
// Todo:
void addAppointment(struct Appointment* appointments, int maxAppointments, struct Patient* patients, int maxPatient)
{
    int counter;
    int size = 0;
    int flag = 1;
    //Calculate the size of the array
    size = calculateSizeOfAppointmentsArray(appointments, maxAppointments);
    //Execute if there is available element
    if (maxAppointments > size)
    {
        printf("Patient Number: ");
        scanf(" %d", &appointments[size].patientNumber);
        clearInputBuffer();
        //Check if there is patient with provied patient number
        if (findPatientIndexByPatientNum(appointments[size].patientNumber,
            patients, maxPatient) != -1)
        {
            do
            {
                int duplicate = 0;
                checkLeapYear(&appointments[size].date);
                do
                {
                    printf("Hour (0-23)  : ");
                    appointments[size].time.hour = inputIntRange(0, 23);
                    printf("Minute (0-59): ");
                    appointments[size].time.min = inputIntRange(0, 59);
                    //Check if there is any appoinment with the same time and date
                    for (counter = 0; counter < size; counter++)
                    {
                        if (appointments[size].date.year ==
                            appointments[counter].date.year &&
                            appointments[size].date.month ==
                            appointments[counter].date.month &&
                            appointments[size].date.day ==
                            appointments[counter].date.day &&
                            appointments[size].time.hour ==
                            appointments[counter].time.hour &&
                            appointments[size].time.min ==
                            appointments[counter].time.min)
                        {
                            printf("\nERROR: Appointment timeslot is not available!\n\n");
                            duplicate = 1;
                        }
                    }
                    //Execute if there is no duplicate
                    if (duplicate == 0)
                    {
                        if (appointments[size].time.hour >= CLINICSTARTTIMEINHOUR && appointments[size].time.hour <= CLINICENDTIMEINHOUR)
                        {
                            if (appointments[size].time.min >=
                                CLINICSTARTTIMEINMINUTES &&
                                appointments[size].time.min <= CLINICENDTIMEINMINUTES)
                            {
                                printf("\n*** Appointment scheduled! ***\n\n");
                                flag = 0;
                                break;
                            }
                            else
                            {
                                printf("ERROR: Time must be between 10:00 and 14:00 in %d minute intervals.\n\n", APPOINTMENTDURATION);
                            }
                        }
                        else
                        {
                            printf("ERROR: Time must be between 10:00 and 14:00 in %d minute intervals.\n\n", APPOINTMENTDURATION);
                        }
                    }
                } while (duplicate == 0);
            } while (flag == 1);
        }
        else
        {
            printf("\nERROR: Patient record not found!\n\n");
        }
    }
}

// Remove an appointment record from the appointment array
// Todo:
void removeAppointment(struct Appointment* appointments, int maxAppointments,
    struct Patient* patients, int maxPatient)
{
    int index;
    char selection;
    int i;
    struct Appointment removeAppm = { 0 };
    int size = 0;
    //Calculate the size of the appoinment array
    size = calculateSizeOfAppointmentsArray(appointments, maxAppointments);
    //Sorting appointments
    sortingAppoint(appointments, size);
    printf("Patient Number: ");
    scanf(" %d", &removeAppm.patientNumber);
    clearInputBuffer();
    index = findPatientIndexByPatientNum(removeAppm.patientNumber, patients, maxPatient);
    if (index != -1)
    {
        checkLeapYear(&removeAppm.date);
        putchar('\n');
        displayPatientData(&patients[index], FMT_FORM);
        printf("Are you sure you want to remove this appointment (y,n): ");
        scanf(" %c", &selection);
        clearInputBuffer();
        if (selection == 'y')
        {
            //Find the index of the appointment in array by date
            for (i = 0; i < maxAppointments; i++)
            {
                if (removeAppm.patientNumber ==
                    appointments[i].patientNumber &&
                    removeAppm.date.day ==
                    appointments[i].date.day &&
                    removeAppm.date.month == appointments[i].date.month &&
                    removeAppm.date.year ==
                    appointments[i].date.year)
                {
                    index = i;
                    break;
                }
            }
            //Removing the appointment
            appointments[index].patientNumber = 0;
            appointments[index].date.day = 0;
            appointments[index].date.month = 0;
            appointments[index].date.year = 0;
            appointments[index].time.hour = 0;
            appointments[index].time.min = 0;
            printf("\nAppointment record has been removed!\n\n");
        }
        else
        {
            printf("Operation aborted.\n\n");
        }
    }
    else
    {
        printf("ERROR: Patient record not found!\n\n");
    }
}
//Calculate the size of the appointments array
int calculateSizeOfAppointmentsArray(const struct Appointment* appointments, int maxAppointment)
{
    int size = 0;
    int i;
    for (i = 0; i < maxAppointment; i++)
    {
        if (appointments[i].date.day != 0)
        {
            size++;
        }
    }
    return size;
}
//Check Leap Year
void checkLeapYear(struct Date* userInput)
{
    printf("Year        : ");
    scanf(" %d", &userInput->year);
    clearInputBuffer();
    printf("Month (1-12): ");
    userInput->month = inputIntRange(0, 12);
    switch (userInput->month)
    {
    case 1:
        printf("Day (1-31)  : ");
        userInput->day = inputIntRange(0, 31);
        break;
    case 2:
        //Check if entered year input is a leap year
        if (userInput->year % 400 == 0 || userInput->year % 100 == 0 ||
            userInput->year % 4 == 0)
        {
            printf("Day (1-29)  : ");
            userInput->day = inputIntRange(1, 29);
        }
        else
        {
            printf("Day (1-28)  : ");
            userInput->day = inputIntRange(1, 28);
        }
        break;
    case 3:
        printf("Day (1-31)  : ");
        userInput->day = inputIntRange(1, 31);
        break;
    case 4:
        printf("Day (1-30)  : ");
        userInput->day = inputIntRange(1, 30);
        break;
    case 5:
        printf("Day (1-31)  : ");
        userInput->day = inputIntRange(1, 31);
        break;
    case 6:
        printf("Day (1-30)  : ");
        userInput->day = inputIntRange(1, 30);
        break;
    case 7:
        printf("Day (1-31)  : ");
        userInput->day = inputIntRange(1, 31);
        break;
    case 8:
        printf("Day (1-31)  : ");
        userInput->day = inputIntRange(1, 31);
        break;
    case 9:
        printf("Day (1-30)  : ");
        userInput->day = inputIntRange(1, 30);
        break;
    case 10:
        printf("Day (1-31)  : ");
        userInput->day = inputIntRange(1, 31);
        break;
    case 11:
        printf("Day (1-30)  : ");
        userInput->day = inputIntRange(1, 30);
        break;
    case 12:
        printf("Day (1-31)  : ");
        userInput->day = inputIntRange(1, 31);
        break;
    default:
        inputIntRange(1, 12);
        break;
    }
}
//Selection Sort
void sortingAppoint(struct Appointment* appointments, int size)
{
    int i, j;
    struct Appointment temp;
    for (i = size - 1; i > 0; i--)
    {
        for (j = 0; j < i; j++)
        {
            //Sorting by year
            if (appointments[j].date.year > appointments[j + 1].date.year)
            {
                temp = appointments[j];
                appointments[j] = appointments[j + 1];
                appointments[j + 1] = temp;
            }
            //Sorting by day
            else if (appointments[j].date.year == appointments[j + 1].date.year && appointments[j].date.day > appointments[j + 1].date.day)
            {
                temp = appointments[j];
                appointments[j] = appointments[j + 1];
                appointments[j + 1] = temp;
            }
            //Sorting by hour
            else if (appointments[j].date.year == appointments[j +
                1]
                .date.year &&
                appointments[j].date.day == appointments[j +
                1]
                .date.day &&
                appointments[j].time.hour > appointments[j + 1].time.hour)
            {
                temp = appointments[j];
                appointments[j] = appointments[j + 1];
                appointments[j + 1] = temp;
            }
            //Sorting by min
            else if (appointments[j].date.year == appointments[j +
                1]
                .date.year &&
                appointments[j].date.day == appointments[j +
                1]
                .date.day &&
                appointments[j].time.hour == appointments[j + 1].time.hour &&
                appointments[j].time.min > appointments[j + 1].time.min)
            {
                temp = appointments[j];
                appointments[j] = appointments[j + 1];
                appointments[j + 1] = temp;
            }
        }
    }
}

//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
// (Copy your code from MS#2)

void searchPatientByPatientNumber(const struct Patient patient[], int max)
{
    // get the patient number as user input
    printf("Search by patient number: ");
    int num = inputInt();

    // using the patient number, get the index in the patient array
    int index = findPatientIndexByPatientNum(num, patient, max);
    putchar('\n');

    // if index is -1, patient number is not existing
    if (index == -1)
    {
        printf("*** No records found ***\n");
    }
    else
    {
        // call the displayPatientData() using the index in the patient array
        displayPatientData(&patient[index], FMT_FORM);
    }
    putchar('\n');
}

// Search and display patient records by phone number (tabular)
// (Copy your code from MS#2)
void searchPatientByPhoneNumber(const struct Patient patient[], int max)
{
    char phone_number[11];

    // get the phone number of the patient as user input
    printf("Search by phone number: ");
    inputCString(phone_number, 10, 10);
    putchar('\n');

    int flag = 0;
    int i;

    for (i = 0; i < max; i++)
    {
        // display a single eligible patient record
        if (strcmp(phone_number, patient[i].phone.number) == 0)
        {
            flag = -1;
            break;
        }
    }

    // display the table header
    displayPatientTableHeader();

    if (flag == 0)
    {
        putchar('\n');
        printf("*** No records found ***\n");
    }
    else
    {
        for (i = 0; i < max; i++)
        {
            // display a single eligible patient record
            if (strcmp(phone_number, patient[i].phone.number) == 0)
                displayPatientData(&patient[i], FMT_TABLE);
        }
    }
    putchar('\n');
}


// Get the next highest patient number
// (Copy your code from MS#2)

int nextPatientNumber(const struct Patient patient[], int max)
{
    int i;
    int next_highest_patient = -1;

    // find the largest patient number in the array
    // and store in variable next
    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber > next_highest_patient)
        {
            next_highest_patient = patient[i].patientNumber;
        }
    }

    // add 1 to the largest patient number in the array
    ++next_highest_patient;

    return next_highest_patient;
}

// Find the patient array index by patient number (returns -1 if not found)
// (Copy your code from MS#2)

int findPatientIndexByPatientNum(int patientNumber, const struct Patient patient[], int max)
{
    int i;

    // -1 is default return value, which is patient number not found
    int flag2 = -1;

    // iterate over each element the patient array
    for (i = 0; i < max; i++)
    {
        // if patientNumber is found, return the index
        if (patient[i].patientNumber == patientNumber)
        {
            flag2 = i;
            break;
        }
    }
    return flag2;
}


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
// (Copy your code from MS#2)
void inputPatient(struct Patient* patient)
{
    // get the patient info as user input
    printf("Patient Data Input\n"
        "------------------\n");
    printf("Number: %05d\n", patient->patientNumber);
    printf("Name  : ");
    inputCString(patient->name, 1, NAME_LEN);
    putchar('\n');
    inputPhoneData(&(patient->phone));
}

// Get user input for phone contact information
// (Copy your code from MS#2)

void inputPhoneData(struct Phone* phone)
{
    int selection;

    printf("Phone Information\n"
        "-----------------\n");
    printf("How will the patient like to be contacted?\n");
    printf("1. Cell\n");
    printf("2. Home\n");
    printf("3. Work\n");
    printf("4. TBD\n");
    printf("Selection: ");

    selection = inputIntRange(1, 4);

    putchar('\n');

    if (selection == 1)
    {
        printf("Contact: ");
        puts("CELL");
        strcpy(phone->description, "CELL");
    }
    if (selection == 2)
    {
        printf("Contact: ");
        puts("HOME");
        strcpy(phone->description, "HOME");
    }
    if (selection == 3)
    {
        printf("Contact: ");
        puts("WORK");
        strcpy(phone->description, "WORK");
    }
    if (selection == 4)
    {
        strcpy(phone->description, "TBD");
    }
    else
    {
        printf("Number : ");
        inputCString(phone->number, 10, 10);
        putchar('\n');
    }
}

//////////////////////////////////////
// FILE FUNCTIONS
//////////////////////////////////////

// Import patient data from file into a Patient array (returns # of records read)
/// ToDo:
int importPatients(const char* datafile, struct Patient patients[], int max)
{
    FILE* fp = NULL;
    fp = fopen(datafile, "r");
    int read = 0;
    if (fp != NULL)
    {
        while (!feof(fp) && read < max)
        {
            fscanf(fp, "%d|%29[^|]|%4[^|]|", &patients[read].patientNumber,
                patients[read].name, patients[read].phone.description);
            if (!(strcmp(patients[read].phone.description, "TBD") == 0))
            {
                fscanf(fp, "%[^\n]%*c", patients[read].phone.number);
            }
            read++;
        }
        fclose(fp);
    }
    return read;
}

// Import appointment data from file into an Appointment array (returns # of records read)
// ToDo:
int importAppointments(const char* datafile, struct Appointment appoints[], int max)
{
    FILE* fp = NULL;
    fp = fopen(datafile, "r");
    int read = 0;
    if (fp != NULL)
    {
        while (fscanf(fp, "%d,%d,%d,%d,%d,%d", &appoints[read].patientNumber,
            &appoints[read].date.year, &appoints[read].date.month, &appoints[read].date.day,
            &appoints[read].time.hour, &appoints[read].time.min) == 6 &&
            read < max)
        {
            read++;
        }
        fclose(fp);
    }
    return read;
}

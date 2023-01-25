// FUNCTION PROTOTYPES
// Clear the standard input buffer
void clearInputBuffer(void);
// Wait for user to input the "enter" key to continue
void suspend(void);


//  1-> take integer as input and return it
    int inputInt();
//  2-> function to accept a positive integer from user
	int inputIntPositive();
//  3-> function to accept a range and return value
	int inputIntRange(int, int);
//  4-> function to accept character array and return character
	char inputCharOption(const char[]);
//  5-> functons with three inputs and no return type.
	void inputCString(char*, int ,int);
//  6-> function to take character string input and print it. 
	void displayFormattedPhone(const char *);
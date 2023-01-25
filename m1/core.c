/*
*****************************************************************************
						Assignment 1 - Milestone 1
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

#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

// As demonstrated in the course notes: 
// https://intro2c.sdds.ca/D-Modularity/input-functions#clearing-the-buffer
// Clear the standard input buffer
void clearInputBuffer(void)
{
	// Discard all remaining char's from the standard input buffer:
	while (getchar() != '\n')
	{
		; // do nothing!
	}
}
// Wait for user to input the "enter" key to continue
void suspend(void)
{
	printf("<ENTER> to continue...");
	clearInputBuffer();
	putchar('\n');
}

int inputInt()
{
	int input = 0;
	char cinput = 'x';
	int flag = -1;
	do
	{
		
		scanf("%d%c", &input, &cinput);
		if (cinput == '\n')
		{
			flag = 0;
		}
		else
		{
			clearInputBuffer();
			printf("Error! Input a whole number: ");
		}
	} while (flag != 0);
	return input;
}
int inputIntPositive()
{
	int input = 0;
	int flag = -1;
	do
	{
		scanf("%d", &input);
		if (input > 0)
		{
			flag = 0;
		}
		else
		{
			printf("ERROR! Value must be > 0: ");
		}
	} while (flag != 0);
	return input;
}
int inputIntRange(int lowerbound, int upperbound)
{
	char cinput = 'x';
	int input = 0;
	int flag = -1;
	do
	{
		scanf("%d%c", &input,&cinput);
		if (cinput == '\n')
		{
			if ((input >= lowerbound && input <= upperbound))
			{
				flag = 0;
			}
			else
			{
				printf("ERROR! Value must be between %d and %d inclusive: ",lowerbound,upperbound);
			}
		}
		else
		{
			clearInputBuffer();
			printf("Error! Input a whole number: ");
		}
		
	} while (flag != 0);
	return input;
}

char inputCharOption(const char str[])
{
	char input= ' ';
	char match = ' ';
	int flag = -1;
	int i = 0;
	do
	{
		scanf("%c",&input);
		for (i = 0; i < strlen(str) || str[i] == '\0'; i++)
		{
			if (input == str[i])
			{
				match = input;
			}

		}
		if (match == ' ')
		{
			printf("ERROR: Character must be one of [%s]: ", str);
			clearInputBuffer();
		}
		else
		{
			flag = 0;
		}

	} while (flag != 0);
	return match;
}

void inputCString(char* pointer, int a, int b)
{
	char input[100];
	int size = 0;
	int i = 0;
	int flag = -1;
	do
	{
	    clearInputBuffer();
	    scanf("%[^\n]", input);
	    for(i=0;i<100;i++)
	    {
	        if(input[i]=='\0')
	        {
	            size = i;
	            break;
	        }
	    }
	    if(size >= a && size <= b)
	    {
	        for(i=0;i<=size;i++)
	        {
	            *pointer=input[i];
	            pointer++;
	        }
	        flag=0;
	    }
	    else
	    {
	        if(a==b)
	        {
	            printf("ERROR: String length must be exactly %d chars: ",a);
	        }
		else if (a + 1 < b)
		{
			printf("ERROR: String length must be no more than %d chars: ",b);
		}
	        else
	        {
	            printf("ERROR: String length must be between %d and %d chars: ",a,b);
	        }
	    }
	}while(flag != 0);
	
}
void displayFormattedPhone(const char* string)
{
	int flag = 1;
	int i = 0;
	if (string != NULL)
	{
		for (i = 0; string[i] && flag; i++)
		{

			if (string[i] < 48 || string[i] > 57)
			{
				flag = 0;
			}
		}
	}
	if (flag && i == 10)
	{
		printf("(");
		for (i = 0; i < 3; i++)
		{
			printf("%c", string[i]);
		}
		printf(")");
		for (i = 3; i < 6; i++)
		{
			printf("%c", string[i]);
		}
		printf("-");
		for (i = 6; i < 10; i++)
		{
			printf("%c", string[i]);
		}
	}
	else
	{
		printf("(___)___-____");
	}
}

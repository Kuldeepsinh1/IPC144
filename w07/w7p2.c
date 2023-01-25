/*
*****************************************************************************
						  Workshop - #7 (P2)
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

#define MAXPATHLENGTH 70 // macros that can be changed and we do not need to change logic in the code
#define MINPATHLENGTH 10
#define MAXLIVES 10
#define PATHISMULTIPLEOF 5

int main(void)
{
	char symprint[MAXPATHLENGTH];
	int flag = -1;
	int flag1 = -1;
	int i = 0;
	int iteration, chances, nextpos;
	struct PlayerInfo // making a user defined data type PlayerInfo
	{
		int livecnt;
		char plyricon;
		int foundtreasercnt;
		int PastEntrdPos[MAXPATHLENGTH];
	};
	struct GameInfo
	{
		int maxmoves;
		int pathlength;
		int bombpos[MAXPATHLENGTH];
		int treasurepos[MAXPATHLENGTH];
	};
	struct PlayerInfo player; // making a object of user defined data type
	struct GameInfo game;
	printf("================================");
	printf("\n         Treasure Hunt!");
	printf("\n================================\n");
	printf("\nPLAYER Configuration");
	printf("\n--------------------");
	printf("\nEnter a single character to represent the player: ");
	scanf(" %c", &player.plyricon);
	do
	{
		printf("Set the number of lives: ");
		scanf("%d", &player.livecnt);
		if (player.livecnt >= 1 && player.livecnt <= MAXLIVES)
		{
			printf("Player configuration set-up is complete\n");
			flag = 0;
		}
		else
		{
			printf("     Must be between 1 and 10!\n");
		}
	} while (flag != 0);
	player.foundtreasercnt = 0;//we are using this loop to set all the values to default as we are told
	for (i = 0; i < MAXPATHLENGTH; i++)
	{
		player.PastEntrdPos[i] = 0;
	}
	printf("\nGAME Configuration");
	printf("\n------------------");
	flag = -1;
	do
	{
		printf("\nSet the path length (a multiple of %d between %d-%d): ", PATHISMULTIPLEOF, MINPATHLENGTH, MAXPATHLENGTH);
		scanf("%d", &game.pathlength);
		if ((game.pathlength % PATHISMULTIPLEOF == 0) && (game.pathlength >= MINPATHLENGTH && game.pathlength <= MAXPATHLENGTH))
		{
			flag = 0;
		}
		else
		{
			printf("     Must be a multiple of %d and between %d-%d!!!", PATHISMULTIPLEOF, MINPATHLENGTH, MAXPATHLENGTH);
		}
	} while (flag != 0);
	flag = -1;
	chances = game.pathlength * 0.75;
	do
	{
		printf("Set the limit for number of moves allowed: ");
		scanf("%d", &game.maxmoves);
		if (game.maxmoves >= player.livecnt && game.maxmoves <= chances)
		{
			flag = 0;
		}
		else
		{
			printf("    Value must be between %d and %d\n", player.livecnt, chances);
		}
	} while (flag != 0);
	printf("\nBOMB Placement\n--------------");
	printf("\nEnter the bomb positions in sets of %d where a value", PATHISMULTIPLEOF);
	printf("\nof 1=BOMB, and 0=NO BOMB. Space-delimit your input.");
	printf("\n(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathlength);
	iteration = game.pathlength / PATHISMULTIPLEOF;
	for (i = 1; i <= iteration; i++)
	{
		printf("   Positions [%2d-%2d]: ", (i * 5) - 4, (i * 5));
		scanf("%d %d %d %d %d", &game.bombpos[(i * 5) - 5], &game.bombpos[(i * 5) - 4], &game.bombpos[(i * 5) - 3], &game.bombpos[(i * 5) - 2], &game.bombpos[(i * 5) - 1]);
	}
	printf("BOMB placement set");

	printf("\n\nTREASURE Placement\n------------------");
	printf("\nEnter the treasure placements in sets of %d where a value", PATHISMULTIPLEOF);
	printf("\nof 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.");
	printf("\n(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathlength);
	for (i = 1; i <= iteration; i++)
	{
		printf("   Positions [%2d-%2d]: ", (i * 5) - 4, (i * 5));
		scanf("%d %d %d %d %d", &game.treasurepos[(i * 5) - 5], &game.treasurepos[(i * 5) - 4], &game.treasurepos[(i * 5) - 3], &game.treasurepos[(i * 5) - 2], &game.treasurepos[(i * 5) - 1]);
	}
	printf("TREASURE placement set");
	printf("\n\nGAME configuration set-up is complete...");
	printf("\n\n------------------------------------");
	printf("\nTREASURE HUNT Configuration Settings");
	printf("\n------------------------------------");
	printf("\nPlayer:");
	printf("\n   Symbol     : %c", player.plyricon);
	printf("\n   Lives      : %d", player.livecnt);
	printf("\n   Treasure   : [ready for gameplay]");
	printf("\n   History    : [ready for gameplay]");
	printf("\n\nGame:");
	printf("\n   Path Length: %d", game.pathlength);
	printf("\n   Bombs      : ");
	
	for (i = 0; i < game.pathlength; i++)
	{
		printf("%d", game.bombpos[i]);
	}
	printf("\n   Treasure   : ");
	for (i = 0; i < game.pathlength; i++)
	{
		printf("%d", game.treasurepos[i]);
	}
	printf("\n\n====================================");
	printf("\n~ Get ready to play TREASURE HUNT! ~");
	printf("\n====================================\n\n");
	
	
	printf("  ");
	for (i = 0; i < game.pathlength; i++)
	{
		if (player.PastEntrdPos[i] == 0)
		{
			printf("-");
		}
		if (player.PastEntrdPos[i] == 1)
		{
			printf(".");
		}
		if (player.PastEntrdPos[i] == 2)
		{
			printf("!");
		}
		if (player.PastEntrdPos[i] == 3)
		{
			printf("$");
		}
		if (player.PastEntrdPos[i] == 4)
		{
			printf("&");
		}
	}
	printf("\n");
	printf("  ");

	for (i = 0; i < game.pathlength; i++)
	{
		if ((i + 1) % 10 == 0)
		{
			printf("%d", (i + 1) / 10);
		}
		else
		{
			printf("|");
		}

	}
	printf("\n");
	printf("  ");
	for (i = 0; i < game.pathlength; i++)
	{
		if ((i + 1) % 10 == 0)
		{
			printf("0");
		}
		else
		{
			printf("%d", ((i + 1) % 10));
		}
	}
	printf("\n+---------------------------------------------------+");
	printf("\n  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d", player.livecnt, player.foundtreasercnt, game.maxmoves);
	printf("\n+---------------------------------------------------+\n");
	
	
	flag = -1;
	do
	{
                
		for (i = 0; i < game.pathlength; i++)
		{
			symprint[i] = ' ';
		}
		flag1 = -1;
		do
		{
			printf("Next Move [1-%d]: ",game.pathlength);
			scanf("%d", &nextpos);
			if (nextpos > 0 && nextpos <= game.pathlength)
			{
				flag1 = 0;
				printf("\n");
			}
			else
			{
				printf("  Out of Range!!!\n");
			}
		} while (flag1 != 0);
		symprint[nextpos-1] = player.plyricon;
		if (player.PastEntrdPos[nextpos-1] != 0)
		{
			printf("===============> Dope! You've been here before!");
		}
		else
		{
			if (game.bombpos[nextpos-1] == 0 && game.treasurepos[nextpos-1] == 0)
			{
				player.PastEntrdPos[nextpos-1] = 1;
				game.maxmoves--;
				printf("===============> [.] ...Nothing found here... [.]");
			}
			else if (game.bombpos[nextpos-1] == 1 && game.treasurepos[nextpos-1] == 0)
			{
				player.PastEntrdPos[nextpos-1] = 2;
				game.maxmoves--;
				player.livecnt--;
				printf("===============> [!] !!! BOOOOOM !!! [!]");
			}
			else if (game.bombpos[nextpos-1] == 0 && game.treasurepos[nextpos-1] == 1)
			{
				player.PastEntrdPos[nextpos-1] = 3;
				game.maxmoves--;
				player.foundtreasercnt++;
				printf("===============> [$] $$$ Found Treasure! $$$ [$]");
			}
			else if (game.bombpos[nextpos-1] == 1 && game.treasurepos[nextpos-1] == 1)
			{
				player.PastEntrdPos[nextpos-1] = 4;
				game.maxmoves--;
				player.foundtreasercnt++;
				player.livecnt--;
				printf("===============> [&] !!! BOOOOOM !!! [&]\n===============> [&] $$$ Life Insurance Payout!!! [&]");
			}
		}

                if(player.livecnt == 0)
                {
                   printf("\n\nNo more LIVES remaining!");
                }

		printf("\n\n  ");
		for (i = 0; i < game.pathlength; i++)
		{
			printf("%c", symprint[i]);
                        if(symprint[i] == player.plyricon)
                        break;
		}
		printf("\n");

		printf("  ");
		for (i = 0; i < game.pathlength; i++)
		{
			if (player.PastEntrdPos[i] == 0)
			{
				printf("-");
			}
			if (player.PastEntrdPos[i] == 1)
			{
				printf(".");
			}
			if (player.PastEntrdPos[i] == 2)
			{
				printf("!");
			}
			if (player.PastEntrdPos[i] == 3)
			{
				printf("$");
			}
			if (player.PastEntrdPos[i] == 4)
			{
				printf("&");
			}
		}
		printf("\n");
		printf("  ");
		for (i = 0; i < game.pathlength; i++)
		{
			if ((i + 1) % 10 == 0)
			{
				printf("%d", (i + 1) / 10);
			}
			else
			{
				printf("|");
			}

		}
		printf("\n");
		printf("  ");
		for (i = 0; i < game.pathlength; i++)
		{
			if ((i + 1) % 10 == 0)
			{
				printf("0");
			}
			else
			{
				printf("%d", ((i + 1) % 10));
			}
		}


		printf("\n+---------------------------------------------------+");
		printf("\n  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d", player.livecnt, player.foundtreasercnt, game.maxmoves);
		printf("\n+---------------------------------------------------+\n");

		if (player.livecnt == 0 || game.maxmoves == 0)
		{
			flag = 0;
			printf("\n##################");
			printf("\n#   Game over!   #");
			printf("\n##################");
			printf("\n\nYou should play again and try to beat your score!\n");
		}
	}while (flag != 0);
	
	return 0;
} 



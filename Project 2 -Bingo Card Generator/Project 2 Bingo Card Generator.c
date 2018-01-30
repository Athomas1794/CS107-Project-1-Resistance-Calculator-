/** ---------------------------------------------
* This program generates random bingo cards in accordance
* with official rules. The user inputs the number of players and
* number of cards per player in order to generate the correct amount of cards.
* The cards are generated in a 4-dimensional array, where the first 2 dimensions
* make up a single card, the 3rd identifies the card, and the 4th identifies the player
*
* Class: CS 107, Fall 2017
* System: Dev-C++, Windows 10 *
* @author Alec Thomas
* @version Oct. 15, 2017
* ---------------------------------------------- */ 


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


int main()
{
	//Variable declarations
	int rowNum,colNum,cardNum,playerNum; //Array locations
	int numberOfPlayers, numberOfCards;   //User input for generation
	int bingoCard[5][5][10][5];			///4 dimensional array for all cards
	int randNum = 0;
	int i,j;
	
	rowNum=0; colNum =0; numberOfCards=10; numberOfPlayers =5;
	srand((int)time(0));	//seed
	
	
	//-----------------------------------------------------------------------------------------------------------------
	//Program Prompt
	
	//------------------------------------------------------------
	//TEST CASE 1 - Scanning in number of players and cards
	//
	//Input: A number less than zero. Additionally entering
	//	a number greater than 5.
	//Expected Output: The program re-prompts the user until a 
	//	valid input is recieved
	//Results: For both inputs, the program re-prompts the user
	//	until a desired input is recieved. So the test case worked
	//-------------------------------------------------------------
	
	printf("Enter the number of players (5 player maximum): ");
	scanf("%d", &numberOfPlayers);
	while(numberOfPlayers <= 0 || numberOfPlayers > 5)
	{
		printf("\nNumber of players must be between 1 to 5, please re-enter: ");
		scanf("%d", &numberOfPlayers);
	}
	
	
	printf("\nEnter the number of BINGO cards per player: ");
	scanf("%d", &numberOfCards);
	while(numberOfCards <= 0 || numberOfCards > 10)
	{
		printf("\nNumber of cards must be between 1 to 10, please re-enter: ");
		scanf("%d", &numberOfCards);
	}
	
	
	
	printf("\n\nYou are playing a game with %d players and each player will have %d cards", numberOfPlayers, numberOfCards);
	printf("\nWe have generated %d cards.", (numberOfPlayers*numberOfCards));
	
	//-----------------------------------------------------------------------------------------------------------------
	
	////////////////////////////////////////////////////////////
	//Variables for checking duplicates, and histogram
	int totalElements = numberOfPlayers * numberOfCards * 5 * 5;
	int allValues[totalElements];
	int count = 0;
	///////////////////////////////////////////////////////////
	
	
	
	printf("\n\n");
	//-----------------------------------------------------------------------------------------------------------------
	//Initializing the cards with zeros
	for(playerNum=0; playerNum < numberOfPlayers; playerNum++)
	{
		for(cardNum=0; cardNum < numberOfCards; cardNum++)
		{
			for(rowNum=0; rowNum<5; rowNum++)
			{		
				for(colNum=0; colNum<5; colNum++)
				{
					bingoCard[rowNum][colNum][cardNum][playerNum] = 0;						
				}
			}		
		}
	}
	//-----------------------------------------------------------------------------------------------------------------
	
	
	
	//-----------------------------------------------------------------------------------------------------------------
	//Generating bingo cards for all players
	for(playerNum=0; playerNum < numberOfPlayers; playerNum++)
	{
		for(cardNum=0; cardNum < numberOfCards; cardNum++)
		{
				for(rowNum=0; rowNum<5; rowNum++)
				{
					for(colNum=0; colNum<5; colNum++)
					{
						
						
						//If statement for free space to make it equal to zero
						if((rowNum == 2) && (colNum == 2))	
						{
							bingoCard[rowNum][colNum][cardNum][playerNum] = 0;
						}	
						else{
						
						
						//Random number assigned to a row and column element
						randNum = rand()%15+(15*colNum)+1;
						bingoCard[rowNum][colNum][cardNum][playerNum] = randNum;	
						
						
						//Checking new element value against all others in the card
						//	in order to see if theres a duplicate. If so, the while loop generates
						//	a new card until its valid with no duplicates
						i = 0;
						for(i = rowNum-1; i >=0; i--)
						{
							//Additional for loop to account for unchecked values
							for(j = 0; j<5; j++)
							{
								while(bingoCard[rowNum][colNum][cardNum][playerNum] == bingoCard[i][colNum][cardNum][playerNum])
								{
								    //Re-assigns the duplicate element until its unique for the card
									randNum = rand()%15+(15*colNum)+1;
									bingoCard[rowNum][colNum][cardNum][playerNum] = randNum;
									
								}
							}
						
						}
						
						//Creating array with all card values
						//This array is used for the histogram later
						allValues[count] = bingoCard[rowNum][colNum][cardNum][playerNum];
						count++;
						
						}
						
					}
				
				}
			
		}
	}
	//-----------------------------------------------------------------------------------------------------------------
	
	
	//-----------------------------------------------------------------------------------------------------------------
	
	//Program run loop
	int loop=1;
	int userChoice=0;
	while(loop == 1)
	{
		
		//User option prompt
		printf("\nPlease choose an option from the following menu: \n");
		printf("1) Display a bingo card\n");
		printf("2) Run a histogram across all bingo cards generated\n");
		printf("3) Exit\nEnter your selection: ");
		scanf("%d", &userChoice);
		
		
		//--------------------------------------------------------------------
		//TEST CASE 2 - Scanning in the users choice
		//
		//Input: A character instead of a number for the user choice
		//Expected Output: The program ends because the loop variable isn't
		//	a 1 or 2
		//Results: The program ends, so the test case worked
		//---------------------------------------------------------------------
		
		//---------------------------------------------------------------------
		//TEST CASE 3 - Scanning in the users choice after looping once before
		//
		//Input: A character instead of a number for the user choice
		//Expected Output: The program ends again like the previous test
		//Results: The program enters an infinite loop
		//---------------------------------------------------------------------
		
		
		if(userChoice == 1)
		{
		    printf("\nYou have chosen: 1");
			//Choice 1 prints the card the user wants to see
			printf("\n\nEnter the player and players card you would like to display,\n");
			printf("First player is 1, last player is %d\n", (numberOfPlayers));
			printf("First card is 1, last card is %d\n", (numberOfCards));
			
			int printPlayer, printCard;
			printf("\nEnter the player number: ");
			scanf("%d", &printPlayer);
			
			printf("\nEnter the card number: ");
			scanf("%d", &printCard);
			
			printPlayer--;
			printCard--;
			
			//--------------------------------------------------------------------------
			//TEST CASE 4 - Scanning in the player number and card number to display
			//
			//Input: A character instead of a number for the first prompt
			//Expected Output: The program crashes because the characters integer value
			//	is out of range or invalid
			//Results: The program tries to display the card and crashes, giving a large
			//	player and card number. So the test case was confirmed 
			//--------------------------------------------------------------------------
			
			
			//Printing users chosen card to look at
			printf("Now displaying player %d, card %d---------------------------\n", printPlayer+1, printCard+1);
			
			printf("\nB\tI\tN\tG\tO\n");
			for(rowNum=0; rowNum<5; rowNum++)
			{
				for(colNum=0; colNum<5; colNum++)
				{	
					//if statement for free space exception
					if(bingoCard[rowNum][colNum][printCard][printPlayer] == 0)	
					{
						printf("Free\t");
					}
					else
					{
						printf("%d\t", bingoCard[rowNum][colNum][printCard][printPlayer]);	
					}
					
				}
				printf("\n");			
			}
			printf("\n");		
			
		}//End of choice 1
		
		
		
		else if(userChoice == 2)
		{
			printf("\nYou have chosen: 2");
			
			//loops through all the elements against each number to
			//see how many of each digit appears
			printf("\n");
			int matches = 0;
			for(i = 0; i<75; i++)
			{
				//checking matches for each digit
				matches = 0;
				for(j = 0; j<totalElements; j++)
				{						
   				if(allValues[j] == i+1)
   				{
   					matches++;
   				}
				}
				
				//prints digit and number of occurances
				printf("\t%d-%d", i+1, matches);
				
				
				
				//This section just helps create rows
				if((i+1)%10 == 0)
				{
					printf("\n");
				}
				
			}
			printf("\n\n");
			
			printf("Average is: %lf", (double)totalElements/75.00);								
			
		}//end of choice 2
		
		
		
		else
		{
		   printf("\nYou have chosen: 3");
			//ends program
			loop=0;
			
		}
		
		
	}//end of program loop
	
	printf("\nGoodbye!");
	

	return 0;
}

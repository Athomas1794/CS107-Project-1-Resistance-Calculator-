/** -------------------------------------------------------------------------------------
* This program generates random bingo cards in accordance
* with official rules. The user inputs the number of players and
* number of cards per player in order to generate the correct amount of cards.
* The cards are generated in a 4-dimensional array, where the first 2 dimensions
* make up a single card, the 3rd identifies the card, and the 4th identifies the player
*
* This program is also an extention of the previous project 2, and allows
* us to actually play bingo with inputted bingo calls.
*
* Class: CS 107, Fall 2017
* System: Dev-C++, Windows 10 *
* @author Alec Thomas
* @version Oct. 29, 2017
* ------------------------------------------------------------------------------------ */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

//--------------------------------------------------------------------------------------------------------
//WIN FUNCTIONS
//--------------------------------------------------------------------------------------------------------

//Function to print matching win values with appropriate letters
void PrintWinValues(int valuesArray[5], int arrSize)
{
	int i=0;
	//Prints out matching values
	for(i=0; i<arrSize; i++)
	{
		//If statements to decide which letter to print before the value
		if((valuesArray[i] >= 1) && (valuesArray[i] <= 15))
		{printf("B");}

		else if((valuesArray[i] >= 16) && (valuesArray[i] <= 30))
		{printf("I");}

		else if((valuesArray[i] >= 31) && (valuesArray[i] <= 45))
		{printf("N");}

		else if((valuesArray[i] >= 46) && (valuesArray[i] <= 60))
		{printf("G");}

		else if((valuesArray[i] >= 61) && (valuesArray[i] <= 75))
		{printf("O");}

		printf("%d ", valuesArray[i]);
	}


}

//Function to check for row wins
int RowWinCheck(int cardArray[5][5][10][5], int numPlayers, int numCards, int calledValuesArray[], int numValsCalled)
{

	int rowNum, colNum;
	int playerNum, cardNum;
	int matches, i, j;
	int matchNumbers[5];

	//Nested for's loop by columns
	for(playerNum=0; playerNum < numPlayers; playerNum++)
	{
		for(cardNum=0; cardNum < numCards; cardNum++)
		{
			for(rowNum=0; rowNum<5; rowNum++)
			{
				matches = 0;
				//j defines the number of matches needed
				j = 5;

				for(colNum=0; colNum<5; colNum++)
				{

					//loop to compare the column number against all numbers called
					for(i=0; i<numValsCalled; i++)
					{
						if(cardArray[rowNum][colNum][cardNum][playerNum] == calledValuesArray[i])
						{
							//free space exception
							if(rowNum == 2)
							{
								//j needed in order to account for the free space
								j = 4;
							}

							//Adds the matches values to an array
							matchNumbers[matches] = cardArray[rowNum][colNum][cardNum][playerNum];
							matches++;

						}

						//Winning number of matches condition
						if(matches == j)
						{

							printf("\n\nWe have a winner in row %d of Player %d's, card %d", rowNum+1, playerNum+1, cardNum+1);
							printf("\nWinning numbers were: ");

							//Prints out matching values
							PrintWinValues(matchNumbers, j);
							return 1;
						}
					}

				}
			}
		}
	}
	return 0;

}

//Function to check for column wins
int ColWinCheck(int cardArray[5][5][10][5], int numPlayers, int numCards, int calledValuesArray[], int numValsCalled)
{

	int rowNum, colNum;
	int playerNum, cardNum;
	int matches, i, j;
	int matchNumbers[5];

	//Nested for's loop by rows
	for(playerNum=0; playerNum < numPlayers; playerNum++)
	{
		for(cardNum=0; cardNum < numCards; cardNum++)
		{
			for(colNum=0; colNum<5; colNum++)
			{
				matches = 0;
				//j defines the number of matches needed
				j = 5;

				for(rowNum=0; rowNum<5; rowNum++)
				{

					//loop to compare the column number against all numbers called
					for(i=0; i<numValsCalled; i++)
					{
						if(cardArray[rowNum][colNum][cardNum][playerNum] == calledValuesArray[i])
						{
							//free space exception
							if(colNum == 2)
							{
								//j needed in order to account for the free space
								j = 4;
							}

							//Stores the matched values
							matchNumbers[matches] = cardArray[rowNum][colNum][cardNum][playerNum];
							matches++;

						}

						//Winning number of matches condition
						if(matches == j)
						{

							printf("\n\nWe have a winner in column %d of Player %d's, card %d", colNum+1 ,playerNum+1, cardNum+1);
							printf("\nWinning numbers were: ");

							//prints out matching values
							PrintWinValues(matchNumbers, j);
							return 1;
						}
					}

				}
			}
		}
	}
	return 0;

}

//Diagonal top left to bottom right function win check
int DiagDownRightWin(int cardArray[5][5][10][5], int numPlayers, int numCards, int calledValuesArray[], int numValsCalled)
{

	int rowNum, colNum;
	int playerNum, cardNum;
	int matches, i, j;
	int matchNumbers[4];

	//Nested for's loop by rows
	for(playerNum=0; playerNum < numPlayers; playerNum++)
	{
		for(cardNum=0; cardNum < numCards; cardNum++)
		{
			matches = 0;
			for(i=0; i<numValsCalled; i++)
			{

				//If statements to specifically check the diagonal values
				if(cardArray[0][0][cardNum][playerNum] == calledValuesArray[i])
				{
					//Stores the matched values
					matchNumbers[0] = cardArray[0][0][cardNum][playerNum];
					matches++;

				}
				else if(cardArray[1][1][cardNum][playerNum] == calledValuesArray[i])
				{
					//Stores the matched values
					matchNumbers[1] = cardArray[1][1][cardNum][playerNum];
					matches++;

				}
				else if(cardArray[3][3][cardNum][playerNum] == calledValuesArray[i])
				{
					//Stores the matched values
					matchNumbers[2] = cardArray[3][3][cardNum][playerNum];
					matches++;

				}
				else if(cardArray[4][4][cardNum][playerNum] == calledValuesArray[i])
				{
					//Stores the matched values
					matchNumbers[3] = cardArray[4][4][cardNum][playerNum];
					matches++;

				}


				//Winning number of matches condition
				if(matches == 4)
				{

					printf("\n\nWe have a winner in the top left to bottom right diagonal of Player %d's, card %d", playerNum+1, cardNum+1);
					printf("\nWinning numbers were: ");

					//prints out matching values
					PrintWinValues(matchNumbers, 4);
					return 1;
				}

			}

		}
	}
		return 0;
}

//Diagonal bottom left to top right function win check
int DiagUpRightWin(int cardArray[5][5][10][5], int numPlayers, int numCards, int calledValuesArray[], int numValsCalled)
{

	int rowNum, colNum;
	int playerNum, cardNum;
	int matches, i, j;
	int matchNumbers[4];

	//Nested for's loop by rows
	for(playerNum=0; playerNum < numPlayers; playerNum++)
	{
		for(cardNum=0; cardNum < numCards; cardNum++)
		{
			matches = 0;
			for(i=0; i<numValsCalled; i++)
			{


				if(cardArray[4][0][cardNum][playerNum] == calledValuesArray[i])
				{
					//Stores the matched values
					matchNumbers[0] = cardArray[4][0][cardNum][playerNum];
					matches++;

				}
				else if(cardArray[3][1][cardNum][playerNum] == calledValuesArray[i])
				{
					//Stores the matched values
					matchNumbers[1] = cardArray[3][1][cardNum][playerNum];
					matches++;

				}
				else if(cardArray[1][3][cardNum][playerNum] == calledValuesArray[i])
				{
					//Stores the matched values
					matchNumbers[2] = cardArray[1][3][cardNum][playerNum];
					matches++;

				}
				else if(cardArray[0][4][cardNum][playerNum] == calledValuesArray[i])
				{
					//Stores the matched values
					matchNumbers[3] = cardArray[0][4][cardNum][playerNum];
					matches++;

				}


				//Winning number of matches condition
				if(matches == 4)
				{

					printf("\n\nWe have a winner in the bottom left to top right diagonal of Player %d's, card %d", playerNum+1, cardNum+1);
					printf("\nWinning numbers were: ");

					//prints out matching values
					PrintWinValues(matchNumbers, 4);
					return 1;
				}

			}

		}
	}
		return 0;
}


//Function to check corner wins
int CornerCheckWin(int cardArray[5][5][10][5], int numPlayers, int numCards, int calledValuesArray[], int numValsCalled)
{

	int rowNum, colNum;
	int playerNum, cardNum;
	int matches, i, j;
	int matchNumbers[4];

	//Nested for's loop by rows
	for(playerNum=0; playerNum < numPlayers; playerNum++)
	{
		for(cardNum=0; cardNum < numCards; cardNum++)
		{
			matches = 0;
			for(i=0; i<numValsCalled; i++)
			{

				//If statements to specifically check the corner locations for matches
				if(cardArray[0][0][cardNum][playerNum] == calledValuesArray[i])
				{
					//Stores the matched values
					matchNumbers[0] = cardArray[0][0][cardNum][playerNum];
					matches++;

				}
				else if(cardArray[0][4][cardNum][playerNum] == calledValuesArray[i])
				{
					//Stores the matched values
					matchNumbers[1] = cardArray[0][4][cardNum][playerNum];
					matches++;

				}
				else if(cardArray[4][0][cardNum][playerNum] == calledValuesArray[i])
				{
					//Stores the matched values
					matchNumbers[2] = cardArray[4][0][cardNum][playerNum];
					matches++;

				}
				else if(cardArray[4][4][cardNum][playerNum] == calledValuesArray[i])
				{
					//Stores the matched values
					matchNumbers[3] = cardArray[4][4][cardNum][playerNum];
					matches++;

				}


				//Winning number of matches condition
				if(matches == 4)
				{

					printf("\n\nWe have a winner in the corners of Player %d's, card %d", playerNum+1, cardNum+1);
					printf("\nWinning numbers were: ");

					//prints out matching values
					PrintWinValues(matchNumbers, 4);
					return 1;
				}

			}

		}
	}
		return 0;
}


//Generating bingo cards function
void GeneratingBingoCards(int cardArray[5][5][10][5], int numPlayers, int numCards, int randValues[])
{

	int playerNum, cardNum, rowNum, colNum;
	int randNum;
	int i, j, count;

	//Generating bingo cards for all players
	for(playerNum=0; playerNum < numPlayers; playerNum++)
	{
		for(cardNum=0; cardNum < numCards; cardNum++)
		{
				for(rowNum=0; rowNum<5; rowNum++)
				{
					for(colNum=0; colNum<5; colNum++)
					{


						//If statement for free space to make it equal to zero
						if((rowNum == 2) && (colNum == 2))
						{
							cardArray[rowNum][colNum][cardNum][playerNum] = 0;
						}
						else{

						//Random number assigned to a row and column element
						randNum = rand()%15+(15*colNum)+1;
						cardArray[rowNum][colNum][cardNum][playerNum] = randNum;

						//Checking new element value against all others in the card
						//	in order to see if theres a duplicate. If so, the while loop generates
						//	a new card until its valid with no duplicates
						i = 0;
						if(rowNum != 0)
						{
							//Additional for loop to account for unchecked values
							for(j = 0; j<5; j++)
							{

							for(i = rowNum-1; i >=0; i--)
							{

								while(cardArray[rowNum][colNum][cardNum][playerNum] == cardArray[i][colNum][cardNum][playerNum])
								{

								    //Re-assigns the duplicate element until its unique for the card
									randNum = rand()%15+(15*colNum)+1;
									cardArray[rowNum][colNum][cardNum][playerNum] = randNum;

								}

							}
							}
						}

						//Creating array with all card values
						//This array is used for the histogram later
						randValues[count] = cardArray[rowNum][colNum][cardNum][playerNum];
						count++;

						}

					}

				}

		}
	}



	return;
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//VALID BINGO CARD FUNCTION
//-----------------------------------------------------------------------------------------------------------------
int ValidBingoCall(char letter, int num)
{
	//Checking if called letter is valid
	if( (letter != 'B') && (letter != 'I') && (letter != 'N') && (letter != 'G') && (letter != 'O'))
	{
		printf("\nInvalid call, re-enter");
		return 0;
	}
	//Checking if called letter and called number are valid
	switch(letter){
		case 'B':
			if((num < 1) || (num > 15))
			{
				printf("\nInvalid call, re-enter");
				return 0;
			}
			break;
			case 'I':
				if((num < 16) || (num > 30))
				{
					printf("\nInvalid call, re-enter");
					return 0;
				}
				break;
			case 'N':
				if((num < 31) || (num > 45))
				{
					printf("\nInvalid call, re-enter");
					return 0;
				}
				break;
			case 'G':
				if((num < 46) || (num > 60))
				{
					printf("\nInvalid call, re-enter");
					return 0;
				}
				break;
			case 'O':
				if((num < 61) || (num > 75))
				{
					printf("\nInvalid call, re-enter");
					return 0;
				}
				break;
			default:
				break;
		}
	return 1;

}


//-----------------------------------------------------------------------------------------------------------------
//MAIN
//-----------------------------------------------------------------------------------------------------------------


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
	while( (numberOfCards <= 0) || (numberOfCards > 10) )
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
	//Generating bingo cards
	GeneratingBingoCards(bingoCard, numberOfPlayers, numberOfCards, allValues);
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
		printf("3) Exit\n");
		printf("4) Play Bingo!\n");
		printf("Enter your selection: ");
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



		//CHOICE 4
		else if(userChoice == 4)
		{
			int winCondition = 0;
			char calledLetter;
			int calledNumber;
			int callCount = 0;
			int numCalledArray[10000];

			printf("\n\nYou've chosen to play Bingo!\n");
			//Loop to play bingo and keep
			while (winCondition == 0)
			{
				//--------------------------------------------------------------------------------
				//TEST CASE 5 - Scanning in the called value with a lowercase letter
				//
				//Input: A lowercase letter of b,i,n,g, or o
				//Expected Output: The program accepts this as a valid call because the
				//	"toupper()" function changes the inputted value
				//Results: The program accepts this as a valid call, and repeats the call
				//	with an uppercase letter
				//--------------------------------------------------------------------------------

				//--------------------------------------------------------------------------------
				//TEST CASE 6 - Scanning in the called number with a letter instead
				//
				//Input: A letter instead of a number for the called number
				//Expected Output: The program states this is an invalid input and reprompts
				// the user to input again
				//Results: The program takes the letter in and doesn't accept it as a valid input
				//--------------------------------------------------------------------------------


				printf("\nEnter the called value: ");
				scanf(" %c", &calledLetter);
				scanf(" %d", &calledNumber);
				calledLetter = toupper(calledLetter);	//Changes the scanned letter to an uppercase

				printf("\n\nRead in %c%d", calledLetter, calledNumber);

				//Checking if called letter is valid
				if(ValidBingoCall(calledLetter, calledNumber) == 0)
				{
					continue;
				}

				printf(", marking %c%d on all boards", calledLetter, calledNumber);

				//Called number is added to an array for all called values
				numCalledArray[callCount] = calledNumber;
				callCount++;

				//Calling all win functions to return if anyone won
				winCondition += ColWinCheck(bingoCard, numberOfPlayers, numberOfCards, numCalledArray, callCount);
				winCondition += RowWinCheck(bingoCard, numberOfPlayers, numberOfCards, numCalledArray, callCount);
				winCondition +=	DiagDownRightWin(bingoCard, numberOfPlayers, numberOfCards, numCalledArray, callCount);
				winCondition +=	DiagUpRightWin(bingoCard, numberOfPlayers, numberOfCards, numCalledArray, callCount);
				winCondition +=	CornerCheckWin(bingoCard, numberOfPlayers, numberOfCards, numCalledArray, callCount);

				//------------------------------------------------------------------------------------------
				//TEST CASE 7 - Checking row, columns, and diagonals with free spaces
				//
				//Input: Appropriate winning calls for a row, column, and diagonal win
				//Expected Output: The program states a winner has been found and repeats the winning calls
				//Results: The program found a win for each case, so all 4 functions work
				//------------------------------------------------------------------------------------------

				//------------------------------------------------------------------------------------------
				//TEST CASE 8 - Checking board corners for a win
				//
				//Input: Appropriate winning calls for a corner win
				//Expected Output: The program states a winner has been found and repeats the winning calls
				//Results: The program found a win for the board corners and repeated the winning values
				//------------------------------------------------------------------------------------------


				if(winCondition > 0)
				{
					printf("\n\nThank you for playing! Select option 4 to play again.\n");
				}

			}


		}//End of Choice 4

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

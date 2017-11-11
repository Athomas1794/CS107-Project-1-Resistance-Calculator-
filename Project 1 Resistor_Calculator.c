/*Alec Thomas
  CS107 Theys - thursday 11am lab
  System: Windows 8, Dev C++
  The goal of this program is to calculate the total resistance of a
  circuit given the resistor band code and the type of circuit
 */

#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
	//-------------------------------------------------------------------------------
	//Variable initializations
	char circuitType[15] = "";
	int numResistors = 0;
	char firstBand[15]= "";
	char secondBand[15]= "";
	char thirdBand[15]= "";
	char loop[15] = "Y";
	
	int numBand1 = 0;
	int numBand2 = 0;
	double numBand3 = 0;
	double resistorValue = 0;
	double totalResistance = 0;
	//-------------------------------------------------------------------------------
	
	//-------------------------------------------------------------------------------
	//Loop keeps the program going if the user
	//want to calculate multiple times
	while(strcmp(loop, "Y")==0)
	{		
		
		//-------------------------------------------------------------------------------
		//Program header and following user input
		//-------------------------------------------------------------------------------
		printf("Welcome to the simple resistance calculator\n");
		
		//Asks the user if they want to make a calculation because otherwise
		//zybooks creates an infinite loop and wont submit
		printf("Would you like to make a calculation? (Y/N)");         
		scanf("%c", loop);
		if(strcmp(loop, "N")==0)
		{
			break;
		}
		
		printf("\nAre the resistors in Series or Parallel?: ");
		scanf(" %s", circuitType);
		
		
		//TEST CASE 1: If the user doesn't type series or parallel correctly,
		//then the program asks for another input in the following loop
		//Checking if the circuit type is valid
		int j = 1;
		while(j == 1)
		{	
			if((strcmp(circuitType, "Series")!= 0) && (strcmp(circuitType, "Parallel")!= 0) )
			{
				printf("\n\nPlease enter a valid input (Capitalize first letter of input)");
				scanf(" %s", circuitType);
				//printf("%s", circuitType);
				continue;
			}
			
			j = 0;
		}
		
		
		
		//TEST CASE 2: If the user types in a character instead of an
		//integer for the number of resistors, the program accepts the value
		//and the final total resistance results in a zero
		printf("\n\nHow many resistors are there in the circuit?: ");		
		scanf(" %d", &numResistors);
		//printf("%d", numResistors);l
		
		//FIXME Put in loop to check number of resistors
		
		
		
		printf("\n\nThe first three color bands on the resistors: ");
		scanf(" %s", firstBand);	
		scanf(" %s", secondBand);
		scanf(" %s", thirdBand);
		
		
	
		//printf("\n\n%s %d %s %s %s", circuitType, numResistors, firstBand, secondBand, thirdBand);
		//-------------------------------------------------------------------------------
		
		
		//-------------------------------------------------------------------------------
		//Resistor code calculations
		//-------------------------------------------------------------------------------
		//-------------------------------------------------------------------------------
		//First band
		//-------------------------------------------------------------------------------
		//TEST CASE 3: If the user types in a string that isn't equal to an acceptable 
		//band color, the program re-prompts the user for a correct input
		int i = 1;
		while(i == 1)
		{
		
			if(strcmp(firstBand, "Black")==0)
			{
				numBand1 = 0;
			}
			else if(strcmp(firstBand, "Brown")==0)
			{
				numBand1 = 10;
			}
			else if(strcmp(firstBand, "Red")==0)
			{
				numBand1 = 20;
			}
			else if(strcmp(firstBand, "Orange")==0)
			{
				numBand1 = 30;
			}
			else if(strcmp(firstBand, "Yellow")==0)
			{
				numBand1 = 40;
			}
			else if(strcmp(firstBand, "Green")==0)
			{
				numBand1 = 50;
			}
			else if(strcmp(firstBand, "Blue")==0)
			{
				numBand1 = 60;
			}
			else if(strcmp(firstBand, "Violet")==0)
			{
				numBand1 = 70;
			}
			else if(strcmp(firstBand, "Grey")==0)
			{
				numBand1 = 80;
			}
			else if(strcmp(firstBand, "White")==0)
			{
				numBand1 = 90;
			}
			else
			{
				printf("\n\nPlease re-enter a valid input for band 1 (capitalize first letter): ");
				scanf("%s", firstBand);
				continue;
			}
		
			i = 0;
			//printf("\nnumBand1 = %d", numBand1);
			
		}
		//-------------------------------------------------------------------------------
		
		
		//-------------------------------------------------------------------------------
		//Second band
		//-------------------------------------------------------------------------------
		i = 1;
		while(i == 1)
		{
		
			if(strcmp(secondBand, "Black")==0)
			{
				numBand2 = 0;
			}
			else if(strcmp(secondBand, "Brown")==0)
			{
				numBand2 = 1;
			}
			else if(strcmp(secondBand, "Red")==0)
			{
				numBand2 = 2;
			}
			else if(strcmp(secondBand, "Orange")==0)
			{
				numBand2 = 3;
			}
			else if(strcmp(secondBand, "Yellow")==0)
			{
				numBand2 = 4;
			}
			else if(strcmp(secondBand, "Green")==0)
			{
				numBand2 = 5;
			}
			else if(strcmp(secondBand, "Blue")==0)
			{
				numBand2 = 6;
			}
			else if(strcmp(secondBand, "Violet")==0)
			{
				numBand2 = 7;
			}
			else if(strcmp(secondBand, "Grey")==0)
			{
				numBand2 = 8;
			}
			else if(strcmp(secondBand, "White")==0)
			{
				numBand2 = 9;
			}
			else
			{
				printf("\n\nPlease re-enter a valid input for band 2 (capitalize first letter): ");
				scanf("%s", secondBand);
				continue;
			}
		
			i = 0;
			//printf("\nnumBand2 = %d", numBand2);
			
		}
		//-------------------------------------------------------------------------------
	
		//-------------------------------------------------------------------------------
		//Third band
		//-------------------------------------------------------------------------------
		i = 1;
		while(i == 1)
		{
		
			if(strcmp(thirdBand, "Black")==0)
			{
				numBand3 = 1;
			}
			else if(strcmp(thirdBand, "Brown")==0)
			{
				numBand3 = 10;
			}
			else if(strcmp(thirdBand, "Red")==0)
			{
				numBand3 = 100;
			}
			else if(strcmp(thirdBand, "Orange")==0)
			{
				numBand3 = 1000;
			}
			else if(strcmp(thirdBand, "Yellow")==0)
			{
				numBand3 = 10000;
			}
			else if(strcmp(thirdBand, "Green")==0)
			{
				numBand3 = 100000;
			}
			else if(strcmp(thirdBand, "Blue")==0)
			{
				numBand3 = 1000000;
			}
			else if(strcmp(thirdBand, "Violet")==0)
			{
				numBand3 = 10000000;
			}
			else if(strcmp(thirdBand, "Gold")==0)
			{
				numBand3 = 0.1;
			}
			else if(strcmp(thirdBand, "Silver")==0)
			{
				numBand3 = 0.01;
			}
			else
			{
				printf("\n\nPlease re-enter a valid input for band 3 (capitalize first letter): ");
				scanf("%s", thirdBand);
				continue;
			}
		
			i = 0;
			//printf("\nnumBand3 = %lf", numBand3);
			
		}
		//-------------------------------------------------------------------------------
	
	
		//-------------------------------------------------------------------------------
		//Band combination to get resistor value
		resistorValue = ( (double)(numBand1 + numBand2) ) * numBand3;
		//printf("\n\nResistor value is: %.2lf", resistorValue);
		//-------------------------------------------------------------------------------
		
		
		
		//-------------------------------------------------------------------------------
		//Calculating total resistance based on series or parallel
		//-------------------------------------------------------------------------------
		if(strcmp(circuitType, "Series") == 0)
		{
			totalResistance = (resistorValue * numResistors);
		}
		else if(strcmp(circuitType, "Parallel") == 0)
		{
			totalResistance = pow((double)resistorValue, (double)numResistors) / ((double)resistorValue * (double)numResistors);
		}
		else
		{
			printf("\nSomething wrong with calculating total resistance");
		}
		
		//printf("\n\nTotal Resistance is: %.2lf ohms", totalResistance);
		printf("\n\nEach resistor is %.2lf ohms and the total resistance of the circuit is %.2lf ohms", resistorValue, totalResistance);
		//-------------------------------------------------------------------------------
	
	
	
	
	
		printf("\n\nWould you like to perform another calculation (Y/N)? ");
		scanf(" %c", loop);
		printf("\n\n\n");
	
	}
	
	
	
	return 0;
}

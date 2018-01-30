/*
 Alec Thomas
 Project 4
 Description: This project takes in a filename with a .txt extension, opens the file,
 and scans in all the contents in order of rows, columns, a 2d grid, and list of words.
 The words get placed in a linked list of nodes, and those nodes words are searched for
 in the 2D grid. They can be found in all cardinal directions, and each node has its own
 linked list attached of "struct list" nodes that contain the coordinates of the occurance
 and which way the word progressed. The linked list of occurances are then printed out by
 the program. So this program essentially solves a word search given dimensions, a grid, and
 a list of words.
 
 Class: Theys CS107 - 11AM
 Coded in: OSX High Sierra on XCode
 Last Updated: 12/3/2017
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> //for tolower()




//Holds word and linked list to all occurances
struct node {
    char *word; // a pointer to a dynamic array that holds the word (a dynamic C-string)
    int length; // an int that holds how many characters are in word
    struct list *first; // a pointer to a struct that will hold the index of where the word occurred and in which direction
    struct node *nextword; // a pointer to a struct node that will hold the next word being searched for
};

struct list {
    int row;
    int col;
    int orientation;
    struct list *next; // a pointer to a node of type list that will be the next location of word in puzzle
};

//Function to print all list occurances for one word node
void printLists(struct node *firstLocation)
{
    struct list *printNode = NULL;
    printNode = firstLocation->first;
    
    //If word node doesn't have a list we just exit the function
    if(printNode == NULL)
    {
        return;
    }
    
    //Prints word and then walks the linked list of occurances
    printf("\nWord: %s\n", firstLocation->word);
    
    //while loop goes until there are no more occurances
    while(printNode != NULL)
    {
        //prints one occurance
        printf("Row: %d Col: %d\t", printNode->row, printNode->col);
        
        //Printing direction based on orientation
        if(printNode->orientation == 1)
        {printf("Orientation: N\n");}
        if(printNode->orientation == 2)
        {printf("Orientation: NE\n");}
        if(printNode->orientation == 3)
        {printf("Orientation: E\n");}
        if(printNode->orientation == 4)
        {printf("Orientation: SE\n");}
        if(printNode->orientation == 5)
        {printf("Orientation: S\n");}
        if(printNode->orientation == 6)
        {printf("Orientation: SW\n");}
        if(printNode->orientation == 7)
        {printf("Orientation: W\n");}
        if(printNode->orientation == 8)
        {printf("Orientation: NW\n");}
        
        
        //printNode goes to the next occurance
        printNode = printNode->next;
    }
    return;
}//printLists END


//Check values east when corresponding character is found
//and returns a 1 if the word is found
int checkEast(char *wordStart, char *gridLocation)
{
    int wordLength = (int)strlen(wordStart);
    char *tempGridLocation = gridLocation;
    char *tempWordStart = wordStart;
    int match = 0;
    int i = 0;
    
    //Checks each next word letter and next grid letter for the length of the word
    for(i = 0; i<wordLength; i++)
    {
        if(tolower(*(tempWordStart)) == tolower(*(tempGridLocation)))
        {
            tempWordStart++;
            tempGridLocation++;
            match++;
            if(match == wordLength)
            {
                //Next grid characters match words characters
                //so we return 1 as a confirmation in main
                return 1;
            }
        }
        else
        {
            return 0; //Return
        }
    }
    match = 0;
    return 0;
}//checkEast END

//Check values west when corresponding character is found
//and returns a 1 if the word is found
int checkWest(char *wordStart, char *gridLocation)
{
    int wordLength = (int)strlen(wordStart);
    char *tempGridLocation = gridLocation;
    char *tempWordStart = wordStart;
    int match = 0;
    int i = 0;
    
    //Checks each next word letter and previous grid letter for the length of the word
    for(i = 0; i<wordLength; i++)
    {
        if(tolower(*(tempWordStart)) == tolower(*(tempGridLocation)))
        {
            tempWordStart++;
            tempGridLocation--;
            match++;
            if(match == wordLength)
            {
                //Next grid characters match words characters
                //so we return 1 as a confirmation in main
                return 1;
            }
        }
        else
        {
            return 0; //Return
        }
    }
    match = 0;
    return 0;
}//checkWest END

//Check values south when corresponding character is found
//and returns a 1 if the word is found
int checkSouth(char *wordStart, char *gridLocation, int col)
{
    int wordLength = (int)strlen(wordStart);
    char *tempGridLocation = gridLocation;
    char *tempWordStart = wordStart;
    int match = 0;
    int i = 0;
    
    //Checks each next word letter and next grid letter for the length of the word
    for(i = 0; i<wordLength; i++)
    {
        if(tolower(*(tempWordStart)) == tolower(*(tempGridLocation)))
        {
            tempWordStart++;
            tempGridLocation += col;
            match++;
            if(match == wordLength)
            {
                //Next grid characters match words characters
                //so we return 1 as a confirmation in main
                return 1;
            }
        }
        else
        {
            return 0; //Return
        }
    }
    match = 0;
    return 0;
}//checkSouth END

//Check values north when corresponding character is found
//and returns a 1 if the word is found
int checkNorth(char *wordStart, char *gridLocation, int col)
{
    int wordLength = (int)strlen(wordStart);
    char *tempGridLocation = gridLocation;
    char *tempWordStart = wordStart;
    int match = 0;
    int i = 0;
    
    //Checks each next word letter and next grid letter for the length of the word
    for(i = 0; i<wordLength; i++)
    {
        if(tolower(*(tempWordStart)) == tolower(*(tempGridLocation)))
        {
            tempWordStart++;
            tempGridLocation -= col;
            match++;
            if(match == wordLength)
            {
                //Next grid characters match words characters
                //so we return 1 as a confirmation in main
                return 1;
            }
        }
        else
        {
            return 0; //Return
        }
    }
    match = 0;
    return 0;
}//checkNorth END

//Check values northeast when corresponding character is found
//and returns a 1 if the word is found
int checkNorthEast(char *wordStart, char *gridLocation, int col)
{
    int wordLength = (int)strlen(wordStart);
    char *tempGridLocation = gridLocation;
    char *tempWordStart = wordStart;
    int match = 0;
    int i = 0;
    
    //Checks each next word letter and next grid letter for the length of the word
    for(i = 0; i<wordLength; i++)
    {
        if(tolower(*(tempWordStart)) == tolower(*(tempGridLocation)))
        {
            tempWordStart++;
            tempGridLocation -= col-1;
            match++;
            if(match == wordLength)
            {
                //Next grid characters match words characters
                //so we return 1 as a confirmation in main
                return 1;
            }
        }
        else
        {
            return 0; //Return
        }
    }
    match = 0;
    return 0;
}//checkNorthEast END

//Check values northwest when corresponding character is found
//and returns a 1 if the word is found
int checkNorthWest(char *wordStart, char *gridLocation, int col)
{
    int wordLength = (int)strlen(wordStart);
    char *tempGridLocation = gridLocation;
    char *tempWordStart = wordStart;
    int match = 0;
    int i = 0;
    
    //Checks each next word letter and next grid letter for the length of the word
    for(i = 0; i<wordLength; i++)
    {
        if(tolower(*(tempWordStart)) == tolower(*(tempGridLocation)))
        {
            tempWordStart++;
            tempGridLocation -= col+1;
            match++;
            if(match == wordLength)
            {
                //Next grid characters match words characters
                //so we return 1 as a confirmation in main
                return 1;
            }
        }
        else
        {
            return 0; //Return
        }
    }
    match = 0;
    return 0;
}//checkNorthWest END

//Check values southeast when corresponding character is found
//and returns a 1 if the word is found
int checkSouthEast(char *wordStart, char *gridLocation, int col)
{
    int wordLength = (int)strlen(wordStart);
    char *tempGridLocation = gridLocation;
    char *tempWordStart = wordStart;
    int match = 0;
    int i = 0;
    
    //Checks each next word letter and next grid letter for the length of the word
    for(i = 0; i<wordLength; i++)
    {
        if(tolower(*(tempWordStart)) == tolower(*(tempGridLocation)))
        {
            tempWordStart++;
            tempGridLocation += col+1;
            match++;
            if(match == wordLength)
            {
                //Next grid characters match words characters
                //so we return 1 as a confirmation in main
                return 1;
            }
        }
        else
        {
            return 0; //Return
        }
    }
    match = 0;
    return 0;
}//checkSouthEast END

//Check values southwest when corresponding character is found
//and returns a 1 if the word is found
int checkSouthWest(char *wordStart, char *gridLocation, int col)
{
    int wordLength = (int)strlen(wordStart);
    char *tempGridLocation = gridLocation;
    char *tempWordStart = wordStart;
    int match = 0;
    int i = 0;
    
    //Checks each next word letter and next grid letter for the length of the word
    for(i = 0; i<wordLength; i++)
    {
        if(tolower(*(tempWordStart)) == tolower(*(tempGridLocation)))
        {
            tempWordStart++;
            tempGridLocation += col-1;
            match++;
            if(match == wordLength)
            {
                //Next grid characters match words characters
                //so we return 1 as a confirmation in main
                return 1;
            }
        }
        else
        {
            return 0; //Return
        }
    }
    match = 0;
    return 0;
}//checkSouthWest END



//Function to print words, length, and next word from nodes (node linked list)
void printWords(struct node *firstNode)
{
    struct node *printNode = NULL;
    int count = 1;
    printNode = firstNode;
    while(printNode != NULL)
    {
        printf("Word %d: %s\n", count, printNode->word);
        printf("Length: %d\n", printNode->length);
        if(printNode->nextword != NULL)
        {
            printf("Next Word: %s\n\n", printNode->nextword->word);
        }
        count++;
        printNode = printNode->nextword;
    }
}


int main()
{
    
    int row = 0;
    int col = 0;
    int i, j;
    int count;
    int gridLength;
    char *filename = malloc(100*sizeof(char)); //mallocing a filename up to size 100 chars
    FILE *inFile = NULL; //File pointer
    
    //Scanning in the filename to access
    printf("Enter the filename that holds the word search information (end name with .txt extension): ");
    scanf("%s", filename);
    //printf("\n%s", filename);
    
    //--------------------------------------------------------------------------------------------
    //TEST CASE 1: Incorrect filename input
    //Input: "samplefile"
    //Expected output: "Could not open file" because the input needs to include ".txt" at the end
    //Output: "Could not open file"
    //--------------------------------------------------------------------------------------------
    
    //--------------------------------------------------------------------------------------------
    //TEST CASE 2: Running the project without samplefile.txt in the same directory as the executable
    //Input: "samplefile.txt"
    //Expected output: "Could not open file" because the file is not in the same folder as the exe
    //Output: "Could not open file"
    //--------------------------------------------------------------------------------------------
    
    //Opening file for input
    inFile = fopen(filename, "r");
    if(inFile == NULL)
    {
        printf("\nCould not open file\n");
        return -1;
    }
    //printf("\nFILE OPENED\n");
    
    //---------------------------------------------------------------------------------------------------------------
    //GRID ALLOCATING AND SCANNING FROM FILE (Rows, Columns, and the grid)
    //---------------------------------------------------------------------------------------------------------------
    //Scanning in the row and col variables
    fscanf(inFile, "%d %d", &row, &col);
    
    //Allocating space for grid of chars
    char *inputGrid = malloc(row * col * sizeof(char));
    char *tempGridBeginning = inputGrid;
    count = 0;
    //printf("Grid allocated\n");
    
    //Scanning letters into dynamic allocated grid
    gridLength = 0;
    for(i = 0; i<row; i++)
    {
        for(j = 0; j<col; j++)
        {
            fscanf(inFile, " %c", (inputGrid)); //Putting character into the grid array
            inputGrid++;
            gridLength++;
            count++;
        }
    }
    inputGrid = tempGridBeginning;
    
    //prints dynamic grid (commented out for viewing just occurances)
    /*printf("\nCount: %d\n", count);
     for(i = 0; i<row; i++)
     {
     for(j = 0; j<col; j++)
     {
     printf("%c", *(inputGrid));
     inputGrid++;
     count++;
     }
     }
     inputGrid = tempGridBeginning;*/
    
    //printf("\nGrid populated\n");
    count = 0;
    
    //---------------------------------------------------------------------------------------------------------------
    //END --- GRID ALLOCATING AND SCANNING FROM FILE
    //---------------------------------------------------------------------------------------------------------------
    
    //---------------------------------------------------------------------------------------------------------------
    //START --- POPULATING NODES (Scanning the words into nodes)
    //---------------------------------------------------------------------------------------------------------------
    
    struct node *headNode = NULL; //First node in the word linked list
    struct node *tempNode = NULL; //temp node creates new nodes to be added
    struct node *prevNode = NULL; //prevNode is for linking the previous nodes nextword to new node
    
    count = 0;
    while(!feof(inFile))
    {
        tempNode = (struct node*)malloc(sizeof(struct node)); //malloc new node pointer
        tempNode->word = (char*)malloc(sizeof(char) * 100); //malloc size for nodes word
        fscanf(inFile, " %s", tempNode->word);
        tempNode->nextword = NULL;
        tempNode->length = (int)strlen(tempNode->word);
        tempNode->first = NULL;
        // printf("Word scanned: %s\n", tempNode->word);
        // printf("Word scanned length: %d\n", tempNode->length);
        
        
        if(headNode == NULL) //first node case
        {
            headNode = tempNode;
        }
        else
        {
            //Adding new node to the end of the list by
            //looking for the previous node and connecting it
            //with nextword to the new node
            prevNode = headNode;
            while(prevNode->nextword != NULL)
            {
                prevNode = prevNode->nextword;
            }
            prevNode->nextword = tempNode;
        }
        
        count++; //increment # of words
    }
    //printf("\n");
    
    //---------------------------------------------------------------------------------------------------------------
    //END --- POPULATING NODES
    //---------------------------------------------------------------------------------------------------------------
    
    /* This code will print out all the word nodes found in the file after the grid
     printf("\n---------------------------------------------------\nWORDS FOUND IN FILE\n");
     printWords(headNode); //printing each node
     printf("\n\n");
     */
    
    //---------------------------------------------------------------------------------------------------------------
    //START --- SEARCHING FOR WORDS AND POPULATING LISTS
    //---------------------------------------------------------------------------------------------------------------
    //printf("\n---------------------------------------------------\nFINDING WORDS\n");
    int i_grid = 0; //keeps track of where I am in the grid
    int rowLoc, colLoc; //location where the word is found
    int east = 0;
    int west = 0;
    int south = 0;
    int north = 0;
    int northeast = 0;
    int northwest = 0;
    int southeast = 0;
    int southwest = 0;
    
    char *tempGrid = inputGrid;
    struct list *prevListNode = NULL;
    struct node *currentNode = headNode;
    struct list *tempListNode =NULL;
    
    //CHECKING THROUGH ALL NODES IN GRID
    while(currentNode != NULL)
    {
        i_grid = 0; //keeps track of where I am in the grid
        count=0;
        tempGrid = inputGrid;
        
        
        //Going through every character in the grid and checking for the nodes word in each direction
        while(i_grid < gridLength)
        {
            
            //Checking east and adding lists---------------------------------------------------------------------------------
            east = 0;
            east = checkEast(currentNode->word, inputGrid);
            if(east == 1)
            {
                rowLoc = i_grid/col;
                colLoc = i_grid%col;
                //printf("%s FOUND EAST at i_grid: %d row: %d col:%d\n", currentNode->word, i_grid, rowLoc, colLoc);
                tempListNode = (struct list*)malloc(sizeof(struct list)*10); //malloc new node pointer
                tempListNode->row = rowLoc;
                tempListNode->col = colLoc;
                tempListNode->orientation = 3;
                tempListNode->next = NULL;
                
                if(currentNode->first == NULL)
                {
                    currentNode->first = tempListNode;
                    count++;
                }
                else
                {
                    prevListNode = currentNode->first;
                    while((prevListNode->next) != NULL)
                    {
                        prevListNode = prevListNode->next;
                    }
                    prevListNode->next = tempListNode;
                    //prevNode->next = NULL;
                    //printf("ADDED NEW LOCATION\n");
                }
            }
            east = 0;
            //END OF Checking east and adding lists--------------------------------------------------------------------------
            
            
            //Checking west and adding lists---------------------------------------------------------------------------------
            west = 0;
            west = checkWest(currentNode->word, inputGrid);
            if(west == 1)
            {
                rowLoc = i_grid/col;
                colLoc = i_grid%col;
                //printf("%s FOUND WEST at i_grid: %d row: %d col:%d\n", currentNode->word, i_grid, rowLoc, colLoc);
                tempListNode = (struct list*)malloc(sizeof(struct list)*10); //malloc new node pointer
                tempListNode->row = rowLoc;
                tempListNode->col = colLoc;
                tempListNode->orientation = 7;
                tempListNode->next = NULL;
                
                if(currentNode->first == NULL)
                {
                    currentNode->first = tempListNode;
                    count++;
                }
                else
                {
                    prevListNode = currentNode->first;
                    while((prevListNode->next) != NULL)
                    {
                        prevListNode = prevListNode->next;
                    }
                    prevListNode->next = tempListNode;
                    //prevNode->next = NULL;
                    //printf("ADDED NEW LOCATION\n");
                }
            }
            west = 0;
            //END OF Checking west and adding lists-------------------------------------------------------------------------
            
            
            //Checking south and adding lists---------------------------------------------------------------------------------
            south = 0;
            south = checkSouth(currentNode->word, inputGrid, col);
            if(south == 1)
            {
                rowLoc = i_grid/col;
                colLoc = i_grid%col;
                //printf("%s FOUND SOUTH at i_grid: %d row: %d col:%d\n", currentNode->word, i_grid, rowLoc, colLoc);
                tempListNode = (struct list*)malloc(sizeof(struct list)*10); //malloc new node pointer
                tempListNode->row = rowLoc;
                tempListNode->col = colLoc;
                tempListNode->orientation = 5;
                tempListNode->next = NULL;
                
                if(currentNode->first == NULL)
                {
                    currentNode->first = tempListNode;
                    count++;
                }
                else
                {
                    prevListNode = currentNode->first;
                    while((prevListNode->next) != NULL)
                    {
                        prevListNode = prevListNode->next;
                    }
                    prevListNode->next = tempListNode;
                    //prevNode->next = NULL;
                    //printf("ADDED NEW LOCATION\n");
                }
            }
            south = 0;
            //END OF Checking south and adding lists--------------------------------------------------------------------------
            
            
            //Checking North and adding lists---------------------------------------------------------------------------------
            north = 0;
            north = checkNorth(currentNode->word, inputGrid, col);
            if(north == 1)
            {
                rowLoc = i_grid/col;
                colLoc = i_grid%col;
                //printf("%s FOUND NORTH at i_grid: %d row: %d col:%d\n", currentNode->word, i_grid, rowLoc, colLoc);
                tempListNode = (struct list*)malloc(sizeof(struct list)*10); //malloc new node pointer
                tempListNode->row = rowLoc;
                tempListNode->col = colLoc;
                tempListNode->orientation = 1;
                tempListNode->next = NULL;
                
                if(currentNode->first == NULL)
                {
                    currentNode->first = tempListNode;
                    count++;
                }
                else
                {
                    prevListNode = currentNode->first;
                    while((prevListNode->next) != NULL)
                    {
                        prevListNode = prevListNode->next;
                    }
                    prevListNode->next = tempListNode;
                    //prevNode->next = NULL;
                    //printf("ADDED NEW LOCATION\n");
                }
            }
            north = 0;
            //END OF Checking north and adding lists--------------------------------------------------------------------------
            
            
            //Checking Northeast and adding lists---------------------------------------------------------------------------------
            northeast = 0;
            northeast = checkNorthEast(currentNode->word, inputGrid, col);
            if(northeast == 1)
            {
                rowLoc = i_grid/col;
                colLoc = i_grid%col;
                //printf("%s FOUND NORTHEAST at i_grid: %d row: %d col:%d\n", currentNode->word, i_grid, rowLoc, colLoc);
                tempListNode = (struct list*)malloc(sizeof(struct list)*10); //malloc new node pointer
                tempListNode->row = rowLoc;
                tempListNode->col = colLoc;
                tempListNode->orientation = 2;
                tempListNode->next = NULL;
                
                if(currentNode->first == NULL)
                {
                    currentNode->first = tempListNode;
                    count++;
                }
                else
                {
                    prevListNode = currentNode->first;
                    while((prevListNode->next) != NULL)
                    {
                        prevListNode = prevListNode->next;
                    }
                    prevListNode->next = tempListNode;
                    //prevNode->next = NULL;
                    //printf("ADDED NEW LOCATION\n");
                }
            }
            northeast = 0;
            //END OF Checking northeast and adding lists--------------------------------------------------------------------------
            
            
            //Checking Northwest and adding lists---------------------------------------------------------------------------------
            northwest = 0;
            northwest = checkNorthWest(currentNode->word, inputGrid, col);
            if(northwest == 1)
            {
                rowLoc = i_grid/col;
                colLoc = i_grid%col;
                //printf("%s FOUND NORTHWEST at i_grid: %d row: %d col:%d\n", currentNode->word, i_grid, rowLoc, colLoc);
                tempListNode = (struct list*)malloc(sizeof(struct list)*10); //malloc new node pointer
                tempListNode->row = rowLoc;
                tempListNode->col = colLoc;
                tempListNode->orientation = 8;
                tempListNode->next = NULL;
                
                if(currentNode->first == NULL)
                {
                    currentNode->first = tempListNode;
                    count++;
                }
                else
                {
                    prevListNode = currentNode->first;
                    while((prevListNode->next) != NULL)
                    {
                        prevListNode = prevListNode->next;
                    }
                    prevListNode->next = tempListNode;
                    //prevNode->next = NULL;
                    //printf("ADDED NEW LOCATION\n");
                }
            }
            northwest = 0;
            //END OF Checking northwest and added lists--------------------------------------------------------------------------
            
            
            //Checking SouthEast and adding lists---------------------------------------------------------------------------------
            southeast = 0;
            southeast = checkSouthEast(currentNode->word, inputGrid, col);
            if(southeast == 1)
            {
                rowLoc = i_grid/col;
                colLoc = i_grid%col;
                //printf("%s FOUND SOUTHEAST at i_grid: %d row: %d col:%d\n", currentNode->word, i_grid, rowLoc, colLoc);
                tempListNode = (struct list*)malloc(sizeof(struct list)*10); //malloc new node pointer
                tempListNode->row = rowLoc;
                tempListNode->col = colLoc;
                tempListNode->orientation = 4;
                tempListNode->next = NULL;
                
                if(currentNode->first == NULL)
                {
                    currentNode->first = tempListNode;
                    count++;
                }
                else
                {
                    prevListNode = currentNode->first;
                    while((prevListNode->next) != NULL)
                    {
                        prevListNode = prevListNode->next;
                    }
                    prevListNode->next = tempListNode;
                    //prevNode->next = NULL;
                    //printf("ADDED NEW LOCATION\n");
                }
            }
            southeast = 0;
            //END OF Checking southeast and adding lists--------------------------------------------------------------------------
            
            
            //Checking Southwest and adding lists---------------------------------------------------------------------------------
            southwest = 0;
            southwest = checkSouthWest(currentNode->word, inputGrid, col);
            if(southwest == 1)
            {
                rowLoc = i_grid/col;
                colLoc = i_grid%col;
                //printf("%s FOUND SOUTHWEST at i_grid: %d row: %d col:%d\n", currentNode->word, i_grid, rowLoc, colLoc);
                tempListNode = (struct list*)malloc(sizeof(struct list)*10); //malloc new node pointer
                tempListNode->row = rowLoc;
                tempListNode->col = colLoc;
                tempListNode->orientation = 6;
                tempListNode->next = NULL;
                
                if(currentNode->first == NULL)
                {
                    currentNode->first = tempListNode;
                    count++;
                }
                else
                {
                    prevListNode = currentNode->first;
                    while((prevListNode->next) != NULL)
                    {
                        prevListNode = prevListNode->next;
                    }
                    prevListNode->next = tempListNode;
                    //prevNode->next = NULL;
                    //printf("ADDED NEW LOCATION\n");
                }
            }
            southwest = 0;
            //END OF Checking southwest and added lists--------------------------------------------------------------------------
            
            
            count++;
            inputGrid++;
            i_grid++;
        }
        inputGrid = tempGrid;
        
        
        currentNode = currentNode->nextword;
    }
    
    //Going through each word node and printing out their
    //connected linked lists of occurances in the grid (found words)
    printf("--------------------------------------------\nWORDS FOUND IN GRID (coordinates start from 0)\n");
    currentNode = headNode;
    while(currentNode != NULL)
    {
        printLists(currentNode);
        currentNode = currentNode->nextword;
    }
    
    
    //---------------------------------------------------------------------------------------------------------------
    //END --- SEARCHING FOR WORDS AND POPULATING LISTS
    //---------------------------------------------------------------------------------------------------------------
    
    
    fclose(inFile); //closes file
    
    
    return 0;
}



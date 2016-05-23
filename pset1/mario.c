/*
    The Emperor of the Republic/Kalika Kay
    CS50 Assignment #3 Mario.C
    
    Prompt user for a number used to generate a pyramid.
    - Positive Integer.
    - less than or equal to 23.
    - Retry if user enters incorrect number.
    
    On valid input, 
    - display a half-pyramid using hashes as blocks.
    - bottom left corner aligns with left edge of terminal.
    - right colum hashes make a straight line.
        
*/

#include <cs50.h>
#include <string.h>
#include <stdio.h>

int PromptInt(char *prompt);
void Pounding(int length);
void Sense(int length);

int main(void)
{
    //Feeling loopy? Initialize to zero and prompt until a valid size is entering.
    int size = 0;
    
    size = PromptInt("Enter the size of 'your pyramid': ");
    
    while (size < 0 || size > 23)
    {
        
       printf("\nTry Again. ");
       if (size < 0)
       {
           size = PromptInt("Stay Positive! ");
       } 
       else 
       {
           size = PromptInt("You're not under 24?!? ");
       }
        
    }
    
    //Show some senseless pounding.
    for(int i = 1; i <= size; i++)
    {
        int less = size - i;
        Sense(less);
        Pounding(i);
        printf("\n");
    }
  
    
}

//Same as get_int, but provides the string prompt.
int PromptInt(char *prompt)
{
    printf("%s", prompt);
    return GetInt();
}

//Gives a pounding, just tell me how long you want it.
void Pounding(int length)
{
    //I can't help myself - gotta use a string variable; 
    char *pound;
    pound = (char *) malloc(length + 2);
    
    //Pounding
    pound = strcpy(pound, "#");
    for(int i = length; i > 0; i--)
    {
       strncat(pound, "#", i);
    }
    
    printf("%s", pound);
    free(pound);
    
}

//All the space, for as long as you like. 
void Sense(int length)
{
    for(int i = 1; i <= length; i++)
    {
     printf(" ");
    }
   
}
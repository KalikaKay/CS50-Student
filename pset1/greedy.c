/*
    The Emperor of the Republic/Kalika Kay
    CS50 Assignment #4 greed.c
    
    1.) Ask user for amount change owed.
        - use cs50 getfloat for input.
        - prompt for positivity.
        - assume the end user will give dollars :( Not as fun, but whatever.
        - consider using round to avoid imprecision.
    2.) Provide Minimum number of coins for change.
        - use printf for output.
        - printout an integer followed by newline only.
        - round and modulus might come in handy.
    3.) Walkthrough says to keep track of the coins I'm using.
    
    Only change available:
    Quarters = 0.25
    Dimes = 0.10 = 
    Nickels = 0.05 
    Pennies = 0.01
    Use cents (multiply by a hundred)    
*/

#include <stdio.h>
#include <cs50.h>
#include <math.h>


int PromptFl(char *prompt);
int MakeCents(float dollars);
void showHand(int coinCointainer[]);

int main(void)
{
    
    int getIt = PromptFl("Hey, Dolla. Whatchoo owe? ");
    
    while(getIt < 0)
    {
        getIt = PromptFl("Lolz, what? That's not a given! ");
    }
    
    //Sometimes I'm easy.
    if (getIt == 0)
    {
        printf("%d\n", 0);
    } 
    else 
    {
        //I want to remember what I got; so I'm changing.
        int change = getIt;
       
        
        //Feeling lazy - coinHolder is an array holding each type of coin. 
        //changeHand is what I've got in my hand; we'll pretend my hands are big enough to group them.
        //[0] = quarter, [1] = dime, [2] = nickel, [3] = penny.
        int coinHolder[] = {25, 10, 5, 1};
        int changeHand[] = {0, 0, 0, 0};
        int coinCount = 0;
        
        //loop through the coin holder
        for (int i = 0; i < 4; i++)
        { 
            
            changeHand[i] = change / coinHolder[i];
            
            coinCount += changeHand[i];
            change = change % coinHolder[i];
           
        }
        
        //Used to verify coins dispensed.
        //showHand(changeHand);
        
       printf("%d\n", coinCount);
   
    }
}

/*
    Prompt the user until they enter float.
    Returns an integer.
    Because well - I'm always going to make cents out of these user inputs.
*/
int PromptFl(char *prompt)
{
    printf("%s", prompt);
    return MakeCents(GetFloat() * 100);
    
}

/* Had to do it rounds the dollars to cents */
int MakeCents(float dollars)
{
    return round(dollars);
}

/* 
    created for err checking and fun. Displays the coins you've got in your hand.
    assumes you're looping through the coin holder. 
*/

void showHand(int coinContainer[])
{   
    char *coinNames[] = {"Quarters:", "Dimes:", "Nickels:", "Pennies:"};
    
    for (int i = 0; i < 4; i++)
    {
        printf("%s %d ", coinNames[i], coinContainer[i]);
    }
    printf("\n");
    //free(coinNames);
}
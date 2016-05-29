/*
    The Emperor of the Republic/Kalika Kay
    CS50 Pset2 Assignment #2 caesar.c
   Structions:
   1.) Accept a single command line artument
   2.) Argument is a non-negative integer.
   3.) return 1 if the user enters too many or too few arguments. 
   4.) otherwise prompt for a string of plain text
   5.) output that text with each alphatical char rotated by k positions.
   6.) non alphabets will remain unchanged.
   7.) after outputting the cipher, exit. return 0.
   8.) don't worry about the int size. 
   9.) if value is greater than 26, (e.g. 27) 
       use modulo to determine alphabet cipher
   10.) Preserve case.
   
   Notations:
   More ASCIIs
    Captial Letters in ASCII = 65-90
    Lower Case Letters in ASCII = 97-122
    Convert from lower to upper by minus 32
    Space is 32
*/

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[ ])
{
    //for my one and only. 
    if (argc == 2)
    {
        
        int key = atoi(argv[1]);
        
        //prepare for the well endowed.
        if (key >= 26)
        {
            key = key % 26;  
        }
       
        //printf("What are you insinuating? ");
        string desire = GetString();
        
        
        //as you wish.
        if (key == 0)
        {   
            printf("%s", desire);
            return 0;
        }
        
        //stay positive.
        if (key >= 0) 
        {
            
            //let's take care of that, shall we?
            int length = strlen(desire);
            string satisfaction = desire;
            int asciing, keyring;
            
            
            for (int i = length - 1; i >= 0; i--) 
            {
                asciing = (int) desire[i];
        
                    
                //Requirements for satisfaction.
                if ( (asciing >= 65 && asciing <= 90) || (asciing >= 97 && asciing <= 122) )
                {
                    keyring = (char) key + asciing;
                    
                    //lower or upper 
                    if (asciing < 90) 
                    {
                      //queue the keyring
                      if (keyring > 90)
                      {
                        keyring = keyring - 26;    
                      }
                      
                    } else {
                        
                      //queue the keyring
                      if (keyring > 122)
                      {
                          keyring = keyring - 26;
                      }
                    }
                    
                    //calculate satisfaction.
                    satisfaction[i] = keyring;
                    
                
                } else {
                    
                    //What is desired.
                    satisfaction[i] = desire[i];
                }
        
            }
            
            //satisfaction guaranteed.
            printf("%s\n", satisfaction);
            return 0;    
       
        } else {
            
            printf("You're not getting anywhere with that negativity.\n");
            return 1;
        }
        
    } else {
        
        printf("I want one!\n");
        return 1;
    
    }
}

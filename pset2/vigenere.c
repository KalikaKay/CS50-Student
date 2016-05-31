/*
    The Emperor of the Republic/Kalika Kay
    CS50 Pset2 Assignment #3 I call it v something.c
   Structions:
        Take an argument.
        If you can't argue with me, then you can't have me.
        The argument must an array of characters between ASCII 65-90 or 97 and 122.
        Plain Text prompting if not; then provide an error. 
        with regards to the argument; all letters are ASCII 97-122 (Lower case). User can use capslock; i get to turn them down.
        symbols are repeated back to the end user.
        The message case is preserved. 
   
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
#include <ctype.h>

bool ltr(string key);
char lower(int a);

int main(int argc, string argv[ ])
{
    //for my one and only. 
    if (argc == 2)
    {
        //letters only
        if (ltr(argv[1]) == 1)
        {
            
            string keyset = argv[1];
            string desire = GetString();
            
            //let's take care of that, shall we?
            int length = strlen(desire);
            string satisfaction = desire;
            int asciing, keyring, to, unlock, wanting;
            
             //Thing about a set of keys, owner knows where the key goes.
            to = 0;
            wanting = 0;
            
            //loop through all the characters.
            for (int i = 0; i <= length - 1; i++) 
            {
                asciing = (int) desire[i];
                
                //Requirements for satisfaction.
                if ( (asciing >= 65 && asciing <= 90) || (asciing >= 97 && asciing <= 122) )
                {
                   
                    to =  wanting % strlen(keyset);
                    unlock = (int) keyset[to];
                    
                    //key is lowercase only.
                    keyring = asciing + ((int) lower(unlock) - 97);
                    
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
                    satisfaction[i] = (char) keyring;
                    wanting++;
            
                } else {
                    
                    //What is desired.
                    satisfaction[i] = desire[i];
                }
        
            }
            
            //satisfaction guaranteed.
            printf("%s\n", satisfaction);
            return 0;    
       
        } else {
            
            printf("The key is letters only.\n");
            return 1;
        }
        
    } else {
        
        printf("I want one!\n");
        return 1;
    
    }
}

/*
returns 0 if the string contains only letters of the alphabet.
returns 1 if it does not.
*/
bool ltr (string key) 
{
    
    int turnkey =  (int) key[0];
    
    for (int i = 0; i <= strlen(key) - 1; i++) 
    {
        
        turnkey = (int) key[i];
                
        if ((turnkey >= 65 && turnkey <= 90) || (turnkey >= 97 && turnkey <= 122)) 
        {
            
        } else {
            return 0;
        }

    }
    
    return 1;
}


/*
return a lowercase letter. assumes is alpha; takes integer representation of a character.
*/
char lower (int a) 
{
    int ascii32 = (int) a;
    
    if (ascii32 <= 90) 
    {
        ascii32 = a + 32;
    }
    
    return (char) ascii32;
}
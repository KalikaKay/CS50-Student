/*
    The Emperor of the Republic/Kalika Kay
    CS50 Pset2 Assignment #1 initials.c
   Structions:
   1.) prompt the user for their name.
   2.) Use getstring.
   3.) Output initials
    a.) capitals
    b.) no spaces or periods
    c.) end with newline.
    d.) that's it
   4.) No escape sequences required (that is - don't gotta worry about the 'nomalies)
  
  Notations:
  Make it ASCII 32    
    Captial Letters in ASCII = 65-90
    Lower Case Letters in ASCII = 97-122
    Convert from lower to upper by minus 32
    Space is 32
*/


#include <cs50.h>
#include <stdio.h>
#include <string.h>

bool Charm (char a, char b);
char Char_Up (char a);

int main(void)
{
   
   string chars;
   int length = 0;
   char space = (char) 32;
 
    //I'm not asking.
     chars = GetString();
     length = strlen(chars);    
        

      
    //initial thought process.
    int initial_length = 0;
    
    //if charmed, inflate. 
    for (int i = length - 1; i > 0; i--) 
    {
        if (Charm(chars[i], space) == 1)
        {
            initial_length++;
        }
    }
  
    //dedicate some memory.
    char *initials;
    initials = (char *) malloc(initial_length + 2);
    
    //if charmed, char_up, deflate.   
    for (int i = length - 1; i > 0; i--) 
    {
       if (Charm(chars[i], space) == 1) 
       {
           initials[initial_length] = Char_Up(chars[i + 1]);
           initial_length--;
        }
    }
    
    //finish off.
    initials[initial_length] = Char_Up(chars[initial_length]);
    
    printf("%s\n", initials);
    free(initials);
}

/*
Take two characters.
return 1 if they match.
return 0 if they do not.
Case sensitive.
*/
bool Charm (char a, char b) 
{
    if ((int) a == (int) b) 
    {
        return 1;
    } else {
        return 0;
    }
}

/*
Take a character 
Make it large.
*/
char Char_Up (char a) 
{
    int ascii32 = (int) a;
    
    if (ascii32 >= 97) 
    {
        ascii32 = a - 32;
    }
    
    return (char) ascii32;
}
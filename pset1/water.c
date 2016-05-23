/*
    Kalika Kay Curry
    CS50 Exercise - PSET1 water.c
    
    Requirements:
    1.) Prompt user for minutes in shower.
    2.) User inputs a positive integer, minutes.
        a.) assume user follows instructions: no error checking.
        b.) assume user enters an integer: no overflow checking.
    3.) Outputs number of bottles of water used.
        a.) Shower spits out 1.5 gallons of water per minute.
        b.) = 192 ounces of water per minute.
        c.) = 12 bottles of water per minute. 
        d.) BottlesofWater = (12)(showerMins)
*/

#include <cs50.h>
#include <stdio.h>
#include <math.h>


int WaterBottles(int mins);
int main(void){
    
        
        printf("Enter the number of minutes in the shower: ");
        int showerMins = GetInt();
        printf("That's about %i bottles of water! \n", WaterBottles(showerMins));
        
        
}

//Function returns the number of water bottles used as an integer.
int WaterBottles(int mins)
{
    
    return mins * 12;
    
}

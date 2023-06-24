#include <stdlib.h>
#include <stdio.h>
#include "dicegame.h"


int getRandomNumber (int min, int max){
    return rand() % (max - min + 1) + min; // Range of possible values from 1 to 6 inclusive (not 0)

}
// This function decides the type of the round based on the probability values mentioned in game rules 
//(20% for BONUS, 30% for DOUBLE and 50% for REGULAR). 
//HINT: Use the getRandomNumber() function to generate a random number between 0 through 9 and use this value for probability. 

ROUNDTYPE getRoundType(){
    int randomNum = getRandomNumber(0, 9); // min = 0, max = 9
    if(randomNum < 2){ // 0 to 1 has a 20% probability of occuring 
        return BONUS;
    }
    else if(randomNum > 2 && randomNum < 5 ){ // 2-4 represent a 30% prob of occuring 
        return DOUBLE;
    }
    else{
        return REGULAR; // the remaining 50% probability (5-9).
    }
}

//This function calculates and return the points associated with the given round type, based on the rules mentioned above. 
//You will need to call the getRandomNumber() function to generate the points randomly. 


// Points – value associated with the round. It is a random number from 10-100 in multiples of 10. (10 * random number between 1-10).
// Type – the type of the round. There are 3 types of rounds:
// REGULAR – keep the “points” equal to the number of points as calculated above using a random number generator.
// BONUS – replace “points” to be equal to 200.
// DOUBLE – update “points” to be equal to DOUBLE the number of points as calculated above using a random number generator.
// Probability of the round types:
// 20% for BONUS, 30% for DOUBLE and 50% for REGULAR

int getRoundPoints(ROUNDTYPE roundType) { // CHECK THE POINTS calculation
        int randomNum1 = getRandomNumber(1, 10); //10 to 100 in multiples of 10 
        int points = 0;
        if (roundType == REGULAR ){
            points = randomNum1 * 10; // Multiplies the random number by 10 if REGULAR type 
        }
        else if(roundType == BONUS){
            points = 200; // If bonus automatic 200 pts
        }
        else if(roundType == DOUBLE){
            points = randomNum1 *20; // double and multiples of 10 of the random num1. (randomNum1 * 10 * 2)
        }

        return points;

}

// Print player points info:
void printPlayerPoints( int p1, int p2 ){ // no return value it is void. 
    printf("P1: %d\n", p1);
    printf("P2: %d\n", p2);
}

//This function prints out the information for each round in the format shown below
void printRoundInfo( ROUNDTYPE t, int dice, int points ){
    printf("Type    : "); // since no \n, the type will print in the correct place. 
    if(t == REGULAR){
        printf("REGULAR\n");
    }
    else if(t == BONUS){
        printf("BONUS\n");
    }
    else if(t == DOUBLE){
        printf("DOUBLE\n");
    }

    printf("DICE    : %d\n", dice);
    printf("POINTS  : %d\n", points);

}





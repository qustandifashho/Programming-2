// Add all the includes for the required header files
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dicegame.h" // Header file 

int main(int argc, char* argv[]){
	// Initialize the srand() to start the random generator:
	srand(time(NULL)); // Seeding

	// Initialize the player-1 and player-2 points to 0 (ints):
	int player1Score = 0;
	int player2Score = 0;


	// Initialize all other required variables ex. rounds
	int numRounds; /// Will ask user so no need to set to 0; 
	int dice;
	int points;
	int round = 0; // Do I need to initialize
	int currPlayer;

	// Ask the user for the number of rounds to run the game
	printf("Enter the number of rounds: ");
	scanf("%d", &numRounds);

	// Call printPlayerPoints() function to print the initial player points which will be 0. This is just calling. Initiailize in other file 
	printPlayerPoints(player1Score, player2Score); // Int Calling

	// Set up the loop to go through all the rounds one at a time
	
	 
	for(round = 1; round <= numRounds; round++ ){ // Starts at round 1 and goes to the number of rounds specified by the user.
		// Enum call:
		ROUNDTYPE roundType = getRoundType(); // define in other file 
		dice = getRandomNumber(1,6); // The dice has numbers between 1 and 6
		points = getRoundPoints(roundType);
		// Print round number
		printf("\nROUND %d\n", round);
		printf("--------");
		// Print current player
		printf("Player  :%d\n",(round%2)+1 ); // to show current player depending on round it is 0 or 1 but we want 1 or 2 so add 1.
		// Call printRoundInfo() to print the round information
		printRoundInfo(roundType, dice, points);
	
	// MAIN GAME LOGIC



	 // Success: Player-1 (odd player) is the current player and the dice rolled is odd 
	// OR Player-2 (even player) is the current player and the dice rolled is even. // CHECK IF I WROTW IT RIGHJT 
		currPlayer = ((round % 2) + 1); // 1 and 2 (not 0 and 1)

	// Write code here to get the main game logic using branches
		if((currPlayer == 1 && (dice % 2 == 1) || (currPlayer == 2 && (dice % 2 != 1)))){ // this may be WRONG IDK mayeb ==0
			if(currPlayer == 1){
				player1Score = player1Score + points;
			}
			else{
				player2Score = player2Score + points;
			}
		}
		else{
		// Failure: Player-1 (odd player) is the current player and the dice rolled is even OR Player-2 (even player) is the current player and the dice rolled is odd.
			if(currPlayer == 1){
				player1Score = player1Score - points;
			}
			else{
				player2Score = player2Score - points;
			}
			currPlayer = (currPlayer % 2) + 1; // chaning to the other player. 

		}
		// Call printPlayerPoints() to print the player information at the end of the round
		printPlayerPoints(player1Score, player2Score);
	}

	printf("\nGAME OVER!!\n");

	// Compare the final points for player-1 and player-2
	if(player1Score < player2Score){
		printf("P2 Won\n"); // Print the winner as the one with higher points

	}
	else if(player1Score > player2Score){
		printf("P1 Won\n"); // Print the winner as the one with higher points

	}
	else{
		printf("P1 and P2 Tied\n"); // not in rubric, not sure if I should remove it or put something else in case there is a tie 
	}

	// Return from the main() function to end the program successfully
	return 0;
}


// Start the main() function with both the parameters
//{
	// Initialize the srand() to start the random generator //////OKAY
	// Initialize the player-1 and player-2 points to 0 //////OKAY
	// Initialize all other required variables
	// Ask the user for the number of rounds to run the game
	// Call printPlayerPoints() function to print the initial player points which will be 0
	
	// Set up the loop to go through all the rounds one at a time
	//{
		// Call the corresponding functions to get the information for this round - type, dice, points
		// Print round number
		// Print current player
	    // Call printRoundInfo() to print the round information
		
		// MAIN GAME LOGIC
		// Write code here to get the main game logic using branches
		// Success: Player-1 (odd player) is the current player and the dice rolled is odd 
		// OR Player-2 (even player) is the current player and the dice rolled is even.
			// Current player gains the points, based on the type of the round (see above). The current playerâ€™s turn continues in the next round.
		// Failure: Player-1 (odd player) is the current player and the dice rolled is even 
		// OR Player-2 (even player) is the current player and the dice rolled is odd.
			// Current player incurs penalty of the same number of points, based on the type of the round (see above). In the next round, the current player is changed to the other player.
		// Call printPlayerPoints() to print the player information at the end of the round
	//}
	//printf("\nGAME OVER!!\n");
	// Compare the final points for player-1 and player-2
	// Print the winner as the one with higher points
	// Return from the main() function to end the program successfully
//}

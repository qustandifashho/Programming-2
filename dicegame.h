#ifndef DICEGAME_H
#define DICEGAME_H

//enumeration ROUNDTYPE
//enum ROUNDTYPE {BONUS, DOUBLE REGULAR};
//enum ROUNDTYPE roundType; 


typedef enum {BONUS,DOUBLE,REGULAR} ROUNDTYPE;
int getRandomNumber( int min, int max );
ROUNDTYPE getRoundType( );
int getRoundPoints( ROUNDTYPE roundType );
void printPlayerPoints( int p1, int p2 );
void printRoundInfo( ROUNDTYPE t, int dice, int points );



#endif
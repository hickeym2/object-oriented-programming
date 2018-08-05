/*
 * Mike Hickey
 * Tic-Tac-Toe
 * Professor Carpenter
 * Due Date October 3, 2016
 */

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstdlib>

using namespace std;

/*=== Function Declaration ===*/
void printTTT(char (&TTTarray)[3][3]);
void insertX(char (&TTTarray)[3][3], int counter, int route, int route2, int route3, int route4);
void insertO(/*PASS BY REFERENCE*/);
void checkForWin(/*PASS BY REFERENCE*/); // IGNORE THIS FOR NOW

void demoWin(char (&TTTarray)[3][3], int counter);
void banner();
void clearScreen();

void countMoves(int &counter);
void manInsertO(char (&TTTarray)[3][3]);
void establishRoute(char (&TTTarray)[3][3], int counter, int &route);
void O_corner(char (&TTTarray)[3][3], int counter, int route2);
void O_sideMid(char (&TTTarray)[3][3], int counter, int route3);
void O_center(char (&TTTarray)[3][3], int counter, int route4);

void continueCorner(char (&TTTarray)[3][3], int counter, int &route2);
void continueSidMid(char (&TTTarray)[3][3], int counter, int &route3);
void continueCenter(char (&TTTarray)[3][3], int counter, int &route4);
/*============================*/

int main(){
/*=== Local Variable Declaration ===*/
	int menuSel = 0;
	int counter = 0;
	int winValue = 0;

	int route  = 0;
	int route2 = 0;
	int route3 = 0;
	int route4 = 0;

	char TTTarray[3][3] = { {'-','-','-'},		//{'-','-','X'}, This is TTTarray[0][2]
                      		{'-','-','-'},		//{'-','-','-'}, And will print an X
                        	{'-','-','-'} };	//{'-','-','-'}, So use it for if statements

/*==================================*/
	clearScreen();
	banner();
	cout << "\n\nPress 1 to play.\nPress 2 to exit.\nSelecting: ";
	cin  >> menuSel;
	clearScreen();

		if (menuSel == 1){
			printTTT(TTTarray);
			insertX(TTTarray, counter, route, route2, route3, route4); //insert an x into [0][0]
			printTTT(TTTarray);//prints the first x at [0][0]
			countMoves(counter);//move 1

			manInsertO(TTTarray);
			countMoves(counter);//move 2
			establishRoute(TTTarray, counter, route);

			printTTT(TTTarray);
			insertX(TTTarray, counter, route, route2, route3, route4);
			countMoves(counter);//move 3

			printTTT(TTTarray);
			manInsertO(TTTarray);
			countMoves(counter);//move 4
			continueCorner(TTTarray, counter, route2); //I probably could have used a struct for route2,3,4
			continueSidMid(TTTarray, counter, route3);
			continueCenter(TTTarray, counter, route4);

			printTTT(TTTarray);
			insertX(TTTarray, counter, route, route2, route3, route4);
			countMoves(counter);//move 5

			printTTT(TTTarray);
                        demoWin(TTTarray, counter);
			manInsertO(TTTarray);
			countMoves(counter);//move 6

			printTTT(TTTarray);
			insertX(TTTarray, counter, route, route2, route3, route4);
			countMoves(counter);//move 7

			printTTT(TTTarray);
                        demoWin(TTTarray, counter);
			manInsertO(TTTarray);
			countMoves(counter);//move 8

			printTTT(TTTarray);
                        demoWin(TTTarray, counter);
			insertX(TTTarray, counter, route, route2, route3, route4);
			countMoves(counter);//move 9
			printTTT(TTTarray);
			demoWin(TTTarray, counter);
		}
		//countMoves(&counter);//counting for O's turn
		else if (menuSel == 2){
			return 0;
		}
}//End of main

void printTTT(char (&TTTarray)[3][3]){
	/*== Print out the TicTacToe grid ===*/

	cout << "   |   |   \n";
	cout << " " << TTTarray[0][0] << " | " << TTTarray[0][1] << " | " << TTTarray[0][2] << "\n";
	cout << "___|___|___\n" << "   |   |   \n";
	cout << " " << TTTarray[1][0] << " | " << TTTarray[1][1] << " | " << TTTarray[1][2] << "\n";
	cout << "___|___|___\n" << "   |   |   \n";
	cout << " " << TTTarray[2][0] << " | " << TTTarray[2][1] << " | " << TTTarray[2][2] << "\n";
	cout << "   |   |   \n\n";

}//End of printTTT

void demoWin(char (&TTTarray)[3][3], int counter){
	/*== This function is a demo for testing for a win or tie ==*/
	/* Top Horizontal */
	if (TTTarray[0][0] == 'X' && TTTarray[0][1] == 'X' && TTTarray[0][2] == 'X'){
                cout << "Ducky Wins.\n";
                exit(0);
	}// end of Top Horizontal

	/* Middle Horizontal */
	if (TTTarray[1][0] == 'X' && TTTarray[1][1] == 'X' && TTTarray[1][2] == 'X'){
                cout << "Ducky Wins.\n";
                exit(0);
	}//end of middle horizontal

	/* Bottom Horizontal*/
	if (TTTarray[2][0] == 'X' && TTTarray[2][1] == 'X' && TTTarray[2][2] == 'X'){
                cout << "Ducky Wins.\n";
                exit(0);
	}//end of Bottom Horizontal

	/*=========================================================================*/
	/* Vertical left*/
	if (TTTarray[0][0] == 'X' && TTTarray[1][0] == 'X' && TTTarray[2][0] == 'X'){
                cout << "Ducky Wins.\n";
                exit(0);
	}// end of vertical left

	/* vertical middle*/
	if (TTTarray[0][1] == 'X' && TTTarray[1][1] == 'X' && TTTarray[2][1] == 'X'){
                cout << "Ducky Wins.\n";
                exit(0);
	}//end of vertical middle

	/* Vertical Right */
	if (TTTarray[0][2] == 'X' && TTTarray[1][2] == 'X' && TTTarray[2][2] == 'X'){
                cout << "Ducky Wins.\n";
                exit(0);
	}// end of vertical right

	/*=========================================================================*/
	/* diagonal down and to the right */
	if (TTTarray[0][0] == 'X' && TTTarray[1][1] == 'X' && TTTarray[2][2] == 'X'){
                cout << "Ducky Wins.\n";
                exit(0);
	}// end of diagonal down right therefore "\"

	/* Diagonal down and to the left */
	if (TTTarray[2][0] == 'X' && TTTarray[1][1] == 'X' && TTTarray[0][2] == 'X'){
		cout << "Ducky Wins.\n";
		exit(0);
	}//end of diagonal and down to the left therfore "/"

	/*=========================================================================*/
	if (counter == 9){
		cout << "It's a Tie.\n";
	}//end of a tie

}//end of winValue

void banner(){
	/* This banner is from googling Tic Tac Toe and entering the picture into giantglass.com, an ascii art generator. */
cout << "................................................................................\n";
cout << "................................................................................\n";
cout << "................................................................................\n";
cout << ".....7777777777....~777777777,......~777I~......................................\n";
cout << "....~7777777777:...77777777777....777777777~....................................\n";
cout << "........7777..........?777=......?777...?77I....................................\n";
cout << "........~77:...........777.......777..........77777?............................\n";
cout << "........~77:...........777.......777,.....,...+7777,............................\n";
cout << "........~77:..........7777I......:777+.:7777....................................\n";
cout << "........~77:......,77777777777....:77777777.....................................\n";
cout << ".........7..........?????????.......?777?.......................................\n";
cout << "................................................................................\n";
cout << "...................:777777777.........7?..........:I777~........................\n";
cout << "..................,77777777777......,7777........77777777?......................\n";
cout << "......................7777?.........77777+......7777,.~777......................\n";
cout << ".......................777.........:77I777.....+777.........,77777..............\n";
cout << ".......................777.........777.,777....+777.........:77777..............\n";
cout << ".......................777........777777777.....7777..,777......................\n";
cout << ".......................777.......77777777777....:77777777I......................\n";
cout << "........................7........I77,....I77......,?777,........................\n";
cout << "................................................................................\n";
cout << "..................................?????????:.......=???........????????.........\n";
cout << ".................................77777777777=....77777777+....7777777777........\n";
cout << "....................................I7777,......7777~.I777....777...............\n";
cout << ".....................................I77.......+777....~777...7777777+..........\n";
cout << ".....................................I77.......+77I.....777...77777777..........\n";
cout << ".....................................I77........777=...777I...777...............\n";
cout << ".....................................I77........~777777777....777777777+........\n";
cout << "......................................7~..........+7777?......,77777777.........\n";
cout << "................................................................................\n";
cout << "................................................................................\n";
}//end of the tic tac toe banner.
/*============================================================================================================================================================*/


void clearScreen(){
	/*== This is a function I made to clear the screen, I wonder if there is a better way to do this ==*/
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}
/*============================================================================================================================================================*/


/*== This Function establishRoute, will look at the board and notice O's first move.
     Then it will use one of the 3 if statements to choose a strategy in one of three functions called O_corner, O_center, O_sideMid == */

void establishRoute(char (&TTTarray)[3][3], int counter, int &route){
	if (TTTarray[0][2] == 'O' || TTTarray[2][0] == 'O' || TTTarray[2][2] == 'O' && counter == 2){
		route = 1;	/*== Setting the route to be corners ==*/
	}
	if (TTTarray[0][1] == 'O' || TTTarray[1][0] == 'O' || TTTarray[2][1] == 'O' || TTTarray[1][2] == 'O' && counter == 2){
		route = 2;	/*== Setting the route to be sideMid ==*/
	}
	if (TTTarray[1][1] == 'O' && counter == 2){
		route = 3;	/*== Setting the route to be center  ==*/
	}
}//end of establishRoute
/*============================================================================================================================================================*/




/* These continue functions are used to store a number as a route.
   Then when ducky wants to place an X, he will remember where he was and what the next best placement should be. */

/* So once O places his first character in a corner position, Ducky will remember that O placed one there [via establishRoute] and will use a strategy based off of O's first position */
/* this is also  used to stop overlapping with the functions. Because when the game progresses, there are more previous conditions met,
   this says ignore all the 'new' conditions that should have been met before a route was selected. */
/* These continueFunctions ensure that Ducky stays on the best strategy. */

void continueCorner(char (&TTTarray)[3][3], int counter, int &route2){
	if (TTTarray[0][2] == 'O' && counter == 4){route2 = 1;}
	if (TTTarray[2][0] == 'O' && counter == 4){route2 = 2;}
	if (TTTarray[2][2] == 'O' && counter == 4){route2 = 3;}

}//end of continueRoute

void continueSidMid(char (&TTTarray)[3][3], int counter, int &route3){
	if (TTTarray[0][1] == 'O' && TTTarray[2][2] == 'O' && counter == 4){route3 = 1;}
	if (TTTarray[1][2] == 'O' && TTTarray[2][2] == 'O' && counter == 4){route3 = 2;}
	if (TTTarray[2][1] == 'O' && TTTarray[2][2] == 'O' && counter == 4){route3 = 3;}
	if (TTTarray[1][0] == 'O' && TTTarray[2][2] == 'O' && counter == 4){route3 = 4;}

}//end of continueSidMid

void continueCenter(char (&TTTarray)[3][3], int counter, int &route4){
	if (TTTarray[0][1] == 'O' && counter == 4){route4 = 1;}
	if (TTTarray[1][2] == 'O' && counter == 4){route4 = 2;}
	if (TTTarray[2][1] == 'O' && counter == 4){route4 = 3;}
	if (TTTarray[1][0] == 'O' && counter == 4){route4 = 4;}
	if (TTTarray[2][0] == 'O' && counter == 4){route4 = 5;}
	if (TTTarray[0][2] == 'O' && counter == 4){route4 = 6;}

}//end of continueCenter

/*==========================================================================================================================================================*/


void O_corner(char (&TTTarray)[3][3], int counter, int route2){
	int corner22 = 0;//Probably could have used a struct here
	int corner02 = 0;
	int corner20 = 0;
                if (TTTarray[0][2] == 'O'){
                        TTTarray[2][2] = 'X';
			if (route2 == 1){/**/		/* The route2 == 1, says when this is true, use only this next set of strategic logic */

                        	if (TTTarray[1][1] == 'O'){
                                	TTTarray[2][0] = 'X';
					corner02 = 3;	/* This corner02 is saying go back to this next set of logic and ignore the other ones when O has made a move at 0,2*/
                                	if (TTTarray[1][0] == 'O' && counter == 6){
                                        	TTTarray[2][1] = 'X';
						corner02 = 1;
                                	}
                                	if (TTTarray[2][1] == 'O' && counter == 6){
                                        	TTTarray[1][0] = 'X';
						corner02 = 2;
                                	}
                        	}
				if (TTTarray[0][1]=='O' || TTTarray[1][0]=='O' || TTTarray[1][2]=='O' || TTTarray[2][0]=='O' || TTTarray[2][1]=='O' && TTTarray[1][1]=='-' && counter==4){
                                	TTTarray[1][1] = 'X';
					if (corner02 == 1){
						TTTarray[1][1] = 'O';
					}
					if (corner02 == 2){
						TTTarray[1][1] = 'O';
					}
					if (counter == 6 && corner02 == 3 && (TTTarray[0][1] == 'O' || TTTarray[0][2] == 'O' || TTTarray[1][1] == 'O')){
						TTTarray[1][1] = 'O';
						TTTarray[1][0] = 'X';
					}
                        	}
				else if (( TTTarray[1][2] == 'O' || TTTarray[0][1] == 'O') && counter == 6){
					TTTarray[2][1] = 'X';
					TTTarray[1][1] = 'O';
				}
			}/**/
                }
		/*=======================================================================================*/
                if (TTTarray[2][0] == 'O'){
                        TTTarray[2][2] = 'X';
			if (route2 == 2){/**/

                        	if (TTTarray[1][1] == 'O'){
					corner20 = 3;
                                	TTTarray[0][2] = 'X';
                                	if (TTTarray[0][1] == 'O' && counter == 6){
                                        	TTTarray[1][2] = 'X';
						corner20 = 1;
                                	}
                                	if (TTTarray[1][2] == 'O' && counter == 6){
                                        	TTTarray[0][1] = 'X';
						corner20 = 2;
                                	}
                        	}
				if (TTTarray[0][1] == 'O' || TTTarray[0][2] == 'O' || TTTarray[1][0] == 'O' || TTTarray[1][2] == 'O' || TTTarray[2][1] == 'O' &&  TTTarray[1][1] == '-' && counter == 4){
                                	TTTarray[1][1] = 'X';
					if (corner20 == 1){
						TTTarray[1][1] = 'O';
					}
					if (corner20 == 2){
						TTTarray[1][1] = 'O';
					}
					if (counter == 6 && corner20 == 3 && (TTTarray[1][0] == 'O' || TTTarray[2][1] == 'O' || TTTarray[1][1] == 'O')){
						TTTarray[1][1] = 'O';
						TTTarray[0][1] = 'X';
					}
                        	}
				else if ((TTTarray[1][0] == 'O' || TTTarray[2][1] == 'O') && counter == 6){
					TTTarray[1][1] = 'O';
					TTTarray[0][1] = 'X';
				}
			}/**/
                }
		/*==================================================================================*/
                if (TTTarray[2][2] == 'O'){
                        TTTarray[0][2] = 'X';
			if (route2 == 3){/**/

                        	if (TTTarray[0][1] == 'O'){
                                	TTTarray[2][0] = 'X';
					corner22 = 3;
                                	if (TTTarray[1][0] == 'O' && counter == 6){
                                        	TTTarray[1][1] = 'X';
						corner22 = 1;
                                	}
                                	if (TTTarray[1][1] == 'O' && counter == 6){
                                        	TTTarray[1][0] = 'X';
						corner22 = 2;
                                	}
                        	}
		        	if (TTTarray[1][0]=='O' || TTTarray[1][1]=='O' || TTTarray[1][2]=='O' || TTTarray[2][0]=='O' || TTTarray[2][1]=='O' && counter==4){
                                	TTTarray[0][1] = 'X';
                                	if (corner22 == 1){
						TTTarray[0][1] = 'O';
					}
					if (corner22 == 2){
						TTTarray[0][1] = 'O';
					}
					/*== When you corner22 with ducky ==*/
					if (counter == 6 && corner22 == 3 && (TTTarray[1][2] == 'O' || TTTarray[2][1] == 'O' || TTTarray[1][2] == '-')){
						TTTarray[0][1] = 'O';
						TTTarray[1][1] = 'X';
						/* I am seething with rage, if TTTarray[2][1] == 'O' is true, Ducky will not take his turn. key combo 2, 9, 8*/
						/* Possibly fixed with the else if below*/
					}
                       		}
				else if (TTTarray[2][1] == 'O' && counter == 6){
					TTTarray[0][1] = 'O';
					TTTarray[1][1] = 'X';
				}
			}/**/
                }
}//end of O_corner
/*=====================================================================================================================================================================*/


void O_sideMid(char (&TTTarray)[3][3], int counter, int route3){
        if (TTTarray[1][1] == '-'){
		TTTarray[1][1] = 'X';
	}
        /*=== O's second move is always TTTarray[2][2]  ===*/
	if (TTTarray[0][1] == 'O' && TTTarray[2][2] == 'O'){
		TTTarray[2][0] = 'X';
		if (route3 == 1){/**/
        		if (TTTarray[0][2] == 'O'){
                		TTTarray[1][0] = 'X';
                	}
                	if (TTTarray[1][0] == 'O'){
                        	TTTarray[0][2] = 'X';
                	}
			if (TTTarray[2][1] == 'O' && counter == 6){
				TTTarray[1][0] = 'X';
			}
		}/**/
        }
        if (TTTarray[1][2] == 'O' && TTTarray[2][2] == 'O'){
             	TTTarray[0][2] = 'X';
		if (route3 == 2){/**/
             		if (TTTarray[0][1] == 'O'){
                 		TTTarray[2][0] = 'X';
            		}
            		if (TTTarray[2][0] == 'O'){
                 		TTTarray[0][1] = 'X';
            		}
			if (TTTarray[1][0] == 'O' && counter == 6){
				TTTarray[2][0] = 'X';
			}
		}/**/
     	}
        if (TTTarray[2][1] == 'O' && TTTarray[2][2] == 'O'){
                TTTarray[2][0] = 'X';
		if (route3 == 3 ){/**/
             		if (TTTarray[1][0] == 'O'){
                      		TTTarray[0][2] = 'X';
               		}
              		if (TTTarray[0][2] == 'O'){
                   		TTTarray[1][0] = 'X';
                	}
			if (TTTarray[0][1] == 'O' && counter == 6){
				TTTarray[1][0] = 'X';
			}
		}/**/
   	}
      	if (TTTarray[1][0] == 'O' && TTTarray[2][2] == 'O'){
           	TTTarray[0][2] = 'X';
		if (route3 == 4){/**/
                	if (TTTarray[2][0] == 'O'){
                       		TTTarray[0][1] = 'X';
              		}
                	if (TTTarray[0][1] == 'O'){
                      		TTTarray[2][0] = 'X';
                	}
			if (TTTarray[1][2] == 'O' && counter == 6){
				TTTarray[0][1] = 'X';
			}
		}/**/
        }
	/*== If its not one of the above options then win the game ==*/
	if (TTTarray[2][2] == '-' && counter == 4){
		TTTarray[2][2] = 'X';
	}

}//end of O_sideMid
/*===============================================================================================================================================================================*/


void O_center(char (&TTTarray)[3][3], int counter, int route4){
	/* This is the only function that I expect to be played when the program is run
	   Because the O's opponent algorithm should choose the best way to make a tie, and the only way to tie is if he takes the center. */

	TTTarray[2][2] = 'X';
     	if (TTTarray[0][1] == 'O'){ /* Count should be 4 */
           	TTTarray[2][1] = 'X'; /* Count should be 5 */
		if (route4 == 1){/**/
                	/*=== O's 3rd move is to block you ===*/
                	if (TTTarray[2][0] == 'O'){ /* Count should be 6 */
                    		TTTarray[0][2] = 'X'; /* Count should be 7 */
                        	/*=== O's 4th move is to block you ===*/
                        	if (TTTarray[1][2] == 'O'){ /* Count should be 8 */
                                	TTTarray[1][0] = 'X'; /* count should be 9 */
                       		}
                	}
		}/**/
       	}
       	if (TTTarray[1][2] == 'O'){
   		TTTarray[1][0] = 'X';
		if (route4 == 2){/**/
              		if (TTTarray[2][0] == 'O'){
                  		TTTarray[0][2] = 'X';
                       		if (TTTarray[0][1] == 'O'){
                          		TTTarray[2][1] = 'X';
                        	}
               		}
		}/**/
        }
        if (TTTarray[2][1] == 'O'){
             	TTTarray[0][1] = 'X';
		if (route4 == 3){/**/
                	if (TTTarray[0][2] == 'O'){
                     		TTTarray[2][0] = 'X';
                        	if (TTTarray[1][0] == 'O'){
                            		TTTarray[1][2] = 'X';
                       		}
                	}
		}/**/
      	}
        if (TTTarray[1][0] == 'O'){
          	TTTarray[1][2] = 'X';
		if (route4 == 4){/**/
                	if (TTTarray[0][2] == 'O'){
                  		TTTarray[2][0] = 'X';
                       		if (TTTarray[2][1] == 'O'){
                           		TTTarray[0][1] = 'X';
                        	}
               		}
		}/**/
        }

	/* These two if statements are here in case the opponent wants to mess with my X algorithm.
	   Say the opponent places a O somewhere you would not expect it to; this will account for it. */
	if (TTTarray[2][0] == 'O'){
		TTTarray[0][2] = 'X';
		if (route4 == 5){/**/
			if (TTTarray[0][1] == 'O' && counter == 6){
				TTTarray[1][2] = 'X';
				TTTarray[2][1] = '-';
			}
			if (TTTarray[1][2] == 'O' && counter == 6){
				TTTarray[0][1] = 'X';
				TTTarray[1][0] = '-';
			}
		}/**/
	}
	if (TTTarray[0][2] == 'O'){
		TTTarray[2][0] = 'X';
		if (route4 == 6){/**/
			if (TTTarray[1][0] == 'O' && counter == 6){
				TTTarray[2][1] = 'X';
				TTTarray[1][2] = '-';
			}
			if (TTTarray[2][1] == 'O' && counter == 6){
				TTTarray[1][0] = 'X';
				TTTarray[0][1] = '-';
			}
		}/**/
	}
}//end of O_center

/*=============================================================================================================================================================================*/


void insertX(char (&TTTarray)[3][3], int counter, int route, int route2, int route3, int route4){
	/* So the first time this runs, it will print out an x, the next times it runs it will analyze the board and choose a strategy to use. */
	//route 1 = corner, route 2 = mid not center, route 3 = center

	/*=== This will always be the first move ===*/
	if (TTTarray[0][0] == '-' && counter == 0){
		TTTarray[0][0] = 'X';//counter is now 1
	}

	/*=== When O's first move is a corner ===*/
	if (route == 1){
		O_corner(TTTarray, counter, route2);
	}

	/*=== When O's first move is a middle but not center ===*/
	if (route == 2){
		O_sideMid(TTTarray, counter, route3);
	}//end of O's first move is a side middle but not center

	/*=== When O's first move is center ===*/
	if (route == 3){
		O_center(TTTarray, counter, route4);
	}//end of O's first move is center

}//end of insertX
/*==============================================================================================================================================================================*/



void insertO(/*PASS BY REFERENCE*/){

}//End of insertO

/*================================================================================================================================================================================*/


void countMoves(int &counter){
	static int count = 0;
	count ++;
	counter ++;
	//cout << "The counter is: " << counter << "\n";

}//end of count moves
/*=================================================================================================================================================================================*/


void manInsertO(char (&TTTarray)[3][3]){
	/* This is having user input play as O for testing purposes */
	int posSel = 0;

	cout << "   |   |   \n";
        cout << " 1 | 2 | 3 \n";
 	cout << "___|___|___\n" << "   |   |   \n";
        cout << " 4 | 5 | 6 \n";
	cout << "___|___|___\n" << "   |   |   \n";
        cout << " 7 | 8 | 9 \n";
	cout << "   |   |   \n\n";

	cout << "\nSelect a number to place your O.\nSelecting: ";
        cin  >> posSel;
	clearScreen();

        if (posSel == 1){TTTarray[0][0] = 'O';}
        if (posSel == 2){TTTarray[0][1] = 'O';}
        if (posSel == 3){TTTarray[0][2] = 'O';}
        if (posSel == 4){TTTarray[1][0] = 'O';}
        if (posSel == 5){TTTarray[1][1] = 'O';}
        if (posSel == 6){TTTarray[1][2] = 'O';}
        if (posSel == 7){TTTarray[2][0] = 'O';}
        if (posSel == 8){TTTarray[2][1] = 'O';}
        if (posSel == 9){TTTarray[2][2] = 'O';}
	else {  }

}//end of manInsertO

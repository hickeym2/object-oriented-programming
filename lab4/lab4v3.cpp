/*
 * Mike Hickey
 * Tic-Tac-Toe
 * Professor Carpenter
 * Due Date October 3, 2016
 */

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

/*=== Function Declaration ===*/
void printTTT(char (&TTTarray)[3][3]);
void insertX(char (&TTTarray)[3][3], int counter, int route, int route2, int route3, int route4);
void insertO(/*PASS BY REFERENCE*/);
void checkForWin(/*PASS BY REFERENCE*/); // IGNORE THIS FOR NOW

void countMoves(int &counter);
void manInsertO(char (&TTTarray)[3][3]);
void establishRoute(char (&TTTarray)[3][3], int counter, int &route);
void O_corner(char (&TTTarray)[3][3], int counter, &route2);
void O_sideMid(char (&TTTarray)[3][3], int counter);
void O_center(char (&TTTarray)[3][3], int counter);

void continueCorner(char (&TTTarray)[3][3], int counter, int &route2);
void continueSidMid(char (&TTTarray)[3][3], int counter, int &route3);
void continueCenter(char (&TTTarray)[3][3], int counter, int &route4);
/*============================*/

int main(){
/*=== Local Variable Declaration ===*/
	int menuSel = 0;
	int counter = 0;
	int route  = 0;
	int route2 = 0;
	int route3 = 0;
	int route4 = 0;

	char TTTarray[3][3] = { {'-','-','-'},		//{'-','-','X'}, This is TTTarray[0][2]
                      		{'-','-','-'},		//{'-','-','-'}, And will print an X
                        	{'-','-','-'} };	//{'-','-','-'}, So use it for if statements

/*==================================*/
	cout << "Press 1 to play.\nPress 2 to exit.\nSelecting: ";
	cin >> menuSel;
		if (menuSel == 1){
			//countMoves(&counter);
			insertX(TTTarray, counter, route, route2, route3, route4); //insert an x into [0][0]
			printTTT(TTTarray);//prints the first x at [0][0]
			countMoves(counter);//move 1

			printTTT(TTTarray);
			manInsertO(TTTarray);
			countMoves(counter);//move 2
			establishRoute(TTTarray, counter, route);

			printTTT(TTTarray);
			insertX(TTTarray, counter, route, route2, route3, route4);
			countMoves(counter);//move 3

			printTTT(TTTarray);
			manInsertO(TTTarray);
			countMoves(counter);//move 4
			continueCorner(TTTarray, counter, route2);

			printTTT(TTTarray);
			insertX(TTTarray, counter, route, route2, route3, route4);
			countMoves(counter);//move 5

			printTTT(TTTarray);
			manInsertO(TTTarray);
			countMoves(counter);//move 6

			printTTT(TTTarray);
			insertX(TTTarray, counter, route, route2, route3, route4);
			countMoves(counter);//move 7

			printTTT(TTTarray);
			manInsertO(TTTarray);
			countMoves(counter);//move 8

			printTTT(TTTarray);
			insertX(TTTarray, counter, route, route2, route3, route4);
			countMoves(counter);//move 9
			printTTT(TTTarray);
		}
		//countMoves(&counter);//counting for O's turn
		else if (menuSel == 2){
			return 0;
		}
}//End of main

void printTTT(char (&TTTarray)[3][3]){
	/*== Print out the TicTacToe grid ===*/
	//cout << *TTTarray << "\n"; //Prints the array in a line.

	cout << "   |   |   \n";
	cout << " " << TTTarray[0][0] << " | " << TTTarray[0][1] << " | " << TTTarray[0][2] << "\n";
	cout << "___|___|___\n" << "   |   |   \n";
	cout << " " << TTTarray[1][0] << " | " << TTTarray[1][1] << " | " << TTTarray[1][2] << "\n";
	cout << "___|___|___\n" << "   |   |   \n";
	cout << " " << TTTarray[2][0] << " | " << TTTarray[2][1] << " | " << TTTarray[2][2] << "\n";
	cout << "   |   |   \n\n";

}//End of printTTT

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


void continueCorner(char (&TTTarray)[3][3], int counter, int &route2){
	if (TTTarray[0][2] == 'O' && counter == 4){route2 = 1;}
	if (TTTarray[2][0] == 'O' && counter == 4){route2 = 2;}
	if (TTTarray[2][2] == 'O' && counter == 4){route2 = 3;}

}//end of continueRoute

void continueSidMid(char (&TTTarray)[3][3], int counter, int &route3){

}//end of continueSidMid

void continueCenter(char (&TTTarray)[3][3], int counter, int &route4){

}//end of continueCente

void O_corner(char (&TTTarray)[3][3], int counter, int &route2){
                if (route2 == 1){
                        TTTarray[2][2] = 'X';
                        if (TTTarray[0][1] == 'O' || TTTarray[1][0] == 'O' || TTTarray[1][2] == 'O' || TTTarray[2][0] == 'O' || TTTarray[2][1] == 'O' && TTTarray[1][1] == '-' && counter == 4){
                                TTTarray[1][1] = 'X';
                        }
                        if (TTTarray[1][1] == 'O'){
                                TTTarray[2][0] = 'X';
                                if (TTTarray[1][0] == 'O' && counter == 6){
                                        TTTarray[2][1] = 'X';
                                }
                                if (TTTarray[2][1] == 'O' && counter == 6){
                                        TTTarray[1][0] = 'X';
                                }
                        }
                }
                if (route2 == 2){
                        TTTarray[2][2] = 'X';
			if (TTTarray[0][1] == 'O' || TTTarray[0][2] == 'O' || TTTarray[1][0] == 'O' || TTTarray[1][2] == 'O' || TTTarray[2][1] == 'O' &&  TTTarray[1][1] == '-' && counter == 4){
        			TTTarray[1][1] = 'X';
                        }
                        if (TTTarray[1][1] == 'O'){
                                TTTarray[0][2] = 'X';
                                if (TTTarray[0][1] == 'O' && counter == 6){
                                        TTTarray[1][2] = 'X';
                                }
                                if (TTTarray[1][2] == 'O' && counter == 6){
                                        TTTarray[0][1] = 'X';
                                }
                        }
                }
                if (route2 == 3){
                        TTTarray[0][2] = 'X';
			if (TTTarray[1][0] == 'O' || TTTarray[1][1] == 'O' || TTTarray[1][2] == 'O' || TTTarray[2][0] == 'O' || TTTarray[2][1] == 'O' && TTTarray[0][1] == '-' && counter == 4){
                                TTTarray[0][1] = 'X';
                        }
                        if (TTTarray[0][1] == 'O'){
                                TTTarray[2][0] = 'X';
                                if (TTTarray[1][0] == 'O'){
                                        TTTarray[1][1] = 'X';
                                }
                                if (TTTarray[1][1] == 'O'){
                                        TTTarray[1][0] = 'X';
                                }
                        }
                }
}//end of O_corner

void O_sideMid(char (&TTTarray)[3][3], int counter){
        if (TTTarray[1][1] == '-'){
		TTTarray[1][1] = 'X';
	}
        /*=== O's second move is always TTTarray[2][2]  ===*/
	if (TTTarray[0][1] == 'O' && TTTarray[2][2] == 'O'){
		TTTarray[2][0] = 'X';
        	if (TTTarray[0][2] == 'O'){
                	TTTarray[1][0] = 'X';
                }
                if (TTTarray[1][0] == 'O'){
                        TTTarray[0][2] = 'X';
                }
        }
        if (TTTarray[1][2] == 'O' && TTTarray[2][2] == 'O'){
             	TTTarray[0][2] = 'X';
             	if (TTTarray[0][1] == 'O'){
                 	TTTarray[2][0] = 'X';
            	}
            	if (TTTarray[2][0] == 'O'){
                 	TTTarray[0][1] = 'X';
            	}
     	}
        if (TTTarray[2][1] == 'O' && TTTarray[2][2] == 'O'){
                TTTarray[2][0] = 'X';
             	if (TTTarray[1][0] == 'O'){
                      	TTTarray[0][2] = 'X';
               	}
              	if (TTTarray[0][2] == 'O'){
                   	TTTarray[1][0] = 'X';
                }
   	}
      	if (TTTarray[1][0] == 'O' && TTTarray[2][2] == 'O'){
           	TTTarray[0][2] = 'X';
                if (TTTarray[2][0] == 'O'){
                       	TTTarray[0][1] = 'X';
              	}
                if (TTTarray[0][1] == 'O'){
                      	TTTarray[2][0] = 'X';
                }
        }
	/*== If its not one of the above options then win the game ==*/
	if (TTTarray[2][2] == '-' && counter == 4){
		TTTarray[2][2] = 'X';
	}

}//end of O_sideMid

void O_center(char (&TTTarray)[3][3], int counter){

	TTTarray[2][2] = 'X';
     	if (TTTarray[0][1] == 'O'){ /* Count should be 4 */
           	TTTarray[2][1] = 'X'; /* Count should be 5 */
                /*=== O's 3rd move is to block you ===*/
                if (TTTarray[2][0] == 'O'){ /* Count should be 6 */
                    	TTTarray[0][2] = 'X'; /* Count should be 7 */
                        /*=== O's 4th move is to block you ===*/
                        if (TTTarray[1][2] == 'O'){ /* Count should be 8 */
                                TTTarray[1][0] = 'X'; /* count should be 9 */
                       	}
                }
       	}
       	if (TTTarray[1][2] == 'O'){
   		TTTarray[1][0] = 'X';
              	if (TTTarray[2][0] == 'O'){
                  	TTTarray[0][2] = 'X';
                       	if (TTTarray[0][1] == 'O'){
                          	TTTarray[2][1] = 'X';
                        }
               	}
        }
        if (TTTarray[2][1] == 'O'){
             	TTTarray[0][1] = 'X';
                if (TTTarray[0][2] == 'O'){
                     	TTTarray[2][0] = 'X';
                        if (TTTarray[1][0] == 'O'){
                            	TTTarray[1][2] = 'X';
                       	}
                }
      	}
        if (TTTarray[1][0] == 'O'){
          	TTTarray[1][2] = 'X';
                if (TTTarray[0][2] == 'O'){
                  	TTTarray[2][0] = 'X';
                       	if (TTTarray[2][1] == 'O'){
                           	TTTarray[0][1] = 'X';
                        }
               	}
        }

}//end of O_center




void insertX(char (&TTTarray)[3][3], int counter, int route, int route2, int route3, int route4){

	//route 1 = corner, route 2 = mid not center, route 3 = center

	/*=== This will always be the first move ===*/
	if (TTTarray[0][0] == '-' && counter == 0){
		TTTarray[0][0] = 'X';//counter is now 1
	}

	/*=== When O's first move is a corner ===*/
	if (route == 1){
		O_corner(TTTarray, counter);
		
	}

	/*=== When O's first move is a middle but not center ===*/
	if (route == 2){
		O_sideMid(TTTarray, counter);
		
	}//end of O's first move is a side middle but not center


	/*=== When O's first move is center ===*/
	if (route == 3){
		O_center(TTTarray, counter);
		
	}//end of O's first move is center


}//end of insertX

void insertO(/*PASS BY REFERENCE*/){

}//End of insertO


void countMoves(int &counter){
	static int count = 0;
	count ++;
	counter ++;
	cout << "The counter is: " << counter << "\n";

}//end of count moves

void manInsertO(char (&TTTarray)[3][3]){
	int posSel = 0;

	cout << "   |   |   \n";
        cout << " 1 | 2 | 3 \n";
 	cout << "___|___|___\n" << "   |   |   \n";
        cout << " 4 | 5 | 6 \n";
	cout << "___|___|___\n" << "   |   |   \n";
        cout << " 7 | 8 | 9 \n";
	cout << "   |   |   \n\n";

	cout << "Where do you want to place your O?\nSelect a number to place your O.\nSelecting: ";
        cin  >> posSel;


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

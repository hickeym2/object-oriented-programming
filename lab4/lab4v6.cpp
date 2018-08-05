/*
 * Mike Hickey
 * Tic-Tac-Toe
 * With headder files for everything.
 * Professor Carpenter
 * Due Date October 3, 2016
 */

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include "tttx.h" 	//My headder file to insert X. Make sure tttx.h is in the same folder where you compile lab4v6.cpp, or whatever version the lab4 is.
			//#include "partners.h", Make sure the partner's .h file has all the proper includes that he has in his original lab.
			//make sure the local variables in your partner's main, are also in your main.
using namespace std;

/*=== Function Declaration ===*/
//All X functions are in the tttx.h
/*============================*/

int main(){
/*=== Local Variable Declaration ===*/
	int menuSel = 0;
	int counter = 0;

	int route  = 0;/*== route having a value of 0 is never used. So I initilized it there. ==*/
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
			/* You want to replace manInsertO(TTTarray) with inserO( Arguments)*/
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
		else {
			cout << "Exiting Program. . .\n";
			return 0;
		}
}//End of main


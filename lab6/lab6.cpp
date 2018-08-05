/*
 * Mike Hickey
 * Professor Carpenter
 * Lab6 Doubly Linked Circular List
 * Due Date 10/17/16
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

/*=== Function Prototype ===*/
void resetList();
void clearScreen();
void menu(int &menuSel);

void makeStruct();
void makeEntry();
int  exitProgram();


void testPrint(int menuSel);



/*==========================*/

int main(){

/*=== Local Variable Declaration ===*/
int menuSel = 0;	//This is being commented because it needs to be in the while loop. Every variable might need to be in the while loop.
int i = 0;
/*==================================*/
	//for (i = 0; i <= 100; i++){
		/*ive tried while loops, do while, for loops..
		When i do not use a type of loop, my program will go
		into the if statements if they meet the conditions.
		but when i use a loop, the function menu(menuSel) will
		recieve a number and store it. Then it will return to the
		main, and it will start evaluating the if statements.
		But, i want this to loop, so im adding loops.
		So, if i type in 5 for menuSel, the program will not go into
		the if statement "if (menuSel == 5)". The only time it will
		enter an if statement is when i type in 8 or 9, and those
		have the exit(0) somewhere in their function.
		Now, i have already used gdb to check all this out. when i use
		gdb, i set a break point at 30, so i can go to the
		menu function. I will type in 3 as an example, then type step.
		I constantly am doing print menuSel every time it steps.
		once i get to if (menuSel == 5), the gdb still prints menuSel
		with a value of 5. NEXT the gdb knows the value is 5, so it
		will go into the if statement and perform the testPrint();
		Only when I am using gdb it will print testPrint();
		it prints it to the screen and everything. Then it will keep
		going forward with step like nothing strange is happening.

		When i run the compiled code, it will keep asking me to enter
		in numbers until i type in either 8 or 9, or a really
		large number like 555555555555555555555555555555.

		So, tldr. I need to use loops to continusly modify the file
		qbList.txt
		if statements that are not supposed to be met, are being met.
		some if statements are not being performed when they
		are being met.
		 */
		clearScreen();
		menu(menuSel);
		if (menuSel == 1){
			//add an entry
			testPrint(menuSel);
			makeEntry();
		}
		if (menuSel == 2){
			//read full list
			testPrint(menuSel);
		}
		if (menuSel == 3){
			//search for year name number
			testPrint(menuSel);
		}
		if (menuSel == 4){
			//To sort the list alphabetically
			testPrint(menuSel);
		}
		if (menuSel == 5){
			//To delete an entry
			testPrint(menuSel);
		}
		if (menuSel == 6){
			//remove all entries
			testPrint(menuSel);
			//exitProgram();//testing here, un comment this after
					//you have run the code once or so
					//exit program has exit(0);
					// and that might mess it up.
		}
		if (menuSel == 7){
			//reset list to original
			resetList();
		}
		if (menuSel == 8){
			//exit program
			exitProgram();
		}
		if (menuSel == 9 /*menuSel != 1 || menuSel != 2 || menuSel != 3 || menuSel != 4 || menuSel != 5 || menuSel != 6 || menuSel != 7 || menuSel != 8*/){
			cout << "MenuSel != (1 2 3 4 5 6 7 8)\n";
			exit(0);
		}
	//}//end of for loop
}//end of main.

void resetList(){
	/*This really is not resetting the list. its making a file. redo this*/
	ofstream qbList;
	qbList.open ("qbList.txt"); // makes a file called qbList.txt
	qbList << "Kurt Warner 2000\n";
	qbList << "Trent Dilfer 2001\n";
	qbList << "Tom Brady 2002\n";
	qbList << "Brad Johnson 2003\n";
	qbList << "Tom Brady 2004\n";
	qbList << "Tom Brady 2005\n";
	qbList << "Ben Roethlisberger 2006\n";
	qbList << "Peyton Manning 2007\n";
	qbList << "Ben Roethlisberger 2009\n";
	qbList << "Drew Brees 2010\n";
	qbList << "Aaron Rodgers\n";
	qbList << "Eli Manning 2012\n";
	qbList << "Joe Flacco 2013\n";
	qbList << "Russell Wilson 2014\n";
	qbList << "Tom Brady 2015\n";
	qbList.close();
	cout << "Your file \"qbList.txt\" has been overwritten\n";
}//end of resetList

void clearScreen(){
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}//end of clearScreen
void menu(int &menuSel){
	cout << "Select 1 to add an entry to the list.\nSelect 2 to read the list.\nSelect 3 to Search for year/name/number.\nSelect 4 to sort the list in alphabetical order.\nSelect 5 to delete an entry.\nSelect 6 to remove all entries.\nSelect 7 to reset the list.\nSelect 8 to exit the program.\nSelecting: ";
	cin  >> menuSel;
}//end of menu

void makeStruct(){
	struct qb{
		string qbFirstName;
		string qbLastName;
		string qbEntryName;
		int qbYears;
		int qbNumWins;
		struct qb *forwardsQB;
		struct qb *backwardsQB;
	};
	qb *first;
}//end of make struct

void makeEntry(){
	/*
	struct qb{
		string firstName;
		string lastName;
		int years;
		int numWins;
		//qb *forwards		//this is a pointer to point to the next person in the list
		//qb *backwards	//this points to the previous person in the list
	}qb_1;//end of struct
	*/

	/*
	string entryName;
	cout << "Enter a name to store the QB as a node entry.\n: ";
	cin  >> entryName;
	cout << "Enter a QB's first name.\n: ";
	cin  >> firstName;
	cout << "Enter a QB's last name.\n: ";
	cin  >> lastName;
	cout << "Enter the year the QB won a super bowl.\n: ";
	cin  >> years;

	makeStruct();
	struct qb *startBuffer;
	struct qb *valueBuffer;
	valueBuffer = new(struct qb);
	valueBuffer -> qbEntryName = entryName;
	valueBuffer -> qbFirstName = firstName;
	valueBuffer -> qbLastName = lastName;
	valueBuffer -> qbYears = years;
	valueBuffer -> qbNumWins = numWins;
	valueBuffer -> forwards = '\0';

	if (first == '\0'){
		valueBuffer -> backwards;
	}
	else {
		startBuffer = first;
		while (startBuffer -> forwards != '\0'){
			startBuffer = startBuffer -> forwards;
		}
		startBuffer -> forwards = valueBuffer;
		valueBuffer -> backwards = startBuffer;
	}
	*/


	/* This is taking the information entered and making a file called qbList.txt */
	/* It is overwritingthe file every time, deleting the contents and putting just this */
	/* We want to add a lin to a list that was already there */
	/*
	ofstream qbList;
	qbList.open ("qbList.txt");
	qbList << qb_1.firstName << " ";
	qbList << qb_1.lastName << " ";
	qbList << qb_1.years << " ";
	qbList << qb_1.numWins << "\n";
	qbList.close();
	cout << "You have made a new entry for " << qb_1.firstName << " " << qb_1.lastName << " " << qb_1.years << " " << qb_1.numWins << "\n";
	*/
}//end of make entry

int exitProgram(){
	cout << "Exiting Program. . .\n";
	exit(0);
}//End of exitProgram

void testPrint(int menuSel){
	cout << "Testing... "<< menuSel << " \n";
}//end of testPrint


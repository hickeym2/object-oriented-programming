/*
 * Mike Hickey
 * Professor Carpenter
 * Lab 6 Linked List
 * Due Date 10/21/16
 */

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;

//=== Struct ===
struct entry_qb{
	string firstName;
	string lastName;
	string entryName;
	int yearWon;
	int numWins;
	entry_qb *next; //points to the next struct in the list
	entry_qb *prev; //points to the previous struct in the list
};

entry_qb *list = NULL;
//=== Function Prototype ===
void menu(int &menuSel);
void clearScreen();
void exitProgram();
void testPrint(int menuSel);

int makeEntry();//case 1
int readList(struct entry_qb *list);
int resetList(struct entry_qb *&list);//case 7
int listLength(struct entry_qb *list);
void smallestYearWon(struct entry_qb *&list);

int main(){
	int menuSel = 0;
	clearScreen();
	menu(menuSel);

resetList(list);
smallestYearWon(list);

	do{	/* Just because you don't like do-while. */
		switch (menuSel){
			case 1: //makeEntry();
				cout << endl << endl;
				menu(menuSel);
				break;
				//case 1 add an entry.
			case 2: readList(list);
				cout << endl << endl;
				menu(menuSel);
				break;
				//case 2 read full list to screen
			case 3: 
				cout << endl << endl;
				menu(menuSel);
				break;
				//case 3 search for year, name, or number
			case 4:
				cout << endl << endl;
				menu(menuSel);
				break;
				//case 4 sort alphabetically
			case 5: 
				cout << endl << endl;
				menu(menuSel);
				break;
				//case 5 delete an entry
			case 6: 
				cout << endl << endl;
				menu(menuSel);
				break;
				//case 6 remove all entries
			case 7: resetList(list);//Since list is a pointer, you dont use *list because that would be  de refrencing the pointer, and it it will violate the function prototype
//				smallestYearWon(list);
				cout << endl << endl;
				menu(menuSel);
				break;
				//case 7 reset list to original
			default:cout << "Exiting Program. . . " << endl;
				return 0;
				break;
				//default will exit the program.
		}//end of switch(menuSel)
	}while(menuSel != 0);//end of do-while loop

}//End of main

void menu(int &menuSel){
	cout << "Select 1 to add an entry to the list.\nSelect 2 to read the list.\nSelect 3 to search for a year, name, or number.\nSelect 4 to sort the list in alphabetical order.\nSelect 5 to delete an entry.\nSelect 6 to remove all entries.\nSelect 7 to reset the list.\nSelect 8 to exit the program.\nSelecting: ";
	cin  >> menuSel;
}//end of menu()

void clearScreen(){
	for (int i = 0; i < 50; i++){
		cout << endl;
	}
}//end of clearScreen()

void exitProgram(){
	cout << "Exiting Program. . ." << endl;
	exit(0);
}//end of exitProgram()

void testPrint(int menuSel){
	cout << "Testing. . . " << endl << "menuSel = " << menuSel << endl;
}//end of testPrint()

/*

void makeEntry(){
	string fNameBuff;
	string lNameBuff;
	string entryNameBuff;
	int yearBuff = 0;
	int numWinsBuff = 1;
	int trigger = 1;

	entry_qb head


	while(trigger){

		cout << endl << "Enter the first name of the QB." << endl;
		cin  >> fNameBuff;
		cout << endl << "Enter the last name of the QB." << endl;
		cin  >> lNameBuff;
		cout << endl << "Enter the year the QB won the Super Bowl." << endl;
		cin  >> yearBuff;
		

		
		cout << endl << "Enter 1 to add another entry, or Enter 0 to quit" << endl;
		cout << "Entering: ";
		cin  >> trigger;
		cout << endl;
	}//end of while(trigger)
}//end of makeEntry()

*/

int readList(struct entry_qb *list){
	for(entry_qb *temp = list;  /*end of list*/ ; temp = temp -> next){
		cout << temp -> firstName << " " << temp -> lastName << " " << temp -> yearWon << endl;
	}
}//End of readList()

int checkEnd(struct entry_qb *list){
	
}

int resetList(struct entry_qb *&list){
	cout << "Inside resetList()" << endl; // test print

	//=== Making all the Concrete Entries
	//list = NULL;//Since this is a resetList function, I want to get list obliterated.

	entry_qb KurtWarner;//making a struct called KurtWarner.
	entry_qb TrentDilfer;
	entry_qb TomBrady0;//TB
	entry_qb BradJohnson;
	entry_qb TomBrady1;//TB
	entry_qb TomBrady2;//TB
	entry_qb BenRoethlisberger0;//BR
	entry_qb PeytonManning;
	entry_qb EliManning0;//EM
	entry_qb BenRoethlisberger1;//BR
	entry_qb DrewBrees;
	entry_qb AaronRodgers;
	entry_qb EliManning1;//EM
	entry_qb JoeFlacco;
	entry_qb RussellWilson;
	entry_qb TomBrady3;//TB



	/*
	entry_qb zip;
	entry_qb glob;
	entry_qb kick;
	list = &zip;
	zip.firstName = "ZIP firstName";
	//cout << list << endl; //list is an address, so if you cout this its a hex address.
	cout << (*list).firstName << endl; // This prints ZIP firstName because you are de-refrencing the poiner list and printing the actuall stuff stored at the location of list
	zip.next = &glob;
	glob.firstName = "Glob firstName";
	glob.next = &kick;
	kick.firstName = "Kick firstName";
	cout << (*list).next -> firstName << endl;
	cout << (*list).next -> next -> firstName << endl;

	This prints out
	HELLO?
	ZIP firstName
	Glob firstName
	Kick firstName
	*/


	list = &KurtWarner;//making the pointer list hold the address of KurtWarner
	KurtWarner.firstName = "Kurt";//inside the struct KurtWarner, there is this thing called firstName, lets store Kurt in it.
	KurtWarner.lastName = "Warner";
	KurtWarner.yearWon = 2000;
	KurtWarner.next = &TrentDilfer;//next is a pointer, lets store the address of TrentDilfer in KurtWarner's next pointer.
	KurtWarner.prev = &TomBrady3;

	TrentDilfer.firstName = "Trent";
	TrentDilfer.lastName = "Dilfer";
	TrentDilfer.yearWon = 2001;
	TrentDilfer.next = &TomBrady0;
	TrentDilfer.prev = &KurtWarner;

	TomBrady0.firstName = "Tom";
	TomBrady0.lastName = "Brady";
	TomBrady0.yearWon = 2002;
	TomBrady0.next = &BradJohnson;
	TomBrady0.prev = &KurtWarner;

	BradJohnson.firstName = "Brad";
	BradJohnson.lastName = "Johnson";
	BradJohnson.yearWon = 2003;
	BradJohnson.next = &TomBrady1;
	BradJohnson.prev = &TomBrady0;

	TomBrady1.firstName = "Tom";
	TomBrady1.lastName = "Brady";
	TomBrady1.yearWon = 2004;
	TomBrady1.next = &TomBrady2;
	TomBrady1.prev = &BradJohnson;

	TomBrady2.firstName = "Tom";
	TomBrady2.lastName = "Brady";
	TomBrady2.yearWon = 2005;
	TomBrady2.next = &BenRoethlisberger0;
	TomBrady2.prev = &TomBrady1;

	BenRoethlisberger0.firstName = "Ben";
	BenRoethlisberger0.lastName = "Roethlisberger";
	BenRoethlisberger0.yearWon = 2006;
	BenRoethlisberger0.next = &PeytonManning;
	BenRoethlisberger0.prev = &TomBrady2;

	PeytonManning.firstName = "Peyton";
	PeytonManning.lastName = "Manning";
	PeytonManning.yearWon = 2007;
	PeytonManning.next = &EliManning0;
	PeytonManning.prev = &BenRoethlisberger0;

	EliManning0.firstName = "Eli";
	EliManning0.lastName = "Manning";
	EliManning0.yearWon = 2008;
	EliManning0.next = &BenRoethlisberger1;
	EliManning0.prev = &PeytonManning;

	BenRoethlisberger1.firstName = "Ben";
	BenRoethlisberger1.lastName = "Roethlisberger";
	BenRoethlisberger1.yearWon = 2009;
	BenRoethlisberger1.next = &DrewBrees;
	BenRoethlisberger1.prev = &EliManning0;

	DrewBrees.firstName = "Drew";
	DrewBrees.lastName = "Brees";
	DrewBrees.yearWon = 2010;
	DrewBrees.next = &AaronRodgers;
	DrewBrees.prev = &BenRoethlisberger1;

	AaronRodgers.firstName = "Aaron";
	AaronRodgers.lastName = "Rodgers";
	AaronRodgers.yearWon = 2011;
	AaronRodgers.next = &EliManning1;
	AaronRodgers.prev = &DrewBrees;

	EliManning1.firstName = "Eli";
	EliManning1.lastName = "Manning";
	EliManning1.yearWon = 2012;
	EliManning1.next = &JoeFlacco;
	EliManning1.prev = &AaronRodgers;

	JoeFlacco.firstName = "Joe";
	JoeFlacco.lastName = "Manning";
	JoeFlacco.yearWon = 2013;
	JoeFlacco.next = &RussellWilson;
	JoeFlacco.prev = &EliManning1;

	RussellWilson.firstName = "Russell";
	RussellWilson.lastName = "Wilson";
	RussellWilson.yearWon = 2014;
	RussellWilson.next = &TomBrady3;
	RussellWilson.prev = &JoeFlacco;

	TomBrady3.firstName = "Tom";
	TomBrady3.lastName = "Brady";
	TomBrady3.yearWon = 2015;
	TomBrady3.next = &KurtWarner;
	TomBrady3.prev = &RussellWilson;

	cout << "list has been reset" << endl;


}//end of populateList()


int listLength(struct entry_qb *list){
	entry_qb *temp = list;
	
	//for(entry_qb *temp = &list; temp !=
}//End of listLength()


int headOrTail(){
	//cout << list << endl;
}//End of headOrTail()


//I want to find the head and the tail by using the year the qb won.
void smallestYearWon(struct entry_qb *&list){
	int yearWonValue = 0;
	entry_qb *temp = list -> next;
	entry_qb *first = list;
	//gdb says you never enter the for loop, check stop logic
	for(temp = first -> next; temp != first; temp = temp -> next){
		//Something is happening to the yearWon value where its making the if statement false.
		if(temp -> yearWon > first -> yearWon){
			if(temp -> yearWon > 10000){
				//do nothing..so far..   Using 10000 for garbage values.
			}else{
			yearWonValue = (temp -> yearWon);
			}
		}else {
			break;
		}
	}
	temp = temp -> next;
	cout << temp -> yearWon << endl;
}//end of smallestYearWon()

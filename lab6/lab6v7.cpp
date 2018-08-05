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
#include <sstream>

using namespace std;

//=== Struct ===
struct entry_qb{
	string firstName;
	string lastName;
	string entryName;
	int arrayYear[4];
	int yearWon;
	int numWins;
	int wins;
	int yesHead;//1 for a head, 2 for a tail, 0 for inbetween NA
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
int readList(entry_qb *list, entry_qb *head);
int listLength(struct entry_qb *list);
void populateList(entry_qb *&list, entry_qb *&head);//case 7
void deleteEnd(entry_qb *list);
int deleteList(entry_qb *&list);
entry_qb *search(entry_qb *list, entry_qb *head, string fName, string lName, int yrWon);

int main(){
	int menuSel = 0;
	clearScreen();
	entry_qb *head = NULL;
	

	//initially the first time you run the program, you want a list to be there.
	populateList(list, head);
//	entry_qb *search(entry_qb *list, entry_qb *head, fName, lName, yrWon)

	menu(menuSel);

	do{	/* Just because you don't like do-while. */
		switch (menuSel){
			case 1: //makeEntry();
				cout << endl << endl;
				menu(menuSel);
				break;
				//case 1 add an entry.
			case 2: readList(list, head);
				cout << endl;
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
			case 7: populateList(list, head);
				cout << endl;
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


void populateList(entry_qb *&list, entry_qb *&head){
	string line, fName, lName;
	int yrWon = 0;
	static int checkRan = 0;
	//entry_qb head;//maybe make head a pointer
	list = NULL;

		//You will be inside the file qbList.txt referened to as infile.
		ifstream infile;
		infile.open("qbListv2.txt");


		//Can you open the file? This will check if it's there or corrupted.
		if (infile.fail()){
			cerr << "Error Opening File." << endl << "File not found, HTTP 404." << endl;
			exit(1);
		}

		entry_qb *temp;

		//Nothing is wrong with qbListv2.txt

		while(infile >> fName >> lName >> yrWon){//While there is a line get it.


			if(list == NULL){
				//This is making the head struct as the first entry from reading the qbListv2.txt
				head = new entry_qb;
				head -> firstName = fName;
				head -> lastName = lName;
				head -> arrayYear[0] = yrWon;
				head -> next = head;
				head -> prev = head;
				head -> yesHead = 1;
				head -> numWins = 1;
				head -> wins = 1;

				//cout << head.firstName << " " << head.lastName<< " " << head.yearWon << endl;
				//prints out just "Kurt Warner 2000"
				//or whatever is the first line in the text file.

				list = head;
				//list is a pointer, and its now storing the address of head in it. so its pointing to head.

				//already making a temp pointer to set up the rest of the list.
				temp = head;

			}else{
				//Now dynamically create entry_qb and store the lines in it. Only if the person was not created before.
				entry_qb *return_qb;
				return_qb = search(list, head, fName, lName, yrWon);

				if(return_qb){
					return_qb -> numWins = return_qb -> numWins + 1;
					return_qb -> arrayYear[return_qb -> numWins - 1];//because array starts at 0
					temp = temp -> next;
					//head -> prev = temp;
					return;
				}else{
					temp -> next = new entry_qb;
					temp -> next -> firstName = fName;
					temp -> next -> lastName = lName;
					temp -> next -> yearWon = yrWon;
					temp -> next -> arrayYear[0] = yrWon;
					temp -> next -> next = head;
					temp -> next -> prev = temp;
					temp -> next -> numWins = 0;
					temp -> next -> wins = 1;
					temp = temp -> next;
					head -> prev = temp;
				}//end of else where if asks if a qb was found



				//cout every entry_qb you made, as a test check
				/*
				cout << temp -> next -> firstName << " ";
				cout << temp -> next -> lastName << " ";
				cout << *temp -> next -> arrayYear << endl;
				*/

			}//end of else statement

		}//end of while loop
	cout << endl;
//	checkDuplicate(list, head);
}//end of populateList()

int deleteList(entry_qb *list){

}//end of deleteList()

int readList(entry_qb *list, entry_qb *head){
	if(list == NULL){
		cout << "No available list." << endl;
	}else{
		int ran = 0;
		for(entry_qb *temp = head; temp != head -> prev; temp = temp -> next){
			if(ran == 0){
				cout << endl;
				cout << head -> firstName << " ";
				cout << head -> lastName << " ";
				cout << *(head -> arrayYear) << endl;
				ran = 1;
				temp = temp -> prev;//this is so it prints out trentDilfer2001
			}else{
				cout << temp -> next -> firstName << " ";
				cout << temp -> next -> lastName << " ";
				cout << *(temp -> next -> arrayYear) << endl;
			}
		}
	}
}//end of readList()



//How do i ask if a previous entry of the same name was made?
entry_qb *search(entry_qb *list, entry_qb *head, string fName, string lName, int yrWon){
	entry_qb *return_qb = new entry_qb;
	return_qb = NULL;
	static int check = 0;
	entry_qb *temp;
	//hey this is a specific check just for head since you cant really
	//start a loop at head and end at head since it a circle.
	if(!(head -> firstName.compare(fName)) && !(head -> lastName.compare(lName))){
		//bryon helped me with the .compare because you can not do == for strings.

		//temp = head -> next;
		check = 1;
		return head;
	}	//he showed my why you use this to compare strings and need the !
		//This is why i am in comp sci 1
	/*
	if (check == 1){
		temp = temp -> next;
	}
	*/

	temp = head -> next;
	//this then pushes to the next entry after the if statement was evaluated or not.

	while (temp != head){
		//Heyyy this entry you just made, does it match a name of a previous entry?
		//if it does match an entry, return that qb inside return_qb
		if(!(temp -> firstName.compare(fName)) && !(temp -> lastName.compare(lName))){
			return_qb = temp;
			return return_qb;
		}
		temp = temp -> next;
	}//end of while loop
	return return_qb;
}//end of checkDuplicate()

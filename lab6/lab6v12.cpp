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

void makeEntry(entry_qb *list, entry_qb *&head);//case 1
int readList(entry_qb *list, entry_qb *head);//case 2
void populateList(entry_qb *&list, entry_qb *&head);//case 7
void deleteEntry(entry_qb *list, entry_qb *&head);//case 5
void deleteList(entry_qb *&list);//case 6

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
			case 1: makeEntry(list, head);
				cout << endl;
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

			case 5: deleteEntry(list, head);
				cout << endl << endl;
				menu(menuSel);
				break;
				//case 5 delete an entry

			case 6: deleteList(list);
				cout << endl;
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

		while(infile >> fName >> lName >> yrWon){
		//While there is a line get it.

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
					temp = return_qb -> next;
					head -> prev = temp;
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

}//end of populateList()



void deleteList(entry_qb *&list){
	list = NULL;
	cout << endl;
	cout << "List has been deleted." << endl;
}//end of deleteList()

void deleteEntry(entry_qb *list, entry_qb *&head){
	string delFirstName;
	string delLastName;
	entry_qb *temp;

	cout << endl;

	if(list == NULL){
		cout << "There is no list, so you can not delete an entry." << endl;
	}else{
		cout << "Enter the first name of the QB that you want to delete." << endl;
		cout << "First Name: ";
		cin  >> delFirstName;
		cout << "Enter the last name of the QB that you want to delete." << endl;
		cout << "Last Name: ";
		cin  >> delLastName;

		if(!(head -> firstName.compare(delFirstName)) && !(head -> lastName.compare(delLastName))){
			entry_qb *holder1 = head -> prev;
			entry_qb *holder2 = head -> next;

			head -> prev -> next = holder2;
			head -> next -> prev = holder1;
			delete head;
		}//end of if statement

		temp = head -> next;

		while(temp != head){
			if(!(temp -> firstName.compare(delFirstName)) && !(temp -> lastName.compare(delLastName))){
				entry_qb *holder1 = temp -> prev;
				entry_qb *holder2 = temp -> next;

				temp -> prev -> next = holder2;
				temp -> next -> prev = holder1;
				delete temp;
			}
			temp = temp -> next;
		}//end of while
	}//end of if else list = null

}//end of deleteEntry()



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
		}//end of for loop
	}
}//end of readList()




//How do i ask if a previous entry of the same name was made?

//This is totaly broken......
entry_qb *search(entry_qb *list, entry_qb *head, string fName, string lName, int yrWon){
	entry_qb *return_qb = new entry_qb;
	return_qb = NULL;
	//entry_qb *temp;

	//hey this is a specific check just for head since you cant really
	//start a loop at head and end at head since it a circle.
	if(!(head -> firstName.compare(fName)) && !(head -> lastName.compare(lName))){
		//bryon helped me with the .compare because you can not do == for string.
		//he showed my why you use this to compare strings and need the !
		//This is why i am in comp sci 1
		entry_qb *temp;
		return_qb = temp;
		temp = head -> next;
		return return_qb;
		//temp = head -> next;//this is a seg fault, but i feel like it should be here
	}//end of if statement to check for head.
	else{/*temp = temp -> next;*/}

	//temp = head -> next;//this has to be somwhere... probably here...//but why head -> next * Assignment PA5a by Professor Derbinsky
 
	//temp = temp -> next;// seg fault here!!!!!!!!!!!!!!!!!!!!!!!
	//okay the reason this seg faults is because after the search function is called
	//there are lines to push temp = temp -> next
	//so if you do it before the function ends, you are accessing un allocatedmemory

	//temp = head -> next;
	//this then pushes to the next entry after the if statement was evaluated or not.

	while (entry_qb *temp != head){
		//Heyyy this entry you just made, does it match a name of a previous entry?
		//if it does match an entry, return that qb inside return_qb
		if(!(temp -> firstName.compare(fName)) && !(temp -> lastName.compare(lName))){
			return_qb = temp;
			return return_qb;
		}
		temp = temp -> next;//temp is storing head tho...

	}//end of while loop

	return return_qb;//returns head

}//end of checkDuplicate()



void makeEntry(entry_qb *list, entry_qb *&head){
	string entFirstName;
	string entLastName;
	int entYearWon;
	entry_qb *temp;

	//alright, lets make an entry boiiiise.
	if(list == NULL){
		//this will make the head if there is no head.
		//First gather the info to input.
		cout << "Enter the first name of the QB you would like to enter to the list." << endl;
		cout << "First Name: ";
		cin  >> entFirstName;
		cout << "Enter the last name of thr QB you would like to enter to the list." << endl;
		cout << "Last Name: ";
		cin  >> entLastName;
		cout << "Enter the year the QB won the super bowl." << endl;
		cout << "Year Won: ";
		cin  >> entYearWon;

		//Now fill the struct with your input.
		head = new entry_qb;
		head -> firstName = entFirstName;
		head -> lastName = entLastName;
		head -> arrayYear[0] = entYearWon;
		head -> next = head;
		head -> prev = head;
		head -> yesHead = 1;
		head -> numWins = 1;
		head -> wins = 1;
		list = head;
		temp = head;
	}else{
		//if the list is not null lets add on an entry.
		cout << "Enter the first name of the QB you would like to enter to the list." << endl;
		cout << "First Name: ";
		cin  >> entFirstName;
		cout << "Enter the last name of thr QB you would like to enter to the list." << endl;
		cout << "Last Name: ";
		cin  >> entLastName;
		cout << "Enter the year the QB won the super bowl." << endl;
		cout << "Year Won: ";
		cin  >> entYearWon;


		temp -> next = new entry_qb;
		temp -> next -> firstName = entFirstName;
		temp -> next -> lastName = entLastName;
		temp -> next -> yearWon = entYearWon;
		temp -> next -> arrayYear[0] = entYearWon;
		temp -> next -> next = head;
		temp -> next -> prev = temp;
		temp -> next -> numWins = 1;
		temp -> next -> wins = 1;//my gosh i have so many things for the same shit.
		temp = temp -> next;
		head -> prev = temp;

	}//end of if else to make new entries
	cout << endl;
	cout << entFirstName << entLastName << entYearWon << "has been added to the list." << endl;
	cout << endl;
}//end of makeEntry()

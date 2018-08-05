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
	int wins;// not used
	int yesHead;//not used

	entry_qb *next; //points to the next struct in the list
	entry_qb *prev; //points to the previous struct in the list
};


entry_qb *list = NULL;
//=== Function Prototype ===
void menu(int &menuSel);
void clearScreen();
void exitProgram();
void testPrint(int menuSel);

void makeEntry(entry_qb *list);//case 1
int readList(entry_qb *list, entry_qb *head);//case 2
void searchNameYearNum(entry_qb *list, entry_qb *head);//case 3

void deleteEntry(entry_qb *list, entry_qb *head);//case 5
void deleteList(entry_qb *&list, entry_qb *head);//case 6
void populateList(entry_qb *&list, entry_qb *&head);//case 7


entry_qb *search(entry_qb *list, entry_qb *head, string fName, string lName, int yrWon);

int main(){
	int menuSel = 0;
	clearScreen();
	entry_qb *head = NULL;


	//initially the first time you run the program, you want a list to be there.
	populateList(list, head);
	menu(menuSel);

	do{	/* Just because you don't like do-while. */
		switch (menuSel){
			case 1: makeEntry(list);
				cout << endl;
				menu(menuSel);
				break;
				//case 1 add an entry.

			case 2: readList(list, head);
				cout << endl;
				menu(menuSel);
				break;
				//case 2 read full list to screen

			case 3: searchNameYearNum(list, head);
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

			case 6: deleteList(list, head);
				cout << endl;
				menu(menuSel);
				break;
				//case 6 remove all entries

			case 7: populateList(list, head);
				cout << "The list has been reset." << endl << endl;
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

				//iniializing the arrayYear to 0 and what the file said.
				head -> arrayYear[0] = yrWon;
				head -> arrayYear[1] = 0;
				head -> arrayYear[2] = 0;
				head -> arrayYear[3] = 0;

				head -> next = head;
				head -> prev = head;
				head -> numWins = 1;

				list = head;
				//list is a pointer, and its now storing the address of head in it. so its pointing to head.
				//Seriously list and head are the same thing so its redundant.

				//already making a temp pointer to set up the rest of the list.
				temp = head;

			}else{
				//Now dynamically create entry_qb and store the lines in it. Only if the person was not created before.
				entry_qb *return_qb;//this equals NULL at the start of search() funciton.
				return_qb = search(list, head, fName, lName, yrWon);

				if(return_qb){
					return_qb -> numWins = (return_qb -> numWins) + 1;
					return_qb -> arrayYear[return_qb -> numWins -1] = yrWon;
					//because array starts at 0, and everyone initially has a numWin value of 1.

					temp = head -> prev;// so you can start at the end of the "tail"
				}else{
					temp -> next = new entry_qb;
					temp -> next -> firstName = fName;
					temp -> next -> lastName = lName;
					temp -> next -> yearWon = yrWon;

					//initializing my arrayYear to store yrWon
					temp -> next -> arrayYear[0] = yrWon;
					temp -> next -> arrayYear[1] = 0;
					temp -> next -> arrayYear[2] = 0;
					temp -> next -> arrayYear[3] = 0;

					temp -> next -> next = head;
					temp -> next -> prev = temp;
					temp -> next -> numWins = 1;
					temp = temp -> next;
					head -> prev = temp;
				}//end of else where if asks if a qb was found

			}//end of else statement

		}//end of while loop
	cout << endl;

}//end of populateList()



void deleteList(entry_qb *&list, entry_qb *head){
	//not really deleting the list, its just orphaning the list.
	//so loop backwards and do a delete entry function from if head and while temp != head
	int ran = 0;
	for(entry_qb *temp = head; temp != head -> prev; temp = temp -> next){
		if(ran == 0){
			entry_qb *holder1 = head -> prev;
			entry_qb *holder2 = head -> next;

			head -> prev -> next = holder2;
			head -> next -> prev = holder1;

			ran = 1;
			temp = temp -> prev;//this is so it prints out trentDilfer2001
			delete head;
		}else{
			entry_qb *holder1 = temp -> prev;
			entry_qb *holder2 = temp -> next;

			temp -> prev -> next = holder2;
			temp -> next -> prev = holder1;
			delete temp;
		}
		list = NULL;
	}//end of for loop
	cout << endl << "The list has been deleted." << endl;
}//end of deleteList()


void deleteEntry(entry_qb *list, entry_qb *head){
	string delFirstName;
	string delLastName;
	entry_qb *temp;
	int check = 0;

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
			check = 1;
			cout << endl << delFirstName << " " << delLastName << " was deleted.";
		}//end of if statement

		temp = head -> next;

		while(temp != head){
			if(!(temp -> firstName.compare(delFirstName)) && !(temp -> lastName.compare(delLastName))){
				entry_qb *holder1 = temp -> prev;
				entry_qb *holder2 = temp -> next;

				temp -> prev -> next = holder2;
				temp -> next -> prev = holder1;
				delete temp;
				check = 1;
				cout << endl << delFirstName << " " << delLastName << " was deleted.";
			}
			temp = temp -> next;

		}//end of while

	}//end of if else list = null
	if(check == 0){
		cout << "No QB of " << delFirstName << " " << delLastName << " was found in the list.";
	}
}//end of deleteEntry()



int readList(entry_qb *list, entry_qb *head){
	if(list == NULL){
		cout << endl << "No available list." << endl;
	}else{
		int ran = 0;

		for(entry_qb *temp = head; temp != head -> prev; temp = temp -> next){
			if(ran == 0){
				cout << endl;
				cout << head -> firstName << " ";
				cout << head -> lastName << " ";
				for(int i = 0; i != head -> numWins; i++){
					cout << (head -> arrayYear[i]);
					cout << " ";
				}
				cout << endl;
				ran = 1;
				temp = temp -> prev;//this is so it prints out trentDilfer2001
			}else{
				cout << temp -> next -> firstName << " ";
				cout << temp -> next -> lastName << " ";
				for(int i = 0; i != temp -> next -> numWins; i++){
					cout << (temp -> next -> arrayYear[i]);
					cout << " ";
				}//end of for loop
				cout << endl;
			}//end of if else
		}//end of for loop
	}//end of if else
}//end of readList()




//How do i ask if a previous entry of the same name was made?
entry_qb *search(entry_qb *list, entry_qb *head, string fName, string lName, int yrWon){
	entry_qb *return_qb;
	return_qb = NULL;
	entry_qb *temp;


	//hey this is a specific check just for head since you cant really
	//start a loop at head and end at head since it a circle.
	if(!(head -> firstName.compare(fName)) && !(head -> lastName.compare(lName))){
		//bryon helped me with the .compare because you can not do == for string.
		//he showed my why you use this to compare strings and need the !
		//This is why i am in comp sci 1
		return_qb = temp;
		return return_qb;//returns head if it was found.
	}//end of if statement to check for head.


	temp = head -> next;
	//This temp = head -> next is here so the while loop will start checking
	//at the second position of the list.


	while (temp != head){
		//Heyyy this entry you just made, does it match a name of a previous entry?
		//if it does match an entry, return that qb inside return_qb

		//hey does temp -> lastName have any differences from lName? if yes, return 1.
		//in our situation, there are no differences in the strings so the compare results in a 0
		//then we do the NOT of 0 and get a 1.
		if(!(temp -> firstName.compare(fName)) && !(temp -> lastName.compare(lName))){
			return_qb = temp;
			return return_qb;//returns the entry that matched to populate list.
		}
		temp = temp -> next;

	}//end of while loop

	return return_qb;//returns NULL

}//end of checkDuplicate()



void makeEntry(entry_qb *list){
	string entFirstName;
	string entLastName;
	int entYearWon;

	entry_qb *temp;
	entry_qb *head = list;

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

	if(list == NULL){
		//this will make the head if there is no head.
		//Now fill the struct with your input.
		head = new entry_qb;
		head -> firstName = entFirstName;
		head -> lastName = entLastName;
		head -> arrayYear[0] = entYearWon;
		head -> next = head;
		head -> prev = head;

		head -> numWins = 1;
		list = head;
		temp = head;//starting the list at the head.

	}else{
		//Now dynamically create entry_qb and store the lines in it. Only if the person was not created before.
		entry_qb *return_qb = NULL;//this equals NULL at the start of search() funciton.
		return_qb = search(list, head, entFirstName, entLastName, entYearWon);
		//we are changing the arguments in this function to be different from the prototype.

		//if(return_qb) == NULL skip the if statement code block
		if(return_qb){
			return_qb -> numWins = (return_qb -> numWins) + 1;
			return_qb -> arrayYear[return_qb -> numWins -1] = entYearWon;
			//because array starts at 0, and everyone initially has a numWin value of 1.

			temp = head -> prev;// so you can start at the end of the "tail"
		}else{

			//if the list is not null lets add on an entry.
			temp = head -> prev;
			temp -> next = new entry_qb;
			temp -> firstName = entFirstName;
			temp -> lastName = entLastName;
			temp -> yearWon = entYearWon;
			temp -> arrayYear[0] = entYearWon;
			temp -> next -> next = head;
			temp -> next -> prev = temp;
			temp -> numWins = 1;


			//this says
			//temp = head
			//head ->prev = head;
			//temp = temp -> next;//pushes temp to the next entry_qb, which is head

			head -> prev = temp -> next;//links head to the tail
		}//end of if else
	}//end of if else to make new entries
	cout << endl;
	cout << entFirstName << " " << entLastName << " " << entYearWon << " has been added to the list." << endl;
	cout << endl;
}//end of makeEntry()


void searchNameYearNum(entry_qb *list, entry_qb *head){
	int menuSel = 0;
	string fName, lName;
	int yrWon;
	bool menuLoop = 1;
	if(list == NULL){
		cout << endl << "No available list, you should reset the list or add an entry.";
	}else{

		cout << endl;
		cout << "Select 1 to search for a QB's name." << endl;
		cout << "Select 2 to seach for a QB by year." << endl;
		cout << "Select 3 to search for a QB by number of wins." << endl;
		cout << "Selecting: ";
		cin  >> menuSel;
		cout << endl;

		while(menuLoop){
			if(menuSel == 1){
				//Search for a name.
				cout << "Enter the QB's first name." << endl << "First Name: ";
				cin  >> fName;
				cout << "Enter the QB's last name." << endl << "Last Name: ";
				cin  >> lName;
				cout << endl;

				//making return_qb so I can store the output of the function.
				entry_qb *return_qb;

				//the 1 in the function search is here so i can just pass 1, its not used, but the parameters are there so i can search by year won later.
				return_qb = search(list, head, fName, lName, 1);

				if(return_qb){
					cout << fName << " " << lName << " " << "was found in the list.";
				}else{
					cout << "No QB of name " << fName << " " << lName << " exists in the list.";
				}

				menuLoop = 0;
			}else if(menuSel == 2){
				//search for a year
				cout << "Enter the year you would like to search for." << endl << "Year: ";
				cin  >> yrWon;

				entry_qb *return_qb;
				return_qb = NULL;
				entry_qb *temp;

				if(head -> arrayYear[0] == yrWon || head -> arrayYear[1] == yrWon || head -> arrayYear[2] == yrWon || head -> arrayYear[3] == yrWon){
					return_qb = temp;
				}//end of if statement to check for head.

				temp = head -> next;

				while (temp != head){
					if(temp -> arrayYear[0] == yrWon || temp -> arrayYear[1] == yrWon || temp -> arrayYear[2] == yrWon || temp -> arrayYear[3] == yrWon){
						return_qb = temp;
					}
					temp = temp -> next;

				}//end of while loop

				//return_qb will be NULL here if nothing is found
				if(return_qb){
					cout << endl << return_qb -> firstName << " " << return_qb -> lastName << " won the super bowl in " << yrWon << ".";
				}else{
					cout << endl << "No QB in the list has won in the year " << yrWon << ".";
				}

				menuLoop = 0;
			}else if(menuSel == 3){
				//search by number of wins.
				int wins = 0;

				entry_qb *return_qb = NULL;
				entry_qb *temp;

				cout << "Enter the number of times that a QB might have won the super bowl." << endl << "Number of Wins: ";
				cin  >> wins;
				cout << endl;

				if(head -> numWins >= wins){
					return_qb = temp;
					cout << head -> firstName << " " << head -> lastName << endl;
				}
				temp = head -> next;

				while (temp != head){
					if(temp -> numWins >= wins){
						return_qb = temp;
						cout << temp -> firstName << " " << temp -> lastName << endl;
					}
					temp = temp -> next;
				}//end of while loop

				if(return_qb){
					if(wins == 1){
						cout << endl << "These QBs were found in the list with at least " << wins << " win.";
					}else{
						cout << endl << "These QBs were found in the list with at least " << wins << " wins.";
					}
				}else{
					if(wins == 1){
						cout << "No QBs were found in the list with at least " << wins << " win." << endl;
						cout << "Because the list is empty";
					}else{
						cout << "No QBs were found in the list with at least " << wins << " wins.";
					}
				}

				menuLoop = 0;
			}else{
				cout << endl << "You did not select an option." << endl << "Selecting: ";
				cin >> menuSel;
				menuLoop = 1;
			}
		}//end of while loop
	}//end of big if else where if(list == NULL)
}//end of searchNameYearNum()


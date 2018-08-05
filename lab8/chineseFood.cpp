/**
 * Chinese food
 */

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void clearScreen(){
	for(int i = 0; i < 50; i++){
		cout << endl;
	}
}

int menuSel(){
	int sel = 0;
	cout << endl;
	cout << "Select 1 to enter an item." << endl;
	cout << "Select 2 to read the list." << endl;
	cout << "Select 3 to exit the program." << endl;
	cout << "Selecting: ";
	cin  >> sel;
	cout << endl;
	return sel;
}

void printList(string list[150]){
	cout << endl;
	cout << "/=== Current Chinese Food List ===\\" << endl;
	for(int i = 0; i < 150; i++){
		if(!list[i].compare("NULL")){
			//do nothing
		}else{
			cout << list[i] << endl;
		}
	}
	cout << "/=================================\\" << endl;
}//end of printList

void add2List(string (&list)[150]){
	for(int i = 0; i < 150; i++){
		if(!list[i].compare("NULL")){
			string item;
			cout << "Enter a chinese food item." << endl;
			cout << "Item: ";
			//cin  >> item;
			//list[i] = item;
			cin.ignore();
			getline(cin, item);
			list[i] = item;
			
			break;
		}else{
			//do nothing because an item was entered.
		}
	}
}

void write2File(string list[150]){
	ofstream myFile;
	myFile.open("chineseFoodList.txt");
	myFile << "/=== Current Chinese Food List ===\\\n"; 

	for(int i = 0; i < 150; i++){
		if(!list[i].compare("NULL")){
			//do nothing
		}else{
			myFile << list[i] + "\n";
		}
	} 
	myFile << "/=================================\\\n";
	myFile.close();
}

int main(){
	//int 150 = 150;
	string list[150];
	for(int i = 0; i < 150; i++){
		list[i] = "NULL";
	}
	int grab = 0;


	clearScreen();
	do{
		grab = menuSel();
		switch(grab){
			case 1:add2List(list);
				break;

			case 2: printList(list);
				break;

			default:cout << "Exiting Program. . ." << endl;
				write2File(list);
				return 0;
				break;
		};

	}while(grab != 3);
	return 0;
}//end of main

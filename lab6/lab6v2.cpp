/*
 * Mike Hickey
 * Professor Carpenter
 * Lab6 Doubly Linked Circular List
 * Due Date 10/17/16
 */

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;


/*===== Struct QB =========*/
        struct qb{
                string qbFirstName;
                string qbLastName;
                string qbEntryName;
                int qbYears;
                int qbNumWins;
                qb *qbForwards;
                qb *qbBackwards;
        };
        //qb *first;
        //qb *last;

/*=== Function Prototype ===*/
void resetList(qb *first, qb *last);
void printForward(qb *first);
void clearScreen();
void menu(int &menuSel);

//void makeStruct();
void makeEntry();
int  exitProgram();


void testPrint(int menuSel);

/*==========================*/

int main(){

/*=== Local Variable Declaration ===*/
int menuSel = 0;	//This is being commented because it needs to be in the while loop. Every variable might need to be in the while loop.
int i = 0;
/*==================================*/
	//do {
		//makeStruct();
		qb *first = 0;
		qb *last = 0;
		clearScreen();
		menu(menuSel);
		switch (menuSel){
			case 1: testPrint(menuSel);
				makeEntry();
				break;
				//case 1 add an entry
			case 2: testPrint(menuSel);
				resetList(first, last);
				printForward(first);
				break;
				//case 2 read full list
			case 3: testPrint(menuSel);
				break;
				//case 3 search for year name number
			case 4: testPrint(menuSel);
				break;
				//case 4 sort alphabetically
			case 5: testPrint(menuSel);
				break;
				//case 5 delete an entry
			case 6: testPrint(menuSel);
				break;
				//case 6 remove all entries
			case 7: resetList(first, last);
				break;
				//case 7 reset list to original
			default:exitProgram();
				break;
				//default will exit the program.

		}//end of switch(menuSel)
	//	i++;
	//}while (i < 5);//end of do-while loop

}//end of main.

void resetList(){
	//makeStruct();
	qb *first;
	qb *last;
	qb *newqb;
	
	newqb = new qb;// this is overwriting every address and not saving it.
	newqb -> qbFirstName = "Kurt";
	newqb -> qbLastName = "Warner";
	newqb -> qbEntryName = "KW";
	newqb -> qbYears = 2000;
	newqb -> qbNumWins = 1;
	newqb -> qbBackwards = NULL;
	first = newqb;
	last = newqb;

	newqb = new qb;
	newqb -> qbFirstName = "Trent";
        newqb -> qbLastName = "Dilfer";
        newqb -> qbEntryName = "TD";
        newqb -> qbYears = 2001;
        newqb -> qbNumWins = 1;
	newqb -> qbBackwards = last;
	last -> qbForwards = newqb;
	last = newqb;

        newqb = new qb;
        newqb -> qbFirstName = "Tom";
        newqb -> qbLastName = "Brady";
        newqb -> qbEntryName = "TB";
        newqb -> qbYears = 2002;
        newqb -> qbNumWins = 4;
        newqb -> qbBackwards = last;
        last -> qbForwards = newqb;
        last = newqb;

        newqb = new qb;
        newqb -> qbFirstName = "Brad";
        newqb -> qbLastName = "Johnson";
        newqb -> qbEntryName = "BJ";
        newqb -> qbYears = 2003;
        newqb -> qbNumWins = 1;
        newqb -> qbBackwards = last;
        last -> qbForwards = newqb;
        last = newqb;

        newqb = new qb;
        newqb -> qbFirstName = "Tom";
        newqb -> qbLastName = "Brady";
        newqb -> qbEntryName = "TB";
        newqb -> qbYears = 2004;
        newqb -> qbNumWins = 4;
        newqb -> qbBackwards = last;
        last -> qbForwards = newqb;
        last = newqb;

        newqb = new qb;
        newqb -> qbFirstName = "Tom";
        newqb -> qbLastName = "Brady";
        newqb -> qbEntryName = "TB";
        newqb -> qbYears = 2005;
        newqb -> qbNumWins = 4;
        newqb -> qbBackwards = last;
        last -> qbForwards = newqb;
        last = newqb;

        newqb = new qb;
        newqb -> qbFirstName = "Ben";
        newqb -> qbLastName = "Roethlisberger";
        newqb -> qbEntryName = "BR";
        newqb -> qbYears = 2006;
        newqb -> qbNumWins = 2;
        newqb -> qbBackwards = last;
        last -> qbForwards = newqb;
        last = newqb;

        newqb = new qb;
        newqb -> qbFirstName = "Peyton";
        newqb -> qbLastName = "Manning";
        newqb -> qbEntryName = "PM";
        newqb -> qbYears = 2007;
        newqb -> qbNumWins = 1;
        newqb -> qbBackwards = last;
        last -> qbForwards = newqb;
        last = newqb;

        newqb = new qb;
        newqb -> qbFirstName = "Eli";
        newqb -> qbLastName = "Manning";
        newqb -> qbEntryName = "EM";
        newqb -> qbYears = 2008;
        newqb -> qbNumWins = 2;
        newqb -> qbBackwards = last;
        last -> qbForwards = newqb;
        last = newqb;

        newqb = new qb;
        newqb -> qbFirstName = "Ben";
        newqb -> qbLastName = "Roethlisberger";
        newqb -> qbEntryName = "BR";
        newqb -> qbYears = 2009;
        newqb -> qbNumWins = 2;
        newqb -> qbBackwards = last;
        last -> qbForwards = newqb;
        last = newqb;

        newqb = new qb;
        newqb -> qbFirstName = "Drew";
        newqb -> qbLastName = "Brees";
        newqb -> qbEntryName = "DB";
        newqb -> qbYears = 2010;
        newqb -> qbNumWins = 1;
        newqb -> qbBackwards = last;
        last -> qbForwards = newqb;
        last = newqb;

        newqb = new qb;
        newqb -> qbFirstName = "Aaron";
        newqb -> qbLastName = "Rodgers";
        newqb -> qbEntryName = "AR";
        newqb -> qbYears = 2011;
        newqb -> qbNumWins = 1;
        newqb -> qbBackwards = last;
        last -> qbForwards = newqb;
        last = newqb;

        newqb = new qb;
        newqb -> qbFirstName = "Eli";
        newqb -> qbLastName = "Manning";
        newqb -> qbEntryName = "EM";
        newqb -> qbYears = 2012;
        newqb -> qbNumWins = 2;
        newqb -> qbBackwards = last;
        last -> qbForwards = newqb;
        last = newqb;

        newqb = new qb;
        newqb -> qbFirstName = "Joe";
        newqb -> qbLastName = "Flacco";
        newqb -> qbEntryName = "JF";
        newqb -> qbYears = 2013;
        newqb -> qbNumWins = 1;
        newqb -> qbBackwards = last;
        last -> qbForwards = newqb;
        last = newqb;

        newqb = new qb;
        newqb -> qbFirstName = "Russell";
        newqb -> qbLastName = "Wilson";
        newqb -> qbEntryName = "RW";
        newqb -> qbYears = 2014;
        newqb -> qbNumWins = 1;
        newqb -> qbBackwards = last;
        last -> qbForwards = newqb;
        last = newqb;

        newqb = new qb;
        newqb -> qbFirstName = "Tom";
        newqb -> qbLastName = "Brady";
        newqb -> qbEntryName = "TB";
        newqb -> qbYears = 2015;
        newqb -> qbNumWins = 4;
        newqb -> qbBackwards = last;
        last -> qbForwards = newqb;
        last = newqb;
	last -> qbForwards = NULL;

	//printForward(first);


	/*
	//This is hard coding, NO NO NO
	qb qb1, qb2, qb3, qb4, qb5;
	qb qb6, qb7, qb8, qb9, qb10;
	qb qb11, qb12, qb13, qb14, qb15, qb16;

	qb1.qbFirstName = "Kurt";
	qb1.qbLastName = "Warner";
	qb1.qbEntryName = "KW";
	qb1.qbYears = 2000;
	qb1.qbNumWins = 1;
	qb1.qbForwards = &qb2;
	qb1.qbBackwards = NULL;

	qb2.qbFirstName = "Trent";
        qb2.qbLastName = "Dilfer";
        qb2.qbEntryName = "TD";
        qb2.qbYears = 2001;
        qb2.qbNumWins = 1;
        qb2.qbForwards = qb3;
        qb2.qbBackwards = &qb1;

        qb3.qbFirstName = "Tom";
        qb3.qbLastName = "Brady";
        qb3.qbEntryName = "TB";
        qb3.qbYears = 2002;
        qb3.qbNumWins = 4;
        qb3.qbForwards = &qb4;
        qb3.qbBackwards = &qb2;

        qb4.qbFirstName = "Brad";
        qb4.qbLastName = "Johnson";
        qb4.qbEntryName = "BJ";
        qb4.qbYears = 2003;
        qb4.qbNumWins = 1;
        qb4.qbForwards = &qb5;
        qb4.qbBackwards = &qb3;

        qb5.qbFirstName = "Tom";
        qb5.qbLastName = "Brady";
        qb5.qbEntryName = "TB";
        qb5.qbYears = 2004;
        qb5.qbNumWins = 4;
        qb5.qbForwards = &qb6;
        qb5.qbBackwards = &qb4;

        qb6.qbFirstName = "Tom";
        qb6.qbLastName = "Brady";
        qb6.qbEntryName = "TB";
        qb6.qbYears = 2005;
        qb6.qbNumWins = 4;
        qb6.qbForwards = &qb7;
        qb6.qbBackwards = &qb5;

        qb7.qbFirstName = "Ben";
        qb7.qbLastName = "Roethlisberger";
        qb7.qbEntryName = "BR";
        qb7.qbYears = 2006;
        qb7.qbNumWins = 2;
        qb7.qbForwards = &qb8;
        qb7.qbBackwards = &qb6;

        qb8.qbFirstName = "Peyton";
        qb8.qbLastName = "Manning";
        qb8.qbEntryName = "PM";
        qb8.qbYears = 2007;
        qb8.qbNumWins = 1;
        qb8.qbForwards = &qb9;
        qb8.qbBackwards = &qb7;

        qb9.qbFirstName = "Eli";
        qb9.qbLastName = "Manning";
        qb9.qbEntryName = "EM";
        qb9.qbYears = 2008;
        qb9.qbNumWins = 2;
        qb9.qbForwards = &qb10;
        qb9.qbBackwards = &qb8;

        qb10.qbFirstName = "Ben";
        qb10.qbLastName = "Roethlisberger";
        qb10.qbEntryName = "BR";
        qb10.qbYears = 2009;
        qb10.qbNumWins = 2;
        qb10.qbForwards = &qb11;
        qb10.qbBackwards = &qb9;

        qb11.qbFirstName = "Drew";
        qb11.qbLastName = "Brees";
        qb11.qbEntryName = "DB";
        qb11.qbYears = 2010;
        qb11.qbNumWins = 1;
        qb11.qbForwards = &qb12;
        qb11.qbBackwards = &qb10;

        qb12.qbFirstName = "Aaron";
        qb12.qbLastName = "Rodgers";
        qb12.qbEntryName = "AR";
        qb12.qbYears = 2011;
        qb12.qbNumWins = 1;
        qb12.qbForwards = &qb13;
        qb12.qbBackwards = &qb11;

        qb13.qbFirstName = "Eli";
        qb13.qbLastName = "Manning";
        qb13.qbEntryName = "EM";
        qb13.qbYears = 2012;
        qb13.qbNumWins = 2;
        qb13.qbForwards = &qb14;
        qb13.qbBackwards = &qb12;

        qb14.qbFirstName = "Joe";
        qb14.qbLastName = "Flacco";
        qb14.qbEntryName = "JF";
        qb14.qbYears = 2013;
        qb14.qbNumWins = 1;
        qb14.qbForwards = &qb15;
        qb14.qbBackwards = &qb13;

        qb15.qbFirstName = "Russell";
        qb15.qbLastName = "Wilson";
        qb15.qbEntryName = "RW";
        qb15.qbYears = 2014;
        qb15.qbNumWins = 1;
        qb15.qbForwards = &qb16;
        qb15.qbBackwards = &qb14;

        qb16.qbFirstName = "Tom";
        qb16.qbLastName = "Brady";
        qb16.qbEntryName = "TB";
        qb16.qbYears = 2015;
        qb16.qbNumWins = 4;
        qb16.qbForwards = NULL;
        qb16.qbBackwards = &qb15;


	/*This really is not resetting the list. its making a file. redo this*/
	/*
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
	*/

}//end of resetList

void printForward(qb *first){
	qb *temp = first;
	while(temp != NULL){
		cout << temp -> qbFirstName << " " << temp -> qbLastName << " " << temp -> qbYears << endl;
		temp = temp -> qbForwards;
	}
	cout << endl;
}//end of printForward


void clearScreen(){
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}//end of clearScreen


void menu(int &menuSel){
	cout << "Select 1 to add an entry to the list.\nSelect 2 to read the list.\nSelect 3 to Search for year/name/number.\nSelect 4 to sort the list in alphabetical order.\nSelect 5 to delete an entry.\nSelect 6 to remove all entries.\nSelect 7 to reset the list.\nSelect 8 to exit the program.\nSelecting: ";
	cin  >> menuSel;
}//end of menu


/*
void makeStruct(){
	struct qb{
		string qbFirstName;
		string qbLastName;
		string qbEntryName;
		int qbYears;
		int qbNumWins;
		qb *qbForwards;
		qb *qbBackwards;
	};
	qb *first;
	qb *last;


}//end of make struct
*/


void makeEntry(){
	
	/*
	//makeStruct();
	qb *newqb; // This is a temporary struct to hold the new struct we will make.
	newqb = new qb; // temp is pointing to a new qb.

        string firstName;
        string lastName;
        string entryName;
        int years;
        int numWins;

	cout << "Enter the initials of the QB to be stored as a node entry.\n: ";
	cin  >> entryName;
	cout << "Enter the QB's first name.\n: ";
	cin  >> firstName;
	cout << "Enter the QB's last name.\n: ";
	cin  >> lastName;
	cout << "Enter the year that the QB won the superbowl.\n: ";
	cin  >> years;

	newqb -> qbEntryName = entryName;//go and find the qb who is referenced by the newqb pointer, inside that qb there is a variable called qbEntryName, and we want to store whatever the user entered in for entryName inside qbEntryName.
	newqb -> qbFirstName = firstName;
	newqb -> qbLastName = lastName;
	newqb -> qbYears = years;
	newqb -> qbNumWins = numWins;

	newqb -> qbBackwards = NULL;	//The temporary qb will point backwards to null.
	first = newqb;
	last = newqb;



	/*
	cout << "Enter a QB's first name.\n: ";
	cin  >> firstName;
	cout << "Enter a QB's last name.\n: ";
	cin  >> lastName;
	cout << "Enter the year the QB won a super bowl.\n: ";
	cin  >> years;
	*/

}//end of make entry

int exitProgram(){
	cout << "Exiting Program. . .\n";
	exit(0);
}//End of exitProgram

void testPrint(int menuSel){
	cout << "Testing... "<< menuSel << " \n";
}//end of testPrint


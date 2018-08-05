#include <stdio.h>
#include <string>
#include <iostream>
#include <string.h>


using namespace std;

/*====== Function Declaration =====*/
int encrypting(string message, int stringLength);
int decrypting(string message, int stringLength);

int main(){
/*== Variable Declaration and Initializarion ==*/
string message;//This holds the users inputted message.

char printOut;//This is the output from the stringArray function.
char buffer[9999];

unsigned long int stringLength;//This holds the user's inputted string and counts all the slots in it.
int i=0;
int menuSel=0;
/*=============================================*/

cout << "/=== Crypography ===/\n";
/*==== Obtaining The User's Input Message =====*/
	cout << "Input a message.\n: ";
	getline (cin,message);
	stringLength = message.length();
	//cout << "String Length is: " << stringLength << "\n";
	//cout << "Original message was: " << message << "\n";

/*=== Building a menu to do whatever with the message ===*/
cout << "Input 1 to encrypt the message.\n";
cout << "Input 2 to decrypt the message.\n";
cout << "Input 3 to exit the program.\n";
cout << "Selecting: ";
cin  >> menuSel;

if(menuSel==1){
	cout << "/=== Encrypting Your Secrets ===/\n";
	printOut = encrypting(message, stringLength);

}//end of encrypting prompt

if(menuSel==2){
	cout << "/=== Decrypting Your Secrets ===/\n";
	printOut = decrypting(message, stringLength);

}//end of decrypting prompt

else if(menuSel==3){
	cout << "Exiting Program . . .\n";
	return 0;
}
}//end of main


int encrypting(string message, int stringLength){
	char buffer[9999];
	int i=0;

	for (i=0;i<=stringLength-1;i++){
	//cout << message[i] <<" ";
	//cout << message[i] +1 << "\n";
	if (message[i] == 126){
	buffer[i] = message[i]+2;
	}
	else{
	buffer[i] = message[i]+1;
	}
	}// end of for loop

	cout << "Your encrypted message is: ";
	cout << buffer << "\n";


}//end of encrypting

int decrypting(string message, int stringLength){
	char buffer[9999];
        int i=0;

        for (i=0;i<=stringLength-1;i++){
        //cout << message[i] <<" ";
        //cout << message[i] -1 << "\n";
	if (message[i]==128){
	buffer[i] = message[i]-2;
	}
	else{
	buffer[i] = message[i]-1;
	}//end of else
        }// end of for loop

	cout << "Your decrypted message is: ";
        cout << buffer << "\n";

}//end of decrypting

/*==== This .cpp is the file that I would like graded ===*/
#include <stdio.h>
#include <string>
#include <iostream>
#include <string.h>
#include <bitset>


using namespace std;

/*====== Function Declaration =====*/
int encrypting(string message, int stringLength, int keyLength, string key, int menuSel);

int main(){
/*== Variable Declaration and Initializarion ==*/
string message;//This holds the users inputted message.
string key;//This holds the users inputted Key.

char printOut;//This is the output from the stringArray function.

unsigned long int keyLength;//This holds the user's inputted key string and counts all the slots in it.
unsigned long int stringLength;//This holds the user's inputted message string and counts all the slots in it.

int i=0;
int menuSel=0;
/*=============================================*/

cout << "/=== Crypography ===/\n";
/*==== Obtaining The User's Input Message =====*/
	cout << "Input a message.\n: ";
	getline (cin,message);
	stringLength = message.length();

/*====== Taking A User Input String As A Key =======*/
	cout << "Input an encrypy/decrypt key.\n: ";
	getline (cin,key);
	keyLength = key.length();

/*=== Building a menu to do whatever with the message ===*/
cout << "Input 1 to encrypt the message.\n";
cout << "Input 2 to decrypt the message.\n";
cout << "Input 3 to exit the program.\n";
cout << "Selecting: ";
cin  >> menuSel;

if(menuSel==1){
	cout << "/=== Encrypting Your Secrets ===/\n";
	printOut = encrypting(message, stringLength,keyLength, key, menuSel);

}//end of encrypting prompt

if(menuSel==2){
	cout << "/=== Decrypting Your Secrets ===/\n";
	printOut = encrypting(message, stringLength, keyLength, key, menuSel);

}//end of decrypting prompt

else if(menuSel==3){
	cout << "Exiting Program . . .\n";
	return 0;
}
}//end of main


int encrypting(string message, int stringLength, int keyLength, string key, int menuSel){
	char bitXor[9999];//The individual chars after they have been XOR-ed.
	char encrypt[9999];//This is just XOR-ed again... I dont even need this.
	int intBuffer;//This is the length of the message + the length of the key.
	int i=0;//Used to count though the stringLength loop.

	//This is XOR-ing every individual char with the length of the stringLength.
	for (i=0;i<=stringLength-1;i++){	//stringLength -1 becasue subtracting the termination of the string.
		intBuffer = stringLength + keyLength;
		bitXor[i] = message[i] ^ intBuffer;
		encrypt[i] = bitXor[i];
	}//end of for loop stringLength

	if (menuSel==1){
		cout << "Your encrypted message is: " << encrypt << "\n";
	}
	if (menuSel==2){
		cout << "Your decrypted message is: " << encrypt << "\n";
	}
}//end of encrypting

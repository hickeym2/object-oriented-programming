/*=== This is NOT to be graded ===*/
/*=== I am including this experiment .cpp because I did a lot of work for this lab ===*/
#include <stdio.h>
#include <string>
#include <iostream>
#include <string.h>
#include <bitset>

using namespace std;

/*====== Function Declaration =====*/
int cryptography(string message, int stringLength, int keyLength, string key, int menuSel);

int main(){

/*== Variable Declaration and Initializarion ==*/
string message;//This holds the users inputted message.
string key;

char printOut;//This is the output from the stringArray function.
char buffer[9999];

unsigned long int keyLength;//This holds the user's inputted key string and counts all the slots in it.
unsigned long int stringLength;//This holds the user's inputted message string and counts all the slots in it.
//I wanted a lot of numbers so i used unsigned long int.

int i=0;
int menuSel=0;

/*================ Headder ====================*/
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
	printOut = cryptography(message, stringLength,keyLength, key, menuSel);
}//end of encrypting prompt

if(menuSel==2){
	cout << "/=== Decrypting Your Secrets ===/\n";
	printOut = cryptography(message, stringLength, keyLength, key, menuSel);
}//end of decrypting prompt

else if(menuSel==3){
	cout << "Exiting Program . . .\n";
	return 0;
}//end of menuSel==3
}//end of main

/*===== Cryptography function =====*/
int cryptography(string message, int stringLength, int keyLength, string key, int menuSel){
	char bitXor[9999];//The individual chars after they have been XOR-ed.
	char encrypt[9999];//just bitXor again...

	int intBuffer;//this is the number that will be XOR-ed with your individual characters of your string.
	int i=0;//used to count through the message length
	int j=0;//used to count through a loop to convert ascii characters into decimal and add them to other encryption junk
		//So its really just adding 3 numbers together then using that number to XOR with your original message.
		//Yet the three numbers wont always be the same.

	for (i=0;i<=stringLength-1;i++){	//stringLength -1 becasue subtracting the termination of the string. Because i am only interested in the actual characters in the string.
		for (j=0;j<=keyLength-1;j++){
			intBuffer = stringLength + keyLength + key[i]-32;// I am subtracting 32 because it is a <space> on the ascii table. And i do not want a number to be too large or else ill have a bit overflow and the encryption wont be reversable.
			//The intBuffer here really does all the encryption.

			if (intBuffer < 0){	//This is a fale safe option. I dont think any number will be below 32 but if it does and if it went to 0 or negative. This will restore it to a reliable number to be used to XOR your message.
				intBuffer = stringLength + keyLength;
				//Well intBuffer can go negative, if your key length is shorter than your message length, and less than 32.
			}//End of if statement for intBuffer < 0
		}//End of forloop for keyLength

		bitXor[i] = message[i] ^ intBuffer;//This is the actual XOR-ing being done. SO every specific character in the message will be XOR-ed with an equated number for intBuffer.
		encrypt[i] = bitXor[i];//And im just wasting space here because i want to.
	}//end of for loop stringLength

	if (menuSel==1){
		cout << "Your encrypted message is: " << encrypt << "\n";
	}//End of menuSel==1

	if (menuSel==2){
		cout << "Your decrypted message is: " << encrypt << "\n";
	}//End of menuSel==2
}//end of encrypting

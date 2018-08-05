#include <stdio.h>
#include <string>
#include <iostream>
#include <string.h>
#include <bitset>


using namespace std;

/*====== Function Declaration =====*/
int encrypting(string message, int stringLength, int keyLength, string key);
int decrypting(string message, int stringLength, int keyLength, string key);

int main(){
/*== Variable Declaration and Initializarion ==*/
string message;//This holds the users inputted message.
string key;

char printOut;//This is the output from the stringArray function.
char buffer[9999];

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
	//cout << "String Length is: " << stringLength << "\n";
	//cout << "Original message was: " << message << "\n";


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
	printOut = encrypting(message, stringLength,keyLength, key);

}//end of encrypting prompt

if(menuSel==2){
	cout << "/=== Decrypting Your Secrets ===/\n";
	printOut = decrypting(message, stringLength, keyLength, key);

}//end of decrypting prompt

else if(menuSel==3){
	cout << "Exiting Program . . .\n";
	return 0;
}
}//end of main


int encrypting(string message, int stringLength, int keyLength, string key){
	char bitXor[9999];//The individual chars after they have been XOR-ed.
	char encrypt[9999];

	//string strEncrypt;

	//unsigned long int encryptLength;
	int intBuffer;
	int i=0;
	int j=0;
	//This is XOR-ing every individual char with the length of the stringLength.
	for (i=0;i<=stringLength-1;i++){	//stringLength -1 becasue subtracting the termination of the string.
		cout << message[i] << " " << key[i] << "\n";
		intBuffer = message[i];
		cout << intBuffer << "\n";
		for (j=0;j<=keyLength-1;j++){
			intBuffer = stringLength + keyLength + key[i]-32;
			if (intBuffer < 0){//This is a fale safe option. I dont think any number will be below 32 but if it does and if it went to 0 or negative. This will restore it to a reliable number to be used to XOR your message.
				intBuffer = stringLength + keyLength;
			}//End of if statement for intBuffer < 32
		}//End of forloop for keyLength
		cout << intBuffer << " is the intBuffer number\n";
		bitXor[i] = message[i] ^ intBuffer;
		encrypt[i] = bitXor[i];
	//	strEncrypt = encrypt;
	}//end of for loop stringLength

	//encryptLength = strEncrypt.length();
	//cout << encryptLength << " is the encryptLength\n";
	//cout << stringLength << " is the stringLength\n";
	//if (encryptLength != stringLength){
	//	cout << "Your key is stupid.\n";
	//}
//	else{
	cout << "Your encrypted message is: " << encrypt << "\n";
//	}

}//end of encrypting

int decrypting(string message, int stringLength, int keyLength, string key){
	char bitXor[9999];
	char decrypt[9999];
	int intBuffer;
        int i=0;
	//This is XOR-ing evey individual char with the length of the stringLength.
        for (i=0;i<=stringLength-1;i++){
        //bitXor[i] = message[i] ^ stringLength;
	intBuffer = stringLength + keyLength;
	bitXor[i] = message[i] ^ intBuffer;
	decrypt[i] = bitXor[i];
        }// end of for loop

	cout << "Your decrypted message is: ";
        cout << decrypt << "\n";

}//end of decrypting

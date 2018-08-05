/*
	Michael Hickey
	Professor Carpenter
	Lab 8 Basketball
	Due November 14, 2016
*/

#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

class Player_c{
	private:
		double accuracy2;
		double accuracy3;
		string name;
		int teamNumber;
		
	public:
		Player_c(){cout << "A player has started their career." << endl;}
		Player_c(string name, int teamNumber, double accuracy2, double accuracy3){
			cout << "A player has started their career." << endl;
			cout << "With attributes" << endl;
			cout << "Name " << name << endl;
			cout << "Team Number " << teamNumber << endl;
			cout << "Accuracy for 2 pointers " << accuracy2 << endl;
			cout << "Accuracy for 3 pointers " << accuracy3 << endl;
			cout << endl;
		}
		void setAccuracy(double A){
			accuracy2 = A;
		}//end of setAccuracy()

		void takeShot(){
			int randomNum = rand()%101;
			cout << randomNum;
		}//end of takeShot()

		//~Player_c(){cout << "A player's career has ended." << endl;}
		~Player_c(){};//deconsructor without cout text
};


int loopAccuracy(Player_c (&playerArray)[5], double A){
	//this is how to pass by reference an array.
	for(int i = 0; i < 5; i++){
		cout << "Set Player" << i << "'s accuracy for 2 pointers  between 0 and 100." << endl << "Accuracy: ";
		cin  >> A;
		if(A < 0 || A > 100){
			cout << "You got to restart this bruh." << endl;
			return 0;
		}else{
			playerArray[i].setAccuracy(A);
		}
	}//end of forloop to initialize the player accuracy

	//checking the sum of the total accuracies
	
}//end of loopAccuracy


void clearScreen(){
	for(int i = 0; i < 50; i++){
		cout << endl;
	}

}//end of clearScreen

int main(){
	srand(time(NULL));
	double A = 0;

	clearScreen();

	//test
	Player_c playerTest("Leroy", 69, 54, 100);

	//Initializing the array of classes manually.
	Player_c playerArray[5] = { Player_c ("Player 1", 71, 100, 100), 
				    Player_c ("Player 2", 72, 80, 55), 
				    Player_c ("Player 3", 73, 50, 25), 
				    Player_c ("Player 4", 74, 35, 10), 
				    Player_c ("Player 5", 75, 35, 10) };

	playerArray[0].takeShot();

	cout << endl;//This is to separate the deconstructor text from the rest of the input.

}//end of main

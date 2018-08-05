/**
 * Michael Hickey
 * Professor Carpenter
 * Lab 8 Basketball
 * Due November 14, 2016
 */

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <cmath>

using namespace std;

/**
 * Description:
 * This class will construct a basketball player.
 * The player will have a name, number, accuracy for 2ptrs and 3ptrs.
 * The function takeShot() will check what percentage of the shots will be made.
 */
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

		void takeShot(){
			int randomNum = rand()%101;
			cout << randomNum;
		}//end of takeShot()

		//~Player_c(){cout << "A player's career has ended." << endl;}
		~Player_c(){};//deconsructor without cout text
};


/**
 * Description:
 * This function will generate a random inclusive number between 0 and 4
 * This number is used to pick which player will shoot the ball.
 */
int pickPlayer(){

	int randNum0 = rand()%5;
	int randNum1 = rand()%5;
	int randNum2 = rand()%5;
	int randNum3 = rand()%5;
	int randNum4 = rand()%5;
	int sumOf5 = randNum0 + randNum1 + randNum2 + randNum3 + randNum4;
	int mean = sumOf5/5;//integer division will skew lower
	int variance = ( (randNum0-mean)*(randNum0-mean)+(randNum1-mean)*(randNum1-mean)+(randNum2-mean)*(randNum2-mean)+(randNum3-mean)*(randNum3-mean)+(randNum4-mean)*(randNum4-mean) );
	int std = sqrt(variance);
	//cout << "Player " << std << " will shoot the ball" << endl;
	//std-1 because it will be the array index
	return std;
}


/**
 * Description:
 * This function will clear the screen.
 * This prints 50 end lines to clear the screen.
 */
void clearScreen(){
	for(int i = 0; i < 50; i++){
		cout << endl;
	}

}//end of clearScreen

/**
 * Description:
 * This is the execution of the program.
 * This will simulate a basketball game and 100 shots will be taken.
 * 300 points will be a perfect game. Meaning 100 3pt shots were successfull.
 */
int main(){
	//seeding time to make rand give random numbers and not the same one every tme.
	srand(time(NULL));
	double A = 0;

	clearScreen();

	//test player
	Player_c playerTest("Leroy", 69, 54, 100);

	//Initializing the array of classes manually.
	Player_c playerArray[5] = { Player_c ("Player 1", 71, 100, 100), 
				    Player_c ("Player 2", 72, 80, 55), 
				    Player_c ("Player 3", 73, 50, 25), 
				    Player_c ("Player 4", 74, 35, 10), 
				    Player_c ("Player 5", 75, 35, 10) };
	//make a for loop here
	int test = 0;
	double holder[5];
	for(int i = 0; i < 10000; i++){
		test = pickPlayer();
		holder[test]++;
	}
	for(int i = 0; i < 5; i++){
		cout << "Player " << i << " was picked " << holder[i] << " times." << endl;
	}



	playerArray[0].takeShot();
	

	cout << endl;//This is to separate the deconstructor text from the rest of the input.

}//end of main



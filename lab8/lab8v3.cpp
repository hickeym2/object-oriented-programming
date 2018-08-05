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
		int accuracy2;
		int accuracy3;
		string name;
		int teamNumber;
		int stdHolder;
	public:
		Player_c(){cout << "A Player has started their career." << endl;}
		Player_c(string name, int teamNumber, int accuracy2, int accuracy3){
			name = name;
			teamNumber = teamNumber;
			accuracy2 = accuracy2;
			accuracy3 = accuracy3;
			cout << "A player has started their career." << endl;
			cout << "With attributes" << endl;
			cout << "Name " << name << endl;
			cout << "Team Number " << teamNumber << endl;
			cout << "Accuracy for 2 pointers " << accuracy2 << endl;
			cout << "Accuracy for 3 pointers " << accuracy3 << endl;
			cout << endl;
		}

		string getName(){
			return name;
		}

		void setName(string name1){
			name = name1;
		}

		void setNumber(int num){
			teamNumber = num;
		}

		void setAccuracy2(int acc2){
			accuracy2 = acc2;
		}

		void setAccuracy3(int acc3){
			accuracy3 = acc3;
		}

		int getAccuracy2(){
			//cout << "This is " << name << " accuracy for 2 ptrs " << accuracy2 << endl;
			return accuracy2;
		}

		int getAccuracy3(){
			//cout << "This is " << name << " accuracy for 3 ptrs " << accuracy3 << endl;
			return accuracy3;
		}

		//The c denotes a cout statement.
		int getAccuracy3c(){
			cout << "This is " << name << " accuracy for 3 ptrs: " << accuracy3 << endl;
			return accuracy3;
		}

		int getAccuracy2c(){
			cout << "This is " << name << " accuracy for 2 ptrs: " << accuracy2 << endl;
			return accuracy2;
		}

		/**
		 * Desctiption:
		 * This take shot funciton will determine the accuracy
		 * needed to make the shot.
		 * @return std, This is the final accuracy your chosen player needs to beat.
		 */
		int takeShot(){
			//array size 100 for each percentage.
			//Now I will skew the curve to the lower numbers by using
			//standard deviation and rand numbers.
			//This is a random accuracy generated that the player needs to beat.
			int array[100];
			int arraySum = 0;
			for(int i = 0; i < 100; i++){
				array[i] = rand()%101;
			}
			for(int i = 0; i < 100; i++){
				arraySum = arraySum + array[i];
			}
			int mean = arraySum/100;
			int variance = 0;
			for(int i = 0; i < 100; i++){
				variance = variance + ((array[i] - mean)*(array[i] - mean));
			}
			int standardDev = sqrt(variance);

			//This  + rand()%20 is just to give the skewed curve some variety.
			int std = sqrt(standardDev) + rand()%20;
			
			//cout << "Accuracy to beat to make the shot " << std << endl;
			stdHolder = std;
			return std;
		}//end of takeShot()

	int takeShotC(){
			int randNum = rand()%39;
			cout << "Accuracy to beat to make the shot: " << randNum << endl;
			return randNum;
		}

		//~Player_c(){cout << "A player's career has ended." << endl;}
		~Player_c(){};//deconsructor without cout text
};


/**
 * Description:
 * This function will generate a random inclusive number between 0 and 4
 * This number is used to pick which player will shoot the ball.
 * @return sqrtStd This is the square root of the standard deviaiton.
 * Used to pick one of 3 players out of 5 total players.
 */
int pickPlayer(){
	//I am creating a skewed distribution for the lower ranged numbers.
	//I am generating random numbers, then I am using the square root of the standard deviation to pick a player.
	int randNum0 = rand()%5;
	int randNum1 = rand()%5;
	int randNum2 = rand()%5;
	int randNum3 = rand()%5;
	int randNum4 = rand()%5;
	int sumOf5 = randNum0 + randNum1 + randNum2 + randNum3 + randNum4;
	int mean = sumOf5/5;//integer division will skew lower
	int variance = ( (randNum0-mean)*(randNum0-mean)+(randNum1-mean)*(randNum1-mean)+(randNum2-mean)*(randNum2-mean)+(randNum3-mean)*(randNum3-mean)+(randNum4-mean)*(randNum4-mean) );
	int sqrtStd = sqrt(sqrt(variance));

	//std-1 because it will be the array index
	return sqrtStd;
}//end of pickPlayer()


/**
 * Description:
 * This function will randomly choose the points for the shot to take.
 * This uses the square root of the standard deviation to skew the distribution.
 * @return sqrtStd This is the shot type that will be retured. either a 2 or a 3.
 */
int shotType(){
	//shots can only be 2 or 3 points
	//rand 2 will choose random numbers of 0 or 1
	//the + 2 will bump the random numbers up to the actual score value of 2 or 3
	//2 will be 2ptrs, and 3 will be 3prts
	int randNum0 = rand()%2 + 2;
	int randNum1 = rand()%2 + 2;
	int sum = randNum0 + randNum1;
	int mean = sum / 2;
	int variance = (randNum0-mean)*(randNum0-mean) + (randNum1-mean)*(randNum1-mean);
	int std = sqrt(variance);
	int sqrtStd = sqrt(variance) + 2;

	//This is "skweing" all the 2 point shots into 3 pt shots.
	if(sqrtStd == 2){
		sqrtStd++;
	}
	return sqrtStd;
}//end of shotType()


//This prototype is for simulation()
void simShots(int);

/**
 * Description:
 * This will simulate as many shots as the arguments you supply.
 * You can see a skewed curve with this.
 * @param numShots This is the number of shots taken in the simulation.
 */
void simulation(int numShots){
	//numShots really is the number of shots taken.
	//simulating numShots times, of who will get picked to shoot.
	int s = numShots;
	int test = 0;
	double holder[5];
	cout << endl << "#=== Simulation ===#" << endl;
	cout << "This will show the distribution of " << numShots << " shots." << endl;
	for(int i = 0; i < numShots; i++){
		test = pickPlayer();
		holder[test]++;
	}
	//how many times player[i] got the ball to shoot.
	for(int i = 0; i < 5; i++){
		if(holder[i] < 1){
			cout << "Player " << i << " was picked 0 times." << endl;
		}else{
			cout << "Player " << i << " was picked " << holder[i] << " times." << endl;
		}
	}
	cout << endl;
	simShots(s);
	cout << "#==================#" << endl;
}//end of simulation()

/**
 * Description:
 * This is a simulaiton to see the distribution of what shots are  chosen.
 * @param numShots This is the number of shots taken in the simulation.
 */
void simShots(int numShots){
	int test = 0;
	double holder[2];
	for(int i = 0; i < numShots; i++){
		//you want to subtract 2 here so the shot value will be within the index values.
		test = shotType() - 2;
		holder[test]++;
	}
	for(int i = 0; i < 2; i++){
		if(holder[i] < 1){
			cout << "Shot Type " << i+2 << " was picked 0 times." << endl;
		}else{
			cout << "Shot Type " << i+2 << " was picked " << holder[i] << " times." << endl;
		}
	}
}//end of simShots()


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
	//Player_c playerTest("Leroy", 69, 54, 100);

	//Initializing the array of classes manually.
	
	Player_c testArray[5] = { Player_c ("Player 0", 71, 100, 40), 
				    Player_c ("Player 1", 72, 100, 100), 
				    Player_c ("Player 2", 73, 100, 60), 
				    Player_c ("Player 3", 74, 0, 0), 
				    Player_c ("Player 4", 75, 0, 0) };
	

	
	Player_c playerArray[5];

	playerArray[0].setName("Player 0");
	playerArray[0].setNumber(70);
	playerArray[0].setAccuracy2(100);
	playerArray[0].setAccuracy3(40);

	playerArray[1].setName("Player 1");
	playerArray[1].setNumber(71);
	playerArray[1].setAccuracy2(100);
	playerArray[1].setAccuracy3(100);

	playerArray[2].setName("Player 2");
	playerArray[2].setNumber(72);
	playerArray[2].setAccuracy2(100);
	playerArray[2].setAccuracy3(60);

	playerArray[3].setName("Player 3");
	playerArray[3].setNumber(73);
	playerArray[3].setAccuracy2(0);
	playerArray[3].setAccuracy3(0);

	playerArray[4].setName("Player 4");
	playerArray[4].setNumber(74);
	playerArray[4].setAccuracy2(0);
	playerArray[4].setAccuracy3(0);

	int test = 0;
	double holder[5];
	int shotPoints = 0;
	int scoreBoard = 0;

	//Change numShots to change the number of simulaions
	int numShots = 10000;
	simulation(numShots);

	//Simulate a single shot
	cout << endl << "Simulation of 1 shot." << endl;
	test = pickPlayer();
	cout << playerArray[test].getName() << " will shoot the ball" << endl;
	shotPoints = shotType();
	cout << "This is the shot value: " << shotPoints << endl;
	playerArray[test].takeShotC();
	if(shotPoints == 2){
		if(playerArray[test].getAccuracy2() >= playerArray[test].takeShot()){
			cout << "You made the shot." << endl;
			//scoreBoard += 2;
		}else{
			cout << "You did not make the shot." << endl;
		}
	}else{
		if(playerArray[test].getAccuracy3c() >= playerArray[test].takeShot()){
			cout << "You made the shot." << endl;
			//scoreBoard += 3;
		}else{
			cout << "You did not make the shot." << endl;
		}
	}//end of if else
	cout << endl << "#==================#" << endl;



	//This is the actual game with 100 shots.

	for(int i = 0; i < 100; i++){
		test = pickPlayer();
		//cout << playerArray[test].getName() << " will shoot the ball" << endl;
		shotPoints = shotType();
		//cout << "This is the shot value " << shotPoints << endl;
		if(shotPoints == 2){
			if(playerArray[test].getAccuracy2() >= playerArray[test].takeShot()){
				cout << "You made the shot." << endl;
				//deal with scoring a point.
			}else{
				cout << "You did not make the shot." << endl;
			}
		}else{
			if(playerArray[test].getAccuracy3() >= playerArray[test].takeShot()){
				//cout << "You made the shot." << endl;
				scoreBoard += 3;
			}else{
				cout << "You did not make the shot." << endl;
			}
		}//end of if else
	}//end of for loop

	cout << endl << "For 100 Shots taken." << endl;
	cout << "The final Score is " << scoreBoard << endl;

	cout << testArray[1].getAccuracy3() << endl;

	cout << endl;//This is to separate the deconstructor text from the rest of the input.

}//end of main



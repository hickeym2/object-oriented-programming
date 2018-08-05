/*
 * Mike Hickey
 * Professor Carpenter
 * Lab 2
 * lab2v2.cpp
 * Due 9/19/16
 */

#include <iostream>
#include <stdio.h>
#include <ctime>
#include <math.h>
#include <string.h>

using namespace std;
/*============Function Declaration============*/
int schedule(int militaryTime,char userDayInput[10]);
/*============================================*/
int main(){

/*===Variables===*/
int militaryTime;//previously was greenTime. Used to store the value of time. VERY IMPORTANT
int dayCompared;//this is the value that will return a 1 when two strings are compared when selecting a day. uses the userDayInput char.previously was ruby.
int menuSel;//Used to select options in the menu.
int hour=0;//Used in storing the system time.
int day=0;//Used in storing the system day.

char monday[10]="monday";
char tuesday[10]="tuesday";
char wednesday[10]="wednesday";
char thursday[10]="thursday";
char friday[10]="friday";
char saturday[10]="saturday";
char sunday[10]="sunday";

char date[256];
char userInputDay[10];//This is the variable that stores the string the user puts in for selecting a day.
char buffer[10];//a buffer to flush the remaining chars.
char printOut;;//Prints out the final string
/*===============*/

/*===============*/
while(1){
	cout<<"\n";
	printf("Would you like to see what I am doing right now, or at a specific hour?\n");
	printf("Input 1 to insert a specific hour.\n");
	printf("Input 2 to see what I am doing right now.\n");
	printf("Input 3 to exit the program.\n");
	printf("Selecting: ");
	scanf("%d",&menuSel);
	cout<<"\n";

	if(menuSel==1){
		/*== This is allowing the user to input a specific time and day to see what is on my schedule ==*/
		printf("Input an hour in military time.\nExample input 19 if you want the hour of 7pm to 8pm.\nMilitary Hour: ");
		scanf("%d",&militaryTime);
		cout<<"\n";
		printf("Type in a day of the week in all lowercase letters.\nExample for tuesday input tuesday.\nDay of the week: ");
		scanf("%s",userInputDay);
		/*== This is calling the function and will return the spefific activity on the schedule at the specific time and day ==*/
		printOut = schedule(militaryTime,userInputDay);

		}//The end of menuSel=1

	if(menuSel==2){
		/*== This is allowing the user to select the option of what is on my schedule right now. By fething the system clocks time and date ==*/
		printf("At this specific hour: ");
		time_t currentTime;
		time(&currentTime);
		struct tm * holder;//see how this is a pointer. I was trying to put this in a char and it would not work. obviously...
		buffer[10];
		holder = localtime(&currentTime);
		strftime(buffer,10,"%H",holder);//if you google strftime and click the link there is a list of things you can do. %H is on the list, it said you will fetch the current hour of the day.
		sscanf(buffer,"%d",&hour);
		printf("%d\n",hour);
		militaryTime = hour;

		/*=====  This prints out the number of the day ====*/
		strftime(date,sizeof(date),"%d",holder);//under the strftime instead of doing %d, you can do %A and it output the day of the week. so it will type monday.
		sscanf(date,"%d",&day);			//But this is a pointer and i coulnd not get the information at the pointer into a char so i had to move on.
		printf("On this specific day: ");
		printf("%d\n",day);

		/* Okay because strftime points to some memory, you cant store the pointer in a char so you can move it around.
		/* So what i did was have the computers clock output an integer for the specific day and then store the day and a regular int.
		/* then I went through the calendar to map every single number of the day to the actual day name. This honestly gives you until the 17th of
		/* October to grade my lab and it will still be working. whick sucks...
		/* I tried so hard to figure out how to store the memory of a pointer in a char, but the pointer is bigger than a char so it doesnt fit.*/

		/*========= Assigning every integer of the month to its appropriate day of the week ==========*/
		if(day==18){strcpy(userInputDay,sunday);}
		if(day==19){strcpy(userInputDay,monday);}
		if(day==20){strcpy(userInputDay,tuesday);}
		if(day==21){strcpy(userInputDay,wednesday);}
		if(day==22){strcpy(userInputDay,thursday);}
		if(day==23){strcpy(userInputDay,friday);}
		if(day==24){strcpy(userInputDay,saturday);}
		if(day==25){strcpy(userInputDay,sunday);}
		if(day==26){strcpy(userInputDay,monday);}
		if(day==27){strcpy(userInputDay,tuesday);}
		if(day==28){strcpy(userInputDay,wednesday);}
		if(day==29){strcpy(userInputDay,thursday);}
		if(day==30){strcpy(userInputDay,friday);}
		if(day== 1){strcpy(userInputDay,saturday);}
		if(day== 2){strcpy(userInputDay,sunday);}
		if(day== 3){strcpy(userInputDay,monday);}
		if(day== 4){strcpy(userInputDay,tuesday);}	//seriously this code here sucks...
		if(day== 5){strcpy(userInputDay,wednesday);}
		if(day== 6){strcpy(userInputDay,thursday);}
		if(day== 7){strcpy(userInputDay,friday);}
		if(day== 8){strcpy(userInputDay,saturday);}
		if(day== 9){strcpy(userInputDay,sunday);}
		if(day==10){strcpy(userInputDay,monday);}
		if(day==11){strcpy(userInputDay,tuesday);}
		if(day==12){strcpy(userInputDay,wednesday);}
		if(day==13){strcpy(userInputDay,thursday);}
		if(day==14){strcpy(userInputDay,friday);}
		if(day==15){strcpy(userInputDay,saturday);}
		if(day==16){strcpy(userInputDay,sunday);}
		if(day==17){strcpy(userInputDay,monday);}

		/*===== This is calling the funciton where it goes to my schedule and grabs the appropriate print out statement =====*/
		printOut = schedule(militaryTime,userInputDay);
		cout<<"\n";
		}//The end of menuSel==2

	else if(menuSel==3){
		printf("Exiting Program. . .\n");
		return 0;
		}// The end of menuSel==2. exiting program

	/*resetting the day to monday and hour to 0*/
	strcpy(userInputDay,monday);
	militaryTime = 0;
	//restarting the while loop

}//This is the end of the while loop

}//this is the end of main

/*=============== Function Schedule =============*/
int schedule(int militaryTime, char userInputDay[10]){
int i;

/*==== This is assigning the days of the week to a specific integer. Then dayCompared will take the place of any of the integers ====*/
int dayCompared;
int dayCompared0=0;//monday
int dayCompared1=0;//tuesday
int dayCompared2=0;//wednesday
int dayCompared3=0;//thursday
int dayCompared4=0;//friday
int dayCompared5=0;//saturday
int dayCompared6=0;//sunday

/*=== Making all these variables in this scope so i can use strcmp ===*/
char monday[10]="monday";
char tuesday[10]="tuesday";
char wednesday[10]="wednesday";
char thursday[10]="thursday";
char friday[10]="friday";
char saturday[10]="saturday";
char sunday[10]="sunday";

/*========*/
/*So when selecting option 1 to insert your own specific time, userInputDay is a char which takes the users input for a specific day and stores it.
  Then the char <day of the week> is compared to the the userInputDay. Using !strcmp to output a 1 if the strings are the same.
  Then the specific dayCompared# will store the value of 1 to signify that a specific weekday was input by the user.*/
/*So when selecting option 2 to use the system time, the userInputDay is still a char that was  forced to accept a specifc weekday as its contents.
  Then the contents of the string are compare to the contents to the weekday. The same thing as before, just a new way to obtain the userInputDay char.*/
  
/*== The reason I do this is so i dont need to make 7x more if statements when doing the schedule ==*/
dayCompared0 = !strcmp(monday,userInputDay);
dayCompared1 = !strcmp(tuesday,userInputDay);
dayCompared2 = !strcmp(wednesday,userInputDay);
dayCompared3 = !strcmp(thursday,userInputDay);
dayCompared4 = !strcmp(friday,userInputDay);
dayCompared5 = !strcmp(saturday,userInputDay);
dayCompared6 = !strcmp(sunday,userInputDay);

/*This is selecting the day for me*/
/*This block runs through all the if statements saying if dayCompared# is equal to 1, assign dayCompared to a specific digit.
  Where 0 is monday, 1 is tuesday, 2 is wednesday . . .  */
if (dayCompared0 == 1){
	dayCompared = 0;
	}
if (dayCompared1 == 1){
	dayCompared = 1;
	}
if (dayCompared2 == 1){
	dayCompared = 2;
	}
if (dayCompared3 == 1){
	dayCompared = 3;
	}
if (dayCompared4 == 1){
	dayCompared = 4;
	}
if (dayCompared5 == 1){
	dayCompared = 5;
	}
if (dayCompared6 == 1){
	dayCompared = 6;
	}

/*== This is the start of the actual schedule. It will take in the variable militaryTime and dayCompared digit to output the appropriate statement ==*/
/*== Every hour for every day is unique 7*24= 168 unique expressions ==*/
if (militaryTime == 0){
        if (dayCompared==0){printf("On monday, Cracking my back\n");}
        if (dayCompared==1){printf("On Tuesday, Smuggling drugs to china\n");}
        if (dayCompared==2){printf("On Wednesday, Lavishing in gravy\n");}
        if (dayCompared==3){printf("On Thursday, Eating chap stick\n");}
        if (dayCompared==4){printf("On friday, Bird hunting\n");}
        if (dayCompared==5){printf("On Saturday, People watching\n");}
        if (dayCompared==6){printf("On Sunday, Dog watching\n");}
        }// the end of time 0
if (militaryTime == 1){
        if (dayCompared==0){printf("On monday, Putting the lotion on its skin\n");}
        if (dayCompared==1){printf("On Tuesday, Not coding when I should be\n");}
        if (dayCompared==2){printf("On Wednesday, Turning all the clocks 20 minutes forward\n");}
        if (dayCompared==3){printf("On Thursday, Hanging posters\n");}
        if (dayCompared==4){printf("On friday, Electrifing Zooboomafoo\n");}
        if (dayCompared==5){printf("On Saturday, Staring as Pete the Camel\n");}
        if (dayCompared==6){printf("On Sunday, Cracking the clams open");}
        }// the end of time 1
if (militaryTime == 2){
        if (dayCompared==0){printf("On monday, Playing the game Farkle\n");}
        if (dayCompared==1){printf("On Tuesday, Breaking into the NSA\n");}
        if (dayCompared==2){printf("On Wednesday, Sending my pants to college\n");}
        if (dayCompared==3){printf("On Thursday, Generating hate mail\n");}
        if (dayCompared==4){printf("On friday, Really hating on birds\n");}
        if (dayCompared==5){printf("On Saturday, Training my young grasshopper\n");}
        if (dayCompared==6){printf("On Sunday, Pronouncing it jif like the peanutbutter\n");}
        }// the end of time 2
if (militaryTime == 3){
        if (dayCompared==0){printf("On monday, Browsing amazon.com\n");}
        if (dayCompared==1){printf("On Tuesday, Staring at a robo scorpion with lazer\n");}
        if (dayCompared==2){printf("On Wednesday, Running into a wall\n");}
        if (dayCompared==3){printf("On Thursday, Studdying the female anatomy\n");}
        if (dayCompared==4){printf("On friday, Choosing the best super model\n");}
        if (dayCompared==5){printf("On Saturday, Shucking corn on the cob\n");}
        if (dayCompared==6){printf("On Sunday, Wondering if you set it to W for wumbo\n");}
        }// the end of time 3
if (militaryTime == 4){
        if (dayCompared==0){printf("On monday, Refusing to play the lottery\n");}
        if (dayCompared==1){printf("On Tuesday, Wishing of making it rich on my own\n");}
        if (dayCompared==2){printf("On Wednesday, Not supporting politics\n");}
        if (dayCompared==3){printf("On Thursday, Moving to Canada\n");}
        if (dayCompared==4){printf("On friday, Skateboarding down the Prudential\n");}
        if (dayCompared==5){printf("On Saturday, Walking a tight rope\n");}
        if (dayCompared==6){printf("On Sunday, Using the bathroom\n");}
        }// the end of time 4
if (militaryTime == 5){
        if (dayCompared==0){printf("On monday, Flapping my tongue\n");}
        if (dayCompared==1){printf("On Tuesday, Finding a dumpster baby and saving it\n");}
        if (dayCompared==2){printf("On Wednesday, Poking holes in condoms\n");}
        if (dayCompared==3){printf("On Thursday, Taking all the take out menus\n");}
        if (dayCompared==4){printf("On friday, Thinking of the internet\n");}
        if (dayCompared==5){printf("On Saturday, Taking out the trash\n");}
        if (dayCompared==6){printf("On Sunday, DMing yo girl\n");}
        }// the end of time 5
if (militaryTime == 6){
        if (dayCompared==0){printf("On monday, Being civil for once\n");}
        if (dayCompared==1){printf("On Tuesday, Not giving a shit\n");}
        if (dayCompared==2){printf("On Wednesday, Reading chinese\n");}
        if (dayCompared==3){printf("On Thursday, Singking stones in a pot of water\n");}
        if (dayCompared==4){printf("On friday, Throwing a super huge party\n");}
        if (dayCompared==5){printf("On Saturday, Calling the pizza guy to the middle of nowhere\n");}
        if (dayCompared==6){printf("On Sunday, Playing music loud\n");}
        }// the end of time 6
if (militaryTime == 7){
        if (dayCompared==0){printf("On monday, Drag racing with my lincoln towncar\n");}
        if (dayCompared==1){printf("On Tuesday, Making a new car alternator\n");}
        if (dayCompared==2){printf("On Wednesday, Cracking my knuckles\n");}
        if (dayCompared==3){printf("On Thursday, Making the elderly cry\n");}
        if (dayCompared==4){printf("On friday, Finding Shrek's swamp\n");}
        if (dayCompared==5){printf("On Saturday, Drinking swamp water\n");}
        if (dayCompared==6){printf("On Sunday, Defusing magic bombs\n");}
        }// the end of time 7
if (militaryTime == 8){
        if (dayCompared==0){printf("On monday, Stuffing stuff in a suitcase\n");}
        if (dayCompared==1){printf("On Tuesday, Finding a taco cat...I'm a palindrome\n");}
        if (dayCompared==2){printf("On Wednesday, Shinning light on a bat\n");}
        if (dayCompared==3){printf("On Thursday, Rubbing a book\n");}
        if (dayCompared==4){printf("On friday, Seeing if I will get free health care\n");}
        if (dayCompared==5){printf("On Saturday, Making people have goosebumps\n");}
        if (dayCompared==6){printf("On Sunday, Turning the thermostat to 69\n");}
        }// the end of time 8
if (militaryTime == 9){
        if (dayCompared==0){printf("On monday, Sleeping in a hammock\n");}
        if (dayCompared==1){printf("On Tuesday, Tongue piercing the wild life\n");}
        if (dayCompared==2){printf("On Wednesday, Rumbling with he big guys\n");}
        if (dayCompared==3){printf("On Thursday, Developing a new fire starter\n");}
        if (dayCompared==4){printf("On friday, Shaving balsa wood\n");}
        if (dayCompared==5){printf("On Saturday, Studdying the female anatomy\n");}
        if (dayCompared==6){printf("On Sunday, Asking people if they even crop\n");}
        }// the end of time 9
if (militaryTime == 10){
        if (dayCompared==0){printf("On monday, Fighting the Kool-Aid man\n");}
        if (dayCompared==1){printf("On Tuesday, Developing new child safety scissors\n");}
        if (dayCompared==2){printf("On Wednesday, Leaving marker caps off so Professor Carpenter can shoot them like Kobe\n");}
        if (dayCompared==3){printf("On Thursday, Unstitching some fabric\n");}
        if (dayCompared==4){printf("On friday, Bathing in maple leaves\n");}
        if (dayCompared==5){printf("On Saturday, Hosting giraffe cage matches");}
        if (dayCompared==6){printf("On Sunday, Crying into a bowl of pudding");}
        }// the end of time 10
if (militaryTime == 11){
        if (dayCompared==0){printf("On monday, Learning how to spell\n");}
        if (dayCompared==1){printf("On Tuesday, Starring in a commercial\n");}
        if (dayCompared==2){printf("On Wednesday, Measuring how tall I am\n");}
        if (dayCompared==3){printf("On Thursday, Burning an inappropriate image onto a plasma tv\n");}
        if (dayCompared==4){printf("On friday, Stealing candy from a baby\n");}
        if (dayCompared==5){printf("On Saturday, Breaking family picture frames\n");}
        if (dayCompared==6){printf("On Sunday, Using crayons on the drywall\n");}
        }// the end of time 11
if (militaryTime == 12){
        if (dayCompared==0){printf("On monday, Finding my core message\n");}
        if (dayCompared==1){printf("On Tuesday, Praising Neptune\n");}
        if (dayCompared==2){printf("On Wednesday, Licking doorknobs\n");}
        if (dayCompared==3){printf("On Thursday, Thinking of cooking recepies\n");}
        if (dayCompared==4){printf("On friday, Eating granola and peanutbutter\n");}
        if (dayCompared==5){printf("On Saturday, Going bumber to bumper\n");}
        if (dayCompared==6){printf("On Sunday, Trimming a toe nail\n");}
        }// the end of time 12
if (militaryTime == 13){
        if (dayCompared==0){printf("On monday, Vilating an OSHA law\n");}
        if (dayCompared==1){printf("On Tuesday, Slicing roast beef\n");}
        if (dayCompared==2){printf("On Wednesday, Mkaing my own footsteps\n");}
        if (dayCompared==3){printf("On Thursday, Trying to find the elixer of life\n");}
        if (dayCompared==4){printf("On friday, Experimenting on a turtle\n");}
        if (dayCompared==5){printf("On Saturday, Spray tanning a baby\n");}
        if (dayCompared==6){printf("On Sunday, Disturbing the peace\n");}
        }// the end of time 13
if (militaryTime == 14){
        if (dayCompared==0){printf("On monday, corupting the EU\n");}
        if (dayCompared==1){printf("On Tuesday, playing N64\n");}
        if (dayCompared==2){printf("On Wednesday, Cutting holes in peoples socks\n");}
        if (dayCompared==3){printf("On Thursday, Breaking INTO jail\n");}
        if (dayCompared==4){printf("On friday, Playing GTA V in real life\n");}
        if (dayCompared==5){printf("On Saturday, Listening to Kendrick Lamar\n");}
        if (dayCompared==6){printf("On Sunday, Cooking a robust pizza\n");}
        }// the end of time 14
if (militaryTime == 15){
        if (dayCompared==0){printf("On monday, Thinking of my stripper name\n");}
        if (dayCompared==1){printf("On Tuesday, If my stripper name was Charity\n");}
        if (dayCompared==2){printf("On Wednesday, I could be asking people\n");}
        if (dayCompared==3){printf("On Thursday, Money for charity please\n");}
        if (dayCompared==4){printf("On friday, But really, im just keeping the money\n");}
        if (dayCompared==5){printf("On Saturday, Damn thats shits good\n");}
        if (dayCompared==6){printf("On Sunday, Making a glass lamp\n");}
        }// the end of time 15
if (militaryTime == 16){
        if (dayCompared==0){printf("On monday, Breaking the law\n");}
        if (dayCompared==1){printf("On Tuesday, Making new memes\n");}
        if (dayCompared==2){printf("On Wednesday, WOOKIE DOOKIE GAZA-MOOPH\n");}
        if (dayCompared==3){printf("On Thursday, Making Gronk my bitch\n");}
        if (dayCompared==4){printf("On friday, Invading Cuba\n");}
        if (dayCompared==5){printf("On Saturday, Burning oil\n");}
        if (dayCompared==6){printf("On Sunday, RaaaAAAAWRRRRRRR!!!\n");}
        }// the end of time 16
if (militaryTime == 17){
        if (dayCompared==0){printf("On monday, Thinking of a plot for a movie\n");}
        if (dayCompared==1){printf("On Tuesday, Two brothers\n");}
        if (dayCompared==2){printf("On Wednesday, Fight an alien race\n");}
        if (dayCompared==3){printf("On Thursday, Of grandmas controlled by cats\n");}
        if (dayCompared==4){printf("On friday, Who find love\n");}
        if (dayCompared==5){printf("On Saturday, With a radioactive tapestry\n");}
        if (dayCompared==6){printf("On Sunday, Coming this June to theaters everywhere\n");}
        }// the end of time 17
if (militaryTime == 18){
        if (dayCompared==0){printf("On monday, Brewing mead\n");}
        if (dayCompared==1){printf("On Tuesday, Looking for a challenge\n");}
        if (dayCompared==2){printf("On Wednesday, Swimming pool full of liquor, and diving in\n");}
        if (dayCompared==3){printf("On Thursday, Punching a tree\n");}
        if (dayCompared==4){printf("On friday, Writing poems\n");}
        if (dayCompared==5){printf("On Saturday, Thinking about the good times\n");}
        if (dayCompared==6){printf("On Sunday, Determing wether I am insane or not\n");}
        }// the end of time 18
if (militaryTime == 19){
        if (dayCompared==0){printf("On monday, Bringing Bowser to a day care\n");}
        if (dayCompared==1){printf("On Tuesday, Grumbling like an old man\n");}
        if (dayCompared==2){printf("On Wednesday, Spilling orange juice in the microwave\n");}
        if (dayCompared==3){printf("On Thursday, Using two ply like its no tomorrow\n");}
        if (dayCompared==4){printf("On friday, Turning to the dark side of the force\n");}
        if (dayCompared==5){printf("On Saturday, Slurping my soup loud in Japan\n");}
        if (dayCompared==6){printf("On Sunday, Watching stranger things\n");}
        }// the end of time 19
if (militaryTime == 20){
        if (dayCompared==0){printf("On monday, Breaking glass bottles\n");}
        if (dayCompared==1){printf("On Tuesday, Cleaning my boots\n");}
        if (dayCompared==2){printf("On Wednesday, Developing a new super conductor\n");}
        if (dayCompared==3){printf("On Thursday, Racing a beever in a chewing contest\n");}
        if (dayCompared==4){printf("On friday, Shaving a cat\n");}
        if (dayCompared==5){printf("On Saturday, Sharpening a pencil\n");}
        if (dayCompared==6){printf("On Sunday, Leaving the two end slices of bread in the bag\n");}
        }// the end of time 20
if (militaryTime == 21){
        if (dayCompared==0){printf("On monday, Scratching all your CD's\n");}
        if (dayCompared==1){printf("On Tuesday, Letting the cold out of the freezer\n");}
        if (dayCompared==2){printf("On Wednesday, Recycling stemcells\n");}
        if (dayCompared==3){printf("On Thursday, Licking sand paper\n");}
        if (dayCompared==4){printf("On friday, Flipping a knife\n");}
        if (dayCompared==5){printf("On Saturday, Watching Arthur\n");}
        if (dayCompared==6){printf("On Sunday, Feeling triggered\n");}
        }// the end of time 21
if (militaryTime == 22){
        if (dayCompared==0){printf("On monday, Finding out all the genders\n");}
        if (dayCompared==1){printf("On Tuesday, Helping the ozone\n");}
        if (dayCompared==2){printf("On Wednesday, Burning trees\n");}
        if (dayCompared==3){printf("On Thursday, Spitting on babies\n");}
        if (dayCompared==4){printf("On friday, Tearing a butterfly in half\n");}
        if (dayCompared==5){printf("On Saturday, Cranking a crank shaft\n");}
        if (dayCompared==6){printf("On Sunday, Breaking a rabbits foot\n");}
        }// the end of time 22
if(militaryTime == 23){
	if(dayCompared==0){printf("On Monday, Eating bugs\n");}
	if(dayCompared==1){printf("On Tuesday, Drawing on a crab shell\n");}
	if(dayCompared==2){printf("On Wednesday, Spraypainting the elderly\n");}
	if(dayCompared==3){printf("On Thursday, Jumping out of an air vent\n");}
	if(dayCompared==4){printf("On Friday, Racing ratcoons\n");}
	if(dayCompared==5){printf("On Saturday, Thinking of the color green\n");}
	if(dayCompared==6){printf("On Sunday, Writing in C code\n");}
	}//end of militaryTime==23
}//This is the end of schedule

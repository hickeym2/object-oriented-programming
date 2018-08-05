/*
 * Mike Hickey
 * Professor Carpenter
 * Lab 2
 * Due 9/13/16
 */
/*=======================================================================*/
#include <iostream>
#include <stdio.h>
#include <ctime>
#include <math.h>
#include <string.h>


using namespace std;


int main(/*int argc, const char * argv[]*/)
{
/*===============
int day1 = holder[1];
int day2 = holder[2];
int day3 = holder[3];
/*===============*/
//void fetchTime(3)

int greenTime;
char* greenDay[9];//i hate green day for the record.

char monday[] = "monday";
char tuesday[] ="tuesday";
char wednesday[] ="wednesday";
char thursday[] ="thursday";
char friday[] ="friday";
char saturday[] ="saturday";
char sunday[] ="sunday";

int exse1;
int exse2;
int menuSel;

while(1)
{//start of the while loop
cout<<"\n";
printf("Would you like to see what I am doing at a specific hour or right now?\n");
printf("Input 1 to insert a specific hour.\n");
printf("Input 2 to see what I am doing right now.\n");
printf("Input 3 to exit the program.\n");
printf("Selecting: ");
scanf("%d",&menuSel);
cout << "\n";
if (menuSel== 1)
{

printf("Input an hour in military time: ");
//cin >> greenTime;
//cout << greenTime;
scanf("%d",&greenTime);
cout << "\n";

//printf("You input: %s\n", greenTime);
//printf("Input the day all lowercase: ");

printf("Please select a day from the list below.\n");
printf("0: Monday\t1: Tuesday\n");
printf("2: Wednesday\t3: Thursday\n");
printf("4: Friday\t5: Saturday\n");
printf("6: Sunday\n");
cout << "Selecting day: ";


//cin >> greenDay;
//cout << greenDay;
//scanf("%s\n",&greenDay);
scanf("%d", &exse1);
cout<<"\n";

if (greenTime == 0){
	if (exse1==0){printf("On monday, Cracking my back\n");}
	if (exse1==1){printf("On Tuesday, Smuggling drugs to china\n");}
	if (exse1==2){printf("On Wednesday, Lavishing in gravy\n");}
	if (exse1==3){printf("On Thursday, Eating chap stick\n");}
	if (exse1==4){printf("On friday, Bird hunting\n");}
	if (exse1==5){printf("On Saturday, People watching\n");}
	if (exse1==6){printf("On Sunday, Dog watching\n");}
	}// the end of time 0
if (greenTime == 1){
	if (exse1==0){printf("On monday, Putting the lotion on its skin\n");}
        if (exse1==1){printf("On Tuesday, Not coding when I should be\n");}
        if (exse1==2){printf("On Wednesday, Turning all the clocks 20 minutes off\n");}
        if (exse1==3){printf("On Thursday, Hanging posters\n");}
        if (exse1==4){printf("On friday, Electrifing Zooboomafoo\n");}
        if (exse1==5){printf("On Saturday, Staring as Pete the Camel\n");}
        if (exse1==6){printf("On Sunday, Cracking the clams open");}
        }// the end of time 1
if (greenTime == 2){
        if (exse1==0){printf("On monday, Playing the game Farkle\n");}
        if (exse1==1){printf("On Tuesday, Breaking into the NSA\n");}
        if (exse1==2){printf("On Wednesday, Sending my pants to college\n");}
        if (exse1==3){printf("On Thursday, Generating hate mail\n");}
        if (exse1==4){printf("On friday, Really hating on birds\n");}
        if (exse1==5){printf("On Saturday, Training my young grasshopper\n");}
        if (exse1==6){printf("On Sunday, Pronouncing it jif like the peanutbutter\n");}
        }// the end of time 2
if (greenTime == 3){
        if (exse1==0){printf("On monday, Browsing amazon.com\n");}
        if (exse1==1){printf("On Tuesday, Staring at a robo scorpion with lazers\n");}
        if (exse1==2){printf("On Wednesday, Running into a wall\n");}
        if (exse1==3){printf("On Thursday, Studdying the female anatomy\n");}
        if (exse1==4){printf("On friday, Choosing the best super model\n");}
        if (exse1==5){printf("On Saturday, Shucking corn on the cob\n");}
        if (exse1==6){printf("On Sunday, Wondering if you set it to W for wumbo?\n");}
        }// the end of time 3
if (greenTime == 4){
        if (exse1==0){printf("On monday, Refusing to play the lottery\n");}
        if (exse1==1){printf("On Tuesday, Wishing of making it rich on my own\n");}
        if (exse1==2){printf("On Wednesday, Not supporting politics\n");}
        if (exse1==3){printf("On Thursday, Moving to Canada\n");}
        if (exse1==4){printf("On friday, Skateboarding down the Prudential\n");}
        if (exse1==5){printf("On Saturday, Walking a tight rope\n");}
        if (exse1==6){printf("On Sunday, Using the bathroom\n");}
        }// the end of time 4
if (greenTime == 5){
        if (exse1==0){printf("On monday, Flapping my tongue\n");}
        if (exse1==1){printf("On Tuesday, Finding a dumpster baby and saving it\n");}
        if (exse1==2){printf("On Wednesday, Poking holes in condoms\n");}
        if (exse1==3){printf("On Thursday, Taking all the take out menus\n");}
        if (exse1==4){printf("On friday, Thinking of the internet\n");}
        if (exse1==5){printf("On Saturday, Taking out the trash\n");}
        if (exse1==6){printf("On Sunday, DMing yo girl\n");}
        }// the end of time 5
if (greenTime == 6){
        if (exse1==0){printf("On monday, NO NO NO, I WILL NOT LEAVE THE BUILDING FOR A FIRE ALARM.... Fiiiinnneeeeeeeee..........\n");}
        if (exse1==1){printf("On Tuesday, Not giving a shit\n");}
        if (exse1==2){printf("On Wednesday, Reading chinese\n");}
        if (exse1==3){printf("On Thursday, Singking stones in a pot of water\n");}
        if (exse1==4){printf("On friday, Throwing a super huge party\n");}
        if (exse1==5){printf("On Saturday, Calling the pizza guy to the middle of nowhere\n");}
        if (exse1==6){printf("On Sunday, Playing music loud\n");}

        }// the end of time 6
if (greenTime == 7){
        if (exse1==0){printf("On monday, Drag racing with my lincoln towncar\n");}
        if (exse1==1){printf("On Tuesday, Making a new car alternator\n");}
        if (exse1==2){printf("On Wednesday, Cracking my knuckles\n");}
        if (exse1==3){printf("On Thursday, Making the elderly cry\n");}
        if (exse1==4){printf("On friday, Finding Shrek's swamp\n");}
        if (exse1==5){printf("On Saturday, Drinking swamp water\n");}
        if (exse1==6){printf("On Sunday, Defusing magic bombs\n");}
        }// the end of time 7
if (greenTime == 8){
        if (exse1==0){printf("On monday, Stuffing stuff in a suitcase\n");}
        if (exse1==1){printf("On Tuesday, Finding a taco cat...I'm a palindrome\n");}
        if (exse1==2){printf("On Wednesday, Shinning light on a bat\n");}
        if (exse1==3){printf("On Thursday, Rubbing a book\n");}
        if (exse1==4){printf("On friday, Seeing if I will get free health care\n");}
        if (exse1==5){printf("On Saturday, Making people have goosebumps\n");}
        if (exse1==6){printf("On Sunday, Turning the thermostat to 69\n");}
        }// the end of time 8
if (greenTime == 9){
        if (exse1==0){printf("On monday, Sleeping in a hammock\n");}
        if (exse1==1){printf("On Tuesday, Tongue piercing the wild life\n");}
        if (exse1==2){printf("On Wednesday, Rumbling with he big guys\n");}
        if (exse1==3){printf("On Thursday, Developing a new fire starter\n");}
        if (exse1==4){printf("On friday, Shaving balsa wood\n");}
        if (exse1==5){printf("On Saturday, Studdying the female anatomy\n");}
        if (exse1==6){printf("On Sunday, Asking people if they even crop\n");}
        }// the end of time 9
if (greenTime == 10){
        if (exse1==0){printf("On monday, Fighting the Kool-Aid man\n");}
        if (exse1==1){printf("On Tuesday, Developing new child safety scissors\n");}
        if (exse1==2){printf("On Wednesday, Leabing marker caps off so Professor Carpenter can shoot them like Kobe\n");}
        if (exse1==3){printf("On Thursday, Unstitching some fabric\n");}
        if (exse1==4){printf("On friday, Bathing in maple leaves\n");}
        if (exse1==5){printf("On Saturday, Hosting giraffe cage matches");}
        if (exse1==6){printf("On Sunday, Crying into a bowl of pudding");}
        }// the end of time 10
if (greenTime == 11){
        if (exse1==0){printf("On monday, Learning how to spell\n");}
        if (exse1==1){printf("On Tuesday, Starring in a commercial\n");}
        if (exse1==2){printf("On Wednesday, Measuring how tall I am\n");}
        if (exse1==3){printf("On Thursday, Burning an inappropriate image onto an old plasma tv screen\n");}
        if (exse1==4){printf("On friday, Stealing candy from a baby\n");}
        if (exse1==5){printf("On Saturday, Breaking family picture frames\n");}
        if (exse1==6){printf("On Sunday, Using crayons on the drywall\n");}
        }// the end of time 11
if (greenTime == 12){
        if (exse1==0){printf("On monday, Finding my core message\n");}
        if (exse1==1){printf("On Tuesday, Praising Neptune\n");}
        if (exse1==2){printf("On Wednesday, Licking doorknobs\n");}
        if (exse1==3){printf("On Thursday, Thinking of cooking recepies\n");}
        if (exse1==4){printf("On friday, Eating granola and peanutbutter\n");}
        if (exse1==5){printf("On Saturday, Going bumber to bumper\n");}
        if (exse1==6){printf("On Sunday, Trimming a toe nail\n");}
        }// the end of time 12
if (greenTime == 13){
        if (exse1==0){printf("On monday, Vilating an OSHA law\n");}
        if (exse1==1){printf("On Tuesday, Slicing roast beef\n");}
        if (exse1==2){printf("On Wednesday, Mkaing my own footsteps\n");}
        if (exse1==3){printf("On Thursday, Trying to find the elixer of life\n");}
        if (exse1==4){printf("On friday, Experimenting on a turtle\n");}
        if (exse1==5){printf("On Saturday, Spray tanning a baby\n");}
        if (exse1==6){printf("On Sunday, Disturbing the peace\n");}
        }// the end of time 13
if (greenTime == 14){
        if (exse1==0){printf("On monday, corupting the EU\n");}
        if (exse1==1){printf("On Tuesday, playing N64\n");}
        if (exse1==2){printf("On Wednesday, Cutting holes in peoples socks\n");}
        if (exse1==3){printf("On Thursday, Breaking INTO jail\n");}
        if (exse1==4){printf("On friday, Playing GTA V in real life\n");}
        if (exse1==5){printf("On Saturday, Listening to Kendrick Lamar\n");}
        if (exse1==6){printf("On Sunday, Cooking a robust pizza\n");}
        }// the end of time 14
if (greenTime == 15){
        if (exse1==0){printf("On monday, Thinking of my stripper name\n");}
        if (exse1==1){printf("On Tuesday, If my stripper name was Charity\n");}
        if (exse1==2){printf("On Wednesday, I could be asking people\n");}
        if (exse1==3){printf("On Thursday, Money for charity please\n");}
        if (exse1==4){printf("On friday, But really, im just keeping the money\n");}
        if (exse1==5){printf("On Saturday, Damn thats shits good\n");}
        if (exse1==6){printf("On Sunday, Making a glass lamp\n");}
        }// the end of time 15
if (greenTime == 16){
        if (exse1==0){printf("On monday, Breaking the law\n");}
        if (exse1==1){printf("On Tuesday, Making new memes\n");}
        if (exse1==2){printf("On Wednesday, WOOKIE DOOKIE GAZA-MOOPH\n");}
        if (exse1==3){printf("On Thursday, Making Gronk my bitch\n");}
        if (exse1==4){printf("On friday, Invading Cuba\n");}
        if (exse1==5){printf("On Saturday, Burning oil\n");}
        if (exse1==6){printf("On Sunday, RaaaAAAAWRRRRRRR!!!\n");}
        }// the end of time 16
if (greenTime == 17){
        if (exse1==0){printf("On monday, Thinking of a plot for a movie\n");}
        if (exse1==1){printf("On Tuesday, Two brothers\n");}
        if (exse1==2){printf("On Wednesday, Fight an alien race\n");}
        if (exse1==3){printf("On Thursday, Of grandmas controlled by cats\n");}
        if (exse1==4){printf("On friday, Who find love\n");}
        if (exse1==5){printf("On Saturday, With a radioactive tapestry\n");}
        if (exse1==6){printf("On Sunday, Coming this June to theaters everywhere\n");}
        }// the end of time 17
if (greenTime == 18){
        if (exse1==0){printf("On monday, Brewing mead\n");}
        if (exse1==1){printf("On Tuesday, Looking for a challenge\n");}
        if (exse1==2){printf("On Wednesday, Swimming pool full of liquor, and diving in\n");}
        if (exse1==3){printf("On Thursday, Punching a tree\n");}
        if (exse1==4){printf("On friday, Writing poems\n");}
        if (exse1==5){printf("On Saturday, Thinking about the good times\n");}
        if (exse1==6){printf("On Sunday, Determing wether I am insane or not\n");}
        }// the end of time 18
if (greenTime == 19){
        if (exse1==0){printf("On monday, Bringing Bowser to a day care\n");}
        if (exse1==1){printf("On Tuesday, Grumbling like an old man\n");}
        if (exse1==2){printf("On Wednesday, Spilling orange juice in the microwave\n");}
        if (exse1==3){printf("On Thursday, Using two ply like its no tomorrow\n");}
        if (exse1==4){printf("On friday, Turning to the dark side of the force\n");}
        if (exse1==5){printf("On Saturday, Slurping my soup loud in Japan\n");}
        if (exse1==6){printf("On Sunday, Watching stranger things\n");}
        }// the end of time 19
if (greenTime == 20){
        if (exse1==0){printf("On monday, Breaking glass bottles\n");}
        if (exse1==1){printf("On Tuesday, Cleaning my boots\n");}
        if (exse1==2){printf("On Wednesday, Developing a new super conductor\n");}
        if (exse1==3){printf("On Thursday, Racing a beever in a chewing contest\n");}
        if (exse1==4){printf("On friday, Shaving a cat\n");}
        if (exse1==5){printf("On Saturday, Sharpening a pencil\n");}
        if (exse1==6){printf("On Sunday, Leaving the two end slices of bread in the bag\n");}
        }// the end of time 20
if (greenTime == 21){
        if (exse1==0){printf("On monday, Scratching all your CD's\n");}
        if (exse1==1){printf("On Tuesday, Letting the cold out of the freezer\n");}
        if (exse1==2){printf("On Wednesday, Recycling stemcells\n");}
        if (exse1==3){printf("On Thursday, Licking sand paper\n");}
        if (exse1==4){printf("On friday, Flipping a knife\n");}
        if (exse1==5){printf("On Saturday, Watching Arthur\n");}
        if (exse1==6){printf("On Sunday, Feeling triggered\n");}
        }// the end of time 21
if (greenTime ==22){
        if (exse1==0){printf("On monday, Finding out all the genders\n");}
        if (exse1==1){printf("On Tuesday, Helping the ozone\n");}
        if (exse1==2){printf("On Wednesday, Burning trees\n");}
        if (exse1==3){printf("On Thursday, Spitting on babies\n");}
        if (exse1==4){printf("On friday, Tearing a butterfly in half\n");}
        if (exse1==5){printf("On Saturday, Cranking a crank shaft\n");}
        if (exse1==6){printf("On Sunday, Breaking a rabbits foot\n");}
        }// the end of time 22
if (greenTime == 23){
        if (exse1==0){printf("On monday, Eating bugs\n");}
        if (exse1==1){printf("On Tuesday, Drawing on a crab shell\n");}
        if (exse1==2){printf("On Wednesday, Spraypainting the elderly\n");}
        if (exse1==3){printf("On Thursday, Jumping out of an air vent\n");}
        if (exse1==4){printf("On friday, Racing ratcoons\n");}
        if (exse1==5){printf("On Saturday, Thinking of the color green\n");}
        if (exse1==6){printf("On Sunday, Writing C code\n");}
        }// the end of time 23
//printf("Would you like to look at the schedule again?\n")

}//this is the end of inserting a specific hour.
//end of menuSel==1
if (menuSel==2)
{
printf("At this specific hour: ");
char buff[100];
time_t currentTime;
struct tm *holder;

char dogs[10]="monday";
char grapes[10];
printf("type monday: ");
scanf("%s",grapes);
int ruby;
ruby = !strcmp(dogs,grapes);
if(ruby=1)
	{
	printf("the same");
	}
//time(&currentTime);
holder = localtime(&currentTime);
int ilmao = strftime(buff,100,"%H", holder);
puts(buff);

time(&currentTime);

//printf(currentTime);

//cout << "\n";
printf("Current Local Time and Date: %s", asctime(holder));
//printf("%d\n",ilmao);// prints the number of todays day on the calendar.
}// the end of whats im doing right now.

else if (menuSel ==3)
{
printf("Exiting Program. . .\n");
return 0;
}
//printf("%d%d%d",day1,day2,day3);
//cout << "Current local time and date: ", asctime(holder);
//printf("\n");
//printf("the hour is: %s", tm_hour);

//after you first selected an option and went through with it,
//the program asks you if you want to select another time or end the program.
cout<<"\n";
printf("Would you like to choose again?\n");
printf("Select 1 for yes\nSelect 2 for no\n");
int pick;
printf("Selecting: ");
scanf("%d",&pick);
if (pick ==1)
	{/*going back to the top of the big loop*/	}
else if (pick==2)
	{
	printf("Exiting Program. . .\n");
	return 0;
	}

}//end of big loop
}//This is the end of main



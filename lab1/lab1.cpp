/*
 * Mike Hickey
 * Professor Carpenter
 * Lab 1
 * Due Date 9/12/16
 */
/*===================================================================*/
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

int main ()
{
int n = 20; // Setting a constant integer to 20.
int i = 0;  // for dow
int j = 19; // for carp
int k = 0;  // for derb
int p = 0;  // for counting


//int lenDow;
//int lenCarp;

int dow[19];
int carp[19];
int derb[19]; // a place holder
for (i=0; i<n; i++)
{
	//cout << "On number: " << i <<"\n";
	dow[i] = i;
	cout << dow[i] << "\n";
}//The end of the for loop that counts from 0-19.
cout << "Writing a new array but backwards, not swapping positions.\n";
//cout << "Now we will reverse the array\n";
//fflush(stdout); // im trying to get rid of the 6563432 number thing.

for(j=19; j>=0; j--)
{
	carp[j]=j;
	cout << carp[j] << "\n";
}
cout << "This is swapping the positions of the array.\n";

//seriously making lenDow as 19. but say i didnt know the array size...
//sizeof dow[19] = lenDow;
//sizeof carp[19] = lenCarp;

//lenDow = sizeof dow[19];
//lenCarp = sizeof carp[19];
//cout << lenDow;
//cout << lenCarp;

for (p=0; p<n; p++)
{
	//dow[i] = carp[j];
	//carp[j] = derb[k];
	//derb[k] = dow[i];
	//this was producing crap and 0 19 0 19 0 19

	//notice how the position of the array needs to be the same
	//number as the position of the loop.
	//derb[p] = dow[p];
	dow[p] = carp[n-1-p];
	//carp[n-p] = derb[p];

	cout << dow[p] <<"\n";
}


	//cout << dow[i] << "\n";
//The end of the swapping loop

cout << "End of Program\n";
return 0;//sure

}//End of main.

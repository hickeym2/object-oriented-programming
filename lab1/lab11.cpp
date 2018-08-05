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

//These integers are for making the arrays and swapping them in a loop with a place holder.
int n = 20; // Setting a constant integer to 20.
int i = 0;  // for dow
int j = n-1; // for carp
int k = 0;  // for derb
int p = 0;  // for counting

//my trying to make it much harder{
//int lenDow;
//int lenCarp;
//}

int dow[n-1];
int carp[n-1];
int derb[n-1]; // a place holder


for (i=0; i<n; i++)
{
	//I am counting with the number n and the number i
	//So the array can be any size and the loop will always count to it.
	//cout << "On number: " << i <<"\n"; // checking my work.
	//i is the number for indexing the dow loop.
	dow[i] = i;
	cout << dow[i] << "\n";
}//The end of the for array that counts from 0-19. So the original loop.


cout << "Writing a new array but backwards, not swapping positions.\n";
//cout << "Now we will reverse the array\n";
//fflush(stdout); // im trying to get rid of the 6563432 number thing.
//nah we dont need that stuff.


for(j=n-1; j>=0; j--)
	{
	//to loop the array backwards, the starting position will be the array size -1
	// we want to index the position of 0 so i am using j>=0
	//and j is just a number to index for the carp loop
	carp[j]=j;
	cout << carp[j] << "\n";
	}//the end of making the reversed array.
cout << "This is swapping the positions of the array.\n";


for (p=0; p<n; p++)
	{
	//my first attempt at passing the variables contents to one another.
	/*======================================================================*/
	//dow[i] = carp[j];
	//carp[j] = derb[k];
	//derb[k] = dow[i];
	//this was producing crap and 0 19 0 19 0 19

	//notice how the position of the array needs to be the same
	//number as the position of the loop.
	//derb[p] = dow[p];
	/*========================================================================*/

	//in the end, i really only had to assign the original array to the reversed array position
	//while still maintaining what was properly index.
	dow[p] = carp[n-1-p];
	//carp[n-p] = derb[p];

	//so i am printing the original dow array after it has been swapped with the carp array.
	cout << dow[p] <<"\n";



	//cout << dow[i] << "\n";
	}//The end of the swapping loop

cout << "End of Program\n";
return 0;//sure

}//End of main.

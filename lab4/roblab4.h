#include <iostream>
using namespace std;

void insertO(char TTTarray[3][3]);

void insertO(char TTTarray[3][3])
{
        //Winning moves (Priority #1)
        if(TTTarray[0][0] == 'O' and TTTarray[2][0] == 'O' and TTTarray[1][0] == '-')
                {
                        TTTarray[1][0] = 'O';
                }
        else if(TTTarray[0][0] == 'O' and TTTarray[1][0] == 'O' and TTTarray[2][0] == '-')
                {
                        TTTarray[2][0] = 'O';
                }
        else if(TTTarray[0][0] == 'O' and TTTarray[2][2] == 'O' and TTTarray[1][1] == '-')
                {
                        TTTarray[1][1] = 'O';
                }
        else if(TTTarray[0][0] == 'O' and TTTarray[1][1] == 'O' and TTTarray[2][2] == '-')
                {
                        TTTarray[2][2] = 'O';
                }
        else if(TTTarray[0][0] == 'O' and TTTarray[0][2] == 'O' and TTTarray[0][1] == '-')
                {
                        TTTarray[0][1] = 'O';
                }
        else if(TTTarray[0][0] == 'O' and TTTarray[0][1] == 'O' and TTTarray[0][2] == '-')
                {
                        TTTarray[0][2] = 'O';
                }
        else if(TTTarray[0][2] == 'O' and TTTarray[2][0] == 'O' and TTTarray[1][1] == '-')
                {
                        TTTarray[1][1] = 'O';
                }
        else if(TTTarray[0][2] == 'O' and TTTarray[1][1] == 'O' and TTTarray[2][0] == '-')
                {
                        TTTarray[2][2] = 'O';
                }
        else if(TTTarray[0][2] == 'O' and TTTarray[2][2] == 'O' and TTTarray[1][2] == '-')
                {
                        TTTarray[1][2] = 'O';
                }
        else if(TTTarray[0][2] == 'O' and TTTarray[1][2] == 'O' and TTTarray[2][2] == '-')
                {
                        TTTarray[2][2] = 'O';
                }
        else if(TTTarray[2][0] == 'O' and TTTarray[1][0] == 'O' and TTTarray[0][0] == '-')
                {
                        TTTarray[0][0] = 'O';
                }
        else if(TTTarray[2][0] == 'O' and TTTarray[1][1] == 'O' and TTTarray[0][2] == '-')
                {
                        TTTarray[0][2] = 'O';
                }
        else if(TTTarray[2][0] == 'O' and TTTarray[2][1] == 'O' and TTTarray[2][2] == '-')
                {
                        TTTarray[2][2] = 'O';
                }
        else if(TTTarray[2][0] == 'O' and TTTarray[2][2] == 'O' and TTTarray[2][1] == '-')
                {
                        TTTarray[2][1] = 'O';
                }
        else if(TTTarray[2][2] == 'O' and TTTarray[2][1] == 'O' and TTTarray[2][0] == '-')
                {
                        TTTarray[2][0] = 'O';
                }
        else if(TTTarray[2][2] == 'O' and TTTarray[1][1] == 'O' and TTTarray[0][0] == '-')
                {
                        TTTarray[0][0] = 'O';
                }
        else if(TTTarray[2][2] == 'O' and TTTarray[0][2] == 'O' and TTTarray[0][2] == '-')
                {
                        TTTarray[0][2] = 'O';
                }
        else if(TTTarray[1][0] == 'O' and TTTarray[1][2] == 'O' and TTTarray[1][1] == '-')
                {
                        TTTarray[1][1] = 'O';
                }
        else if(TTTarray[1][0] == 'O' and TTTarray[1][1] == 'O' and TTTarray[1][2] == '-')
                {
                        TTTarray[1][2] = 'O';
                }
        else if(TTTarray[0][1] == 'O' and TTTarray[2][1] == 'O' and TTTarray[1][1] == '-')
                {
                        TTTarray[1][1] = 'O';
                }
        else if(TTTarray[0][1] == 'O' and TTTarray[1][1] == 'O' and TTTarray[2][1] == '-')
                {
                        TTTarray[2][1] = 'O';
                }
        else if(TTTarray[1][2] == 'O' and TTTarray[1][1] == 'O'  and  TTTarray[1][0] == '-')
                {
                        TTTarray[1][0] = 'O';
                }
        else if(TTTarray[2][1] == 'O' and TTTarray[1][1] == 'O' and TTTarray[0][1] == '-')
                {
                        TTTarray[0][1] = 'O';
                }

        //Defense (Priority #2)
        else if(TTTarray[0][0] == 'X' and TTTarray[2][0] == 'X' and TTTarray[1][0] == '-')
                {
                        TTTarray[1][0] = 'O';
                }
        else if(TTTarray[0][0] == 'X' and TTTarray[1][0] == 'X' and TTTarray[2][0] == '-')
                {
                        TTTarray[2][0] = 'O';
                }
        else if(TTTarray[0][0] == 'X' and TTTarray[2][2] == 'X' and TTTarray[1][1] == '-')
                {
                        TTTarray[1][1] = 'O';
                }
        else if(TTTarray[0][0] == 'X' and TTTarray[1][1] == 'X' and TTTarray[2][2] == '-')
                {
                        TTTarray[2][2] = 'O';
                }
        else if(TTTarray[0][0] == 'X' and TTTarray[0][2] == 'X' and TTTarray[0][1] == '-')
                {
                        TTTarray[0][1] = 'O';
                }
        else if(TTTarray[0][0] == 'X' and TTTarray[0][1] == 'X' and TTTarray[0][2] == '-')
                {
                        TTTarray[0][2] = 'O';
                }
        else if(TTTarray[0][2] == 'X' and TTTarray[2][0] == 'X' and TTTarray[1][1] == '-')
                {
                        TTTarray[1][1] = 'O';
                }
        else if(TTTarray[0][2] == 'X' and TTTarray[1][1] == 'X' and TTTarray[2][0] == '-')
                {
                        TTTarray[2][2] = 'O';
                }
        else if(TTTarray[0][2] == 'X' and TTTarray[2][2] == 'X' and TTTarray[1][2] == '-')
                {
                        TTTarray[1][2] = 'O';
                }
        else if(TTTarray[0][2] == 'X' and TTTarray[1][2] == 'X' and TTTarray[2][2] == '-')
                {
                        TTTarray[2][2] = 'O';
                }
        else if(TTTarray[2][0] == 'X' and TTTarray[1][0] == 'X' and TTTarray[0][0] == '-')
                {
                        TTTarray[0][0] = 'O';
                }
        else if(TTTarray[2][0] == 'X' and TTTarray[1][1] == 'X' and TTTarray[0][2] == '-')
                {
                        TTTarray[0][2] = 'O';
                }
        else if(TTTarray[2][0] == 'X' and TTTarray[2][1] == 'X' and TTTarray[2][2] == '-')
                {
                        TTTarray[2][2] = 'O';
                }
        else if(TTTarray[2][0] == 'X' and TTTarray[2][0] == 'X' and TTTarray[2][1] == '-')
                {
                        TTTarray[2][1] == 'O';
                }
        else if(TTTarray[2][2] == 'X' and TTTarray[2][1] == 'X' and TTTarray[2][0] == '-')
                {
                        TTTarray[2][0] = 'O';
                }
        else if(TTTarray[2][2] == 'X' and TTTarray[1][1] == 'X' and TTTarray[0][0] == '-')
                {
                        TTTarray[0][0] = 'O';
                }
        else if(TTTarray[2][2] == 'X' and TTTarray[0][2] == 'X' and TTTarray[0][2] == '-')
                {
                        TTTarray[0][2] = 'O';
                }
        else if(TTTarray[1][0] == 'X' and TTTarray[1][2] == 'X' and TTTarray[1][1] == '-')
                {
                        TTTarray[1][1] = 'O';
                }
        else if(TTTarray[1][0] == 'X' and TTTarray[1][1] == 'X' and TTTarray[1][2] == '-')
                {
                        TTTarray[1][2] = 'O';
                }
        else if(TTTarray[0][1] == 'X' and TTTarray[2][1] == 'X' and TTTarray[1][1] == '-')
                {
                        TTTarray[1][1] = 'O';
                }
        else if(TTTarray[0][1] == 'X' and TTTarray[1][1] == 'X' and TTTarray[2][1] == '-')
                {
                        TTTarray[2][1] = 'O';
                }
        else if(TTTarray[1][0] == 'X' and TTTarray[1][1] == 'X' and TTTarray[2][1] == '-')
                {
                        TTTarray[2][1] = 'O';
                }
        else if(TTTarray[1][2] == 'X' and TTTarray[1][1] == 'X' and TTTarray[1][0] == '-')
                {
                        TTTarray[1][0] = 'O';
                }
        else if(TTTarray[2][1] == 'X' and TTTarray[1][1] == 'X' and TTTarray[0][1] == '-')
                {
                        TTTarray[0][1] = 'O';
                }

        //In case none of the above moves are valid
        else
        {
                for (int j = 0; j < 3; j++)
                {
                        for (int i = 0; i < 3; i++)
                        {
                                if(TTTarray[i][j] == '-')
                                {
                                        TTTarray[i][j] = 'O';
                                        goto Done;
                                }
                        }
                }
	Done:;
        }
}


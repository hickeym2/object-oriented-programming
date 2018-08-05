/*
 * Michael Hickey
 * Professor Carpenter
 * Lab 9 Inheritance and Classes
 * Due November 21, 2016
 */

#include <iostream>
#include <string>

using namespace std;

class Person_c{
	protected:
		string name;
		string homeCity;
		int age;
	public:
		//Default constructor
		Person_c(){cout << "A Person_c was created." << endl;}

		//Constructor with parameter
		Person_c(string name1, string homeCity1, int age1){
			cout << "A Person_c was created with arguments." << endl;
			name = name1;
			homeCity = homeCity1;
			age = age1;
		}

		//Defualt deconstructor
		~Person_c();

		//Get Functions

		//Set Functions

};//end of class Player_c


class Student_c:public Person_c{
	protected:
		string school;
		int classYear;
		float gradYear;

	public:
		/*
		//Default Constructor
		Student_c(string name1, string homeCity1, int age1, string school1 
			,int classYear1
			,float gradYear1):Person_c()
			school(school1), 
			classYear(classYear1), 
			gradYear(gradYear1);

			cout << "A Student_c was created." << endl;

		//Default Deconstructor
		~Student_c();
		*/

		Student_c(string school1, int classYear1, float gradYear1):Person_c(name1, homecity1, age1){
			school = school1;
			classYear = classYear1;
			gradYear = gradYear1;
		}
		

		//Get Functions

		//Set Functions

};//end of class Student_c

/*
class Intern_c:public Student_c{
	protected:
		string company;
		double weeklyPay;
		struct dateOfCompletion{
			int day;
			int year;
			string month;
		};
		dateOfCompletion completionDate;
	public:
		//Default Constructor
		Intern_c():Student_c(school, classYear, dateOfGraduation){
		
		}

};
*/


int main(){

}

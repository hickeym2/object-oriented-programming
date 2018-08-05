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
		
		//Person_c(string name, string homeCity, int age): name(name), homeCity(homeCity), age(age) {cout << "A Person_c was created." << endl;}

		//Defualt deconstructor
		~Person_c(){};

		//Get Functions
		string getName(){
			return name;
		}
		string getHomeCity(){
			return homeCity;
		}
		int getAge(){
			return age;
		}

		//Set Functions
		void setName(string name1){
			name = name1;
		}

		void setHomeCity(string homeCity1){
			homeCity = homeCity1;
		}

		void setAge(int age1){
			age = age1;
		}
		void setPerson(string n, string hc, int a){
			name = n;
			homeCity = hc;
			age = a;
		}
};//end of class Player_c


class Student_c:public Person_c{
	protected:
		string school;
		int classYear;
		float gradYear;

	public:
		
		//Default Constructor
		Student_c();

		//Student_c(string school, int classYear, float gradYear):Person_c("VOID", "VOID", 0){}

		Student_c(string school1, int classYear1, float gradYear1){
			school = school1;
			classYear = classYear1;
			gradYear = gradYear1;
		}

		~Student_c(){};

		//Get Functions
		string getSchool(){
			return school;
		}
		int getClassYear(){
			return classYear;
		}
		float getGradYear(){
			return gradYear;
		}

		//Set Functions
		void setSchool(string school1){
			school = school1;
		}
		void setClassYear(int classYear1){
			classYear = classYear1;
		}
		void setGradYear(float gradYear1){
			gradYear = gradYear1;
		}
		void setStudent(string s, int cy, float gy){
			school = s;
			classYear = cy;
			gradYear = gy;
		}
};//end of class Student_c


class Intern_c:public Student_c{
	protected:
		string company;
		double weeklyPay;
		string dateOfCompletion;
		/*
		struct dateOfCompletion{
			int day;
			int year;
			string month;
		};
		*/
		
	public:
		//Default Constructor
		Intern_c();
		Intern_c(string company1, double weeklyPay1, string dateOfCompletion1){
			company = company1;
			weeklyPay = weeklyPay1;
			dateOfCompletion = dateOfCompletion1;
		}
		~Intern_c(){}

		//Get Funcitons
			string getCompany(){
				return company;
			}
			double getWeeklyPay(){
				return weeklyPay;
			}
			string getDateOfCompletion(){
				return dateOfCompletion;
			}
		//Set Functions
			void setCompany(string company1){
				company = company1;
			}
			void setWeeklyPay(double weeklyPay1){
				weeklyPay = weeklyPay1;
			}
			void setDateOfCompletion(string doc){
				dateOfCompletion = doc;
			}
			void setIntern(string comp, double wp, string doc){
				company = comp;
				weeklyPay = wp;
				dateOfCompletion = doc;
			}

};



int main(){
	//Student_c student1("WIT", 2018, 5.318008);
	//student1.setName("Mike");
	//student1.setHomeCity("Pembroke");
	//student1.setAge(21);
	//cout << student1.getName() << endl;
	
	Intern_c intern1("Payette", 17.5, "April 23, 2017");
	intern1.setStudent("WIT", 2014, 8.2018);
	intern1.setPerson("Mike Hickey", "Pembroke", 21);
}

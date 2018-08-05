/*
 * Michael Hickey
 * Professor Carpenter
 * Lab 9 Inheritance and Classes
 * Due November 21, 2016
 */

#include <iostream>
#include <string>
#include <fstream> //I want to use get line

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
		~Person_c(){cout << "A Person_c was destroyed." << endl;}

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

		//Special Functions
		void printPerson(){
			cout << "Name: " << name << endl;
			cout << "Home City: " << homeCity << endl;
			cout << "Age: " << age << endl;
		}
};//end of class Player_c


class Student_c:public Person_c{
	protected:
		string school;
		int classYear;
		float gradYear;

	public:
		
		//Default Constructor
		Student_c(){}

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

		//Special Functions
		void printStudent(){
			cout << "Name: " << name << endl;
			cout << "Home City: " << homeCity << endl;
			cout << "Age: " << age << endl;
			cout << "School: " << school << endl;
			cout << "Class year: " << classYear << endl;
			cout << "Graduation year: " << gradYear << endl;
		}
};//end of class Student_c


class Intern_c:public Student_c{
	protected:
		string company;
		double weeklyPay;
		string dateOfCompletion;
		string skills[50];
	public:
		//Default Constructor
		Intern_c(){}

		Intern_c(string company1, double weeklyPay1, string dateOfCompletion1){
			company = company1;
			weeklyPay = weeklyPay1;
			dateOfCompletion = dateOfCompletion1;
			//initializing the skills to ""
			for(int i = 0; i < 50; i++){
				skills[i] = "";
			}
		}

		//Defauly deconstructor
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
		string getSpecificSkill(int index){
			return skills[index];
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
		void setSpecificSkill(string skill, int index){
			skills[index] = skill;
		}

		//Special Functions
		void printIntern(){
			cout << "Name: " << name << endl;
			cout << "Home City: " << homeCity << endl;
			cout << "Age: " << age << endl;
			cout << "School: " << school << endl;
			cout << "Class year: " << classYear << endl;
			cout << "Graduation year: " << gradYear << endl;
			cout << "Company: " << company << endl;
			cout << "Weekly Pay: " << weeklyPay << endl;
			cout << "Date of Completion: " << dateOfCompletion << endl;
			cout << endl;
			cout << "=== Intern Skills ===" << endl;
			printSkills();
			cout << "=====================" << endl;
			cout << endl;
		}//end of printIntern()

		void setSkill(string theSkill){
			for(int i = 0; i < 50; i++){
				if(!skills[i].compare("")){
					skills[i] = theSkill;
					break;
				}
			}
		}//end of setSkill()

		void printSkills(){
			for(int i = 0; i < 50; i++){
				if(!skills[0].compare("")){
					cout << "The intern has no skills." << endl;
					break;
				}
				if(skills[i].compare("")){
					cout << "Skill " << i+1 << ": " << skills[i] << endl;
				}
			}
		}//end of printSkills()

};

void clearScreen(){
	for(int i = 0; i < 45; i++){
		cout << endl;
	}
}//end of clearScreen()

void showGetFunctions(Person_c person1, Student_c student1, Intern_c intern1){
	cout << person1.getName() << endl;
	cout << person1.getHomeCity() << endl;
	cout << person1.getAge() << endl;
	cout << endl;
	cout << student1.getName() << endl;
	cout << student1.getHomeCity() << endl;
	cout << student1.getAge() << endl;
	cout << student1.getSchool() << endl;
	cout << student1.getClassYear() << endl;
	cout << student1.getGradYear() << endl;
	cout << endl;
	cout << intern1.getName() << endl;
	cout << intern1.getHomeCity() << endl;
	cout << intern1.getAge() << endl;
	cout << intern1.getSchool() << endl;
	cout << intern1.getClassYear() << endl;
	cout << intern1.getGradYear() << endl;
	cout << intern1.getCompany() << endl;
	cout << intern1.getWeeklyPay() << endl;
	cout << intern1.getDateOfCompletion() << endl;
	//getting a skill at index 0.
	cout << intern1.getSpecificSkill(0) << endl;
	cout << endl;
}//end of showGetFunctions

void showSetFunctions(){
	cout << endl;
	Person_c person2;
	Student_c student2;
	Intern_c intern2;

	cout << endl;
	cout << "This is making new objects for the 3 classes and using only the set functions, then printing." << endl;
	cout << endl;
	person2.setName("Douglas Curshaw The 15th");
	person2.setHomeCity("Lumbridge");
	person2.setAge(5);

	student2.setName("Broken Arrow");
	student2.setHomeCity("Los Angeles");
	student2.setAge(88);
	student2.setSchool("University of Disney");
	student2.setClassYear(2012);
	student2.setGradYear(2016);

	intern2.setName("Harambe");
	intern2.setHomeCity("Cincinati");
	intern2.setAge(12);
	intern2.setSchool("Harambe Institute of Bananas");
	intern2.setClassYear(2033);
	intern2.setGradYear(2037);
	intern2.setCompany("OOO OOOh OOOhhh *Monkey Sounds* Inc.");
	intern2.setWeeklyPay(1000000);
	intern2.setDateOfCompletion("Spring of 2041");
	//setting the skill at index 0.
	intern2.setSpecificSkill("Peeling Bananas", 0);

	person2.printPerson();
	cout << endl;
	student2.printStudent();
	cout << endl;
	intern2.printIntern();
}//end of showSetFunctions


int main(){
	clearScreen();

	//Variable Declaration
	string skill;
	int numSkills = 0;
	string choice; //this is the choice to check if you want to exhibit all the get funcitons.

	//Making a Person_c
	Person_c person1("Corn Man", "Drake's Farm", 27);

	//Making a Student_c
	Student_c student1("Umass Boston", 2010, 5.2014);
	student1.setPerson("Sir. Schmoopy of Awesometon", "Shrek's Swamp", 69);

	//Making an Intern_c
	Intern_c intern1("Payette Associates Inc.", 20*40, "April 23, 2017");
	intern1.setStudent("WIT", 2014, 8.2018);
	intern1.setPerson("Mike Hickey", "Pembroke", 21);
	
	cout << endl; //Separate constructors

	intern1.setSkill("C++ (Manually Inserted Skill)");

	cout << "An intern can have up to 50 skills." << endl;
	cout << "How many skills do you want to add?" << endl;
	cout << "Number of Skills: ";
	cin  >> numSkills;
	for(int i = 0; i <= numSkills; i++){
		cout << "Enter a skill." << endl;
		cout << "Skill: ";
		getline(cin, skill);
		intern1.setSkill(skill);
	}
	cout << endl;

	//Printing out the attributes of the objects.
	cout << "Person_c: person1." << endl;
	person1.printPerson();
	cout << endl;
	cout << "Student_c: student1." << endl;
	student1.printStudent();
	cout << endl;
	cout << "Intern_c: intern1." << endl;
	intern1.printIntern();

	//Specifically using only the get functions here.
	cout << "Do you want to see the use of every get function?" << endl;
	cout << "Insert y/n: ";
	cin  >> choice;
	if(!choice.compare("y") || !choice.compare("Y")){
		showGetFunctions(person1, student1, intern1);
	}

	cout << endl;
	cout << "Do you want to see the use of every set function?" << endl;
	cout << "Insert y/n: ";
	cin  >> choice;
	if(!choice.compare("y") || !choice.compare("Y")){
		showSetFunctions();
	}
}//end of main

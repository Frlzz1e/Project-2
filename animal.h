/************************************************************
	Filename:      animal.h
	Author:        Bernie Friesel and Nathan Lopp
	Date Created:  10/24/2024
	Purpose:       The two data classes for our program 2
*************************************************************/

#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
using namespace std;

/*********************************************************** 
Title: FinInfo
Purpose: Class that stores the financial info for each Pet
***********************************************************/
class FinInfo
{
	private:
		double currentBal; //Outstanding balance for the pet
		double Paid; //Amount paid to the Balance
		double tips; //Any Tips given

	public:
		// Default constructor initializing balance, paid amount, and tips to 0.
		FinInfo()
		{
			currentBal = 0.00;
			Paid = 0.00;
			tips = 0.00;
		}

		// Overloaded constructor initializing with specific balance, paid, and tip values
		FinInfo(double balance, double paid, double tip)
		{
			currentBal = balance;
			Paid = paid;
			tips = tip;
		}

		//Setters for currentBal, paid, and tips
		void setbalance(double givenbalance);
		void setpaid(double givenpaid);
		void settip(double giventip);

		//Getters for cuurentBal, paid , amd tips
		double getbalance();
		double getpaid();
		double gettip();
};

/*********************************************************** 
Title: Pet
Purpose: Class that stores information about Pets entered
 into the Veterinary office.
***********************************************************/
class Pet
{
	private:
		string type; //Animal type
		string name; // Pet's name
		int age; //Age of Pet
		FinInfo FinacialObject; //Financial info of the Pet
		
	public:
		//Default constructor initializing an empty Pet object
		Pet(){};
		//Overloaded constructor initializing with type, name, age, and financial imfo
	    Pet(string t, string n, int a, FinInfo f)
		{
			this->type = t;
			this->name = n;
			this->age = a;
			this->FinacialObject = f;
		}

		//Setters for Pet type, name, age , and financial info
		void setFin(FinInfo givenFin);
		void setType(string givenType);
		void setName(string givenName);
		void setAge(int givenAge);

		//Getter for financial info
		FinInfo getObject();

		//Getter for age (Used in sorting)
		int getAge() 
		{ 
			return age; 
		}

	
		//OVERLOADED << OPERATOR to display the pet with cout <<
		friend ostream & operator << (ostream & os, Pet p)
		{
			os << "\nAnimal Type: \t" << p.type;
			os << "\nAnimal Name: \t" << p.name;
			os << "\nAnimal Age: \t" << p.age;
			os << "\nCurrent Balance: \t" << p.FinacialObject.getbalance();
			os << "\nPaid towards Balance: \t" << p.FinacialObject.getpaid();
			os << "\nTips: \t" << p.FinacialObject.gettip();
			return os;
		}
};


#endif
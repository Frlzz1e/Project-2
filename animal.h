/************************************************************
	Filename:      animal.h
	Author:        Bernie Friesel and NAthan Lopp
	Date Created:  10/24/2024
	Purpose:       The two data classes for our program 2
*************************************************************/

#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

using namespace std;

class FinInfo
{
	private:
		double currentBal;
		double Paid;
		double tips;

	public:
		FinInfo()
		{
			currentBal = 0.00;
			Paid = 0.00;
			tips = 0.00;
		}

		FinInfo(double balance, double paid, double tip)
		{
			currentBal = balance;
			Paid = paid;
			tips = tip;
		}

		void setbalance(double givenbalance);
		void setpaid(double givenpaid);
		void settip(double giventip);

		double getbalance();
		double getpaid();
		double gettip();

};


class Pet
{
	private:
		string type;
		string name;
		int age;
		FinInfo FinacialObject;
		
		
	public:
		//CONSTRUCTORS
		Pet(){};
	    Pet(string t, string n, int a, FinInfo f)
		{
			this->type = t;
			this->name = n;
			this->age = a;
			this->FinacialObject = f;
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

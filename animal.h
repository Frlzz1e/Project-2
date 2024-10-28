/************************************************************
	Filename:      Pickle.h
	Author:        April R. Crockett
	Date Created:  2/24/2021
	Purpose:       Class specification file for a Pickle
	               which will be used in 
				   CSC 1310 LAB 5 on Template Linked List
*************************************************************/

#ifndef ANIMAL_H
#define ANIMAL_H

using namespace std;

class Pet
{
	private:
		string type;
		string name;
		int age;
		
		
	public:
		//CONSTRUCTORS
	    Pet(){} 
	    Pet(string t, string n, int a)
		{
			this->type = t;
			this->name = n;
			this->age = a;
		}

//OVERLOADED << OPERATOR to display the pet with cout <<
		friend ostream & operator << (ostream & os, Pet p)
		{
			os << "\nAnimal Type: \t" << p.type;
			os << "\nAnimal Name: \t" << p.name;
			os << "\nAnimal Age: \t" << p.age;
			return os;
		}


};

#endif

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

class Pet
{
	private:
		string type;
		string name;
		int age;
		double balance;
		
		
	public:
		//CONSTRUCTORS
	    Pet(){} 
	    Pet(string t, string n, int a)
		{
			this->type = t;
			this->name = n;
			this->age = a;
		}
		
};

#endif

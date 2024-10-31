/************************************************************
	Filename:      animal.cpp
	Author:        Bernie Friesel and Nathan Lopp
	Date Created:  10/24/2024
	Purpose:       Our setters and getters for out financial class
*************************************************************/
#include "animal.h"
#include <iostream>

using namespace std;

void Pet::setFin(FinInfo givenFin) {FinacialObject = givenFin;}
void Pet::setType(string givenType) {type = givenType;}
void Pet::setName(string givenName) {name = givenName;}
void Pet::setAge(int givenAge) {age = givenAge;}

void FinInfo::setbalance(double givenbalance) {currentBal = givenbalance;} 
void FinInfo::setpaid(double givenpaid) {Paid = givenpaid;}
void FinInfo::settip(double giventip){tips = giventip;}

double FinInfo::getbalance() {return currentBal;}
double FinInfo::getpaid() {return Paid;}
double FinInfo::gettip() {return tips;}
FinInfo Pet::getObject(){return FinacialObject;}
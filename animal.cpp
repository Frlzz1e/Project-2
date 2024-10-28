#include "animal.h"
#include <iostream>

using namespace std;


void FinInfo::setbalance(double givenbalance) {currentBal = givenbalance;} 
void FinInfo::setpaid(double givenpaid) {Paid = givenpaid;}
void FinInfo::settip(double giventip){tips = giventip;}

double FinInfo::getbalance() {return currentBal;}
double FinInfo::getpaid() {return Paid;}
double FinInfo::gettip() {return tips;}
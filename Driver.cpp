#include <iostream>
#include <cctype>  //for the toupper function
#include <limits>  //to use numeric_limits
#include "LinkedList.h"
#include "animal.h"

int main(){

    LinkedList<Pet>list;
	int num;
	char response;

//ADD SOME animals
	cout << "\n\nAdding the current animals to the linked list!\n\n";
	Pet animal1("Dog", "Dolly", 8);
	list.appendNode(animal1);
	
	Pet animal2("Cat", "Lucy", 4);
	list.appendNode(animal2);
	
	Pet animal3("Rabbit", "Bob", 2);
	list.appendNode(animal3);
	
	Pet animal4("Dragon", "Elliot", 643);
	list.appendNode(animal4);
	
	Pet animal5("Deer", "Bambi", 10);
	list.appendNode(animal5);
	
	cout << "\n\nNow printing out the pickles:\n\n";
	list.displayList();

}
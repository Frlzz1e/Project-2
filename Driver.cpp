#include <iostream>
#include <cctype>  //for the toupper function
#include <limits>  //to use numeric_limits
#include "LinkedList.h"
#include "animal.h"

int main(){

    LinkedList<Pet>list;  
    srand(time(0));
    int count = 0;
    int choice;
    int menuChoice;
    int randomDescription = (rand() % 3) + 1;

//ADD SOME animals
	cout << "\n\nAdding the current animals to inventory!\n\n";
    FinInfo object = FinInfo(0.00, 0.00, 0.00);

	Pet animal1("Dog", "Dolly", 8, object);
	list.appendNode(animal1);
	
	Pet animal2("Cat", "Lucy", 4, object);
	list.appendNode(animal2);
	
	Pet animal3("Rabbit", "Bob", 2, object);
	list.appendNode(animal3);
	
	Pet animal4("Dragon", "Elliot", 643, object);
	list.appendNode(animal4);
	
	Pet animal5("Deer", "Bambi", 10, object);
	list.appendNode(animal5);
    

    do
    {
        cout << "\n\nWelcome to our Veterinary Office! What would you like to do today?" << endl;
        cout << "1. View the Pets in the Kennel" << endl;
        cout << "2. Add a Pet to the Kennel" << endl;
        cout << "3. Update Pet Info" << endl;
        cout << "4. Add a procedure" << endl;
        cout << "5. Leave the Clinc" << endl;
        cin >> menuChoice;

        while (menuChoice < 1 || menuChoice > 4 || cin.fail())
        {
            if (cin.fail())
            {

                cout << "\nOops! please enter a number" << endl;
                cin.clear();
                cin.ignore();
                cout << "\nOops! you entered an invalid choice! Please enter 1, 2, or 3!" << endl;
                cout << "\nWelcome to our Veterinary Office! What would you like to do today?" << endl;
                cout << "1. View the Pets in the Kennel" << endl;
                cout << "2. Add a Pet to the Kennel" << endl;
                cout << "3. Update Pet Info" << endl;
                cout << "4. Add a procedure" << endl;
                cout << "5. Leave the Clinc" << endl;
                cin >> menuChoice;
            }
            else
            {
                cout << "\nOops! you entered an invalid choice! Please enter 1, 2, or 3!" << endl;
                cout << "\nWelcome to our Veterinary Office! What would you like to do today?" << endl;
                cout << "1. View the Pets in the Kennel" << endl;
                cout << "2. Add a Pet to the Kennel" << endl;
                cout << "3. Update Pet Info" << endl;
                cout << "4. Add a procedure" << endl;
                cout << "5. Leave the Clinc" << endl;
                cin >> menuChoice;
            }
        }
        switch (menuChoice)
        {
        case 1:
        	cout << "\n\nNow printing out the pets in the kennel:\n\n";
	        list.displayList();

            break;

            
        case 2:
            list.addPet(&list);
            cout << "Thank you for adding your new pet." << endl << endl;
            cout << "Here is the new list of pets in our kennel:" <<endl;
            list.displayList();
        case 3:


        case 4:

        case 5:
            cout << "\n\nHave a great day and thank you for coming.";
        }
            
    } while (menuChoice != 5);

};
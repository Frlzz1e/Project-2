/************************************************************
	Filename:      Driver.cpp
	Author:        Bernie Friesel and Nathan Lopp
	Date Created:  10/24/2024
	Purpose:       The driver for our program 2
*************************************************************/
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
    int position;
    int menuChoice, sortChoice;
    int randomDescription = (rand() % 3) + 1;

//ADD SOME animals
	cout << "\n\nLoading pets into linked list...";
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
        cout << "4. Remove a pet" << endl;
        cout << "5. Pay balance" << endl;
        cout << "6. Leave the Clinc" << endl;
        cin >> menuChoice;

        while (menuChoice < 1 || menuChoice > 6 || cin.fail())
        {
            if (cin.fail())
            {

                cout << "\nOops! please enter a number." << endl;
                cin.clear();
                cin.ignore();
                cout << "\n\nWelcome to our Veterinary Office! What would you like to do today?" << endl;
                cout << "1. View the Pets in the Kennel" << endl;
                cout << "2. Add a Pet to the Kennel" << endl;
                cout << "3. Update Pet Info" << endl;
                cout << "4. Remove a pet" << endl;
                cout << "5. Pay balance" << endl;
                cout << "6. Leave the Clinc" << endl;
                cin >> menuChoice;
            }
            else
            {
                cout << "\nOops! Please enter a number in the range 1-6.\n";
                cout << "\n\nWelcome to our Veterinary Office! What would you like to do today?" << endl;
                cout << "1. View the Pets in the Kennel" << endl;
                cout << "2. Add a Pet to the Kennel" << endl;
                cout << "3. Update Pet Info" << endl;
                cout << "4. Remove a pet" << endl;
                cout << "5. Pay balance" << endl;
                cout << "6. Leave the Clinc" << endl;
                cin >> menuChoice;
            }
        }
        switch (menuChoice)
        {
        case 1:
        	cout << "\n\nHow would you like to view the list?" << endl;
            cout << "1. Unsorted" << endl;
            cout << "2. Sorted by ascending age" << endl;
            cout << "3. Sorted by descending age" << endl;
            cin >> sortChoice;
            while (sortChoice < 1 || sortChoice > 3 || cin.fail())
            {
                if (cin.fail())
                {
                    cout << "\nOops! please enter a number" << endl;
                    cin.clear();
                    cin.ignore();
                    cout << "\n\nHow would you like to view the list?" << endl;
                    cout << "1. Unsorted" << endl;
                    cout << "2. Sorted by ascending age" << endl;
                    cout << "3. Sorted by descending age" << endl;
                    cin >> sortChoice;
                }
                else
                {
                    cout << "\nOops! you entered an invalid choice! Please enter 1, 2, or 3!" << endl;
                    cout << "\n\nHow would you like to view the list?" << endl;
                    cout << "1. Unsorted" << endl;
                    cout << "2. Sorted by ascending age" << endl;
                    cout << "3. Sorted by descending age" << endl;
                    cin >> sortChoice;
                }
            }
            switch (sortChoice)
            {
                case 1:
                    cout << "\n\nNow printing out the pets in the kennel:\n\n";
                    list.displayList();
                    break;
                case 2:
                    cout << "\n\nNow sorting the pets by ascending age, Here they are!" << endl;
                    list.sortAscend();
                    list.displayList();
                    break;
                case 3:
                    cout << "\n\nNow sorting the pets by Descending age, Here they are!" << endl;
                    list.sortDescend();
                    list.displayList();
                    break;
            }
            break;
        case 2:
            list.addPet(&list);
            cout << "Thank you for adding your new pet." << endl << endl;
            cout << "Here is the new list of pets in our kennel:" <<endl;
            list.displayList();

            break;
        case 3:


            cout << "\n\nWhich pet would you like to update?\n\n";
            list.displayList();
            cin >> position;
            list.editNode(position);
            break;


        case 4:
            cout << "\n\nWhich pet would you like to delete?\n\n";
            list.displayList();
            cout << endl;
            cin >> position;

            list.deleteNode(position);

            break;

        case 5:
        cout << "\n\nWhich pet would you like to pay towards?\n\n";
        list.displayList();
        cout << endl;
        cin >> position;

        list.payBalance(position);

        break;
        
        case 6:
             cout << "\n\nHave a great day and thank you for coming.";

             return 0;
        }
            
    } while (menuChoice != 5);

};
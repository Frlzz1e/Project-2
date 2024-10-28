/*****************************************************************
	Filename:       LinkedList.h - Class Specification File for 
				    LinkedList Template Class
	Date Created:   October 22, 2024
	Author:         Bernie Friesel
	Purpose:        LAB 5 - A Singly-Linked List implemented in a
				    LinkedList template class that contains a ListNode
				    structure variable
******************************************************************/

#ifndef LinkedList_H
#define LinkedList_H

#include "animal.h"
#include <iostream>
using namespace std;


template <typename T>
class LinkedList
{
	private:
		struct ListNode
		{
			//STRUCTURE MEMBERS NEED TO BE ADDED HERE
			T val;
			ListNode *next;

            ListNode(T NV){
                this->val = NV;
                this->next = NULL;
            }
		}; 

		ListNode *head;	
		ListNode *tail;		

	public:
		LinkedList()
		{ 
			head = NULL; 
			tail = NULL;
		}
		~LinkedList();
		void appendNode(T value);
		void deleteNode(int position);
		void displayList() const;
        void addPet(LinkedList<Pet>* list);
        void procedure(T value);
};

//DEFINE ALL OTHER LinkedList class FUNCTIONS BELOW THIS LINE--------------------------------
template <typename T>
void LinkedList<T>::appendNode(T value)
{
	ListNode *newNode;

	newNode = new ListNode(value);
	newNode->val = value;
	newNode->next = NULL;

	// If there are no nodes in the list make newNode the first node.
	if (!head ) 
	{
		head = newNode;
		tail = newNode;
	}
	else  // Otherwise, insert newNode at end.
	{
		
		tail->next = newNode;
		tail = newNode;
	}
}

template <typename T>
void LinkedList<T>::deleteNode(int num)
{
	ListNode *temp;
	ListNode *current;
	int i = 0;

	if(head == nullptr || num < 0){
		cout << "invalid position" << endl;
		return;
	}

	if(num == 0) {
		temp = head;
		head = head->next;
		delete temp;
		return;
	}

	current = head;
	while(i<num){
		current = current->next;
		i++;
	}

	if(current->next == nullptr){
		cout << "Position out of range." << endl;
		return;
	}

	temp = current->next;
	current->next = temp->next;
	delete temp;

}
template <typename T>
void LinkedList<T>::displayList() const
{
	ListNode *nodePtr;

	if(head != NULL)
	{
		// Position nodePtr at the head of the list.
		nodePtr = head;

		while (nodePtr)
		{
			cout << nodePtr->val << endl;
			nodePtr = nodePtr->next;
		}
	}
	else
		cout << "\nThere are no nodes in the list.\n\n";
};

template <typename T>
LinkedList<T>::~LinkedList()
{
	ListNode *nodePtr;   // To traverse the list
	ListNode *nextNode;  // To point to the next node

	// Position nodePtr at the head of the list.
	nodePtr = head;

	// While nodePtr is not at the end of the list...
	while (nodePtr != NULL)
	{
		// Save a pointer to the next node.
		nextNode = nodePtr->next;

		// Delete the current node.
		delete nodePtr;

		// Position nodePtr at the next node.
		nodePtr = nextNode;
	}
};

template <typename T>
void LinkedList<T>::addPet(LinkedList<Pet>* list)
{ 
string tempType;
string tempName;
int tempAge;

cout << "Enter information about the new animal"<<endl;
cout << "\tType: ";
cin >> tempType;
cout << "\n\tName: ";
cin >> tempName;
cout << "\n\tAge: ";
cin >> tempAge;

FinInfo NewObject = FinInfo(0.00, 0.00, 0.00);
Pet newPet(tempType, tempName, tempAge, NewObject);
list->appendNode(newPet);

};

template <typename T>
void LinkedList<T>::procedure(T value)
{

};

#endif
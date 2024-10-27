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

#include <iostream>
#include "ListNode.h"
#include "animal.h"
using namespace std;


template <typename T>
class LinkedList
{
	private:
		ListNode<T>* head;  // Pointer to the head of the list
    	ListNode<T>* tail;  // Pointer to the tail of the list	

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
};

//DEFINE ALL OTHER LinkedList class FUNCTIONS BELOW THIS LINE--------------------------------
template <typename T>
void LinkedList<T>::appendNode(T value)
{
	// Create a new node
    ListNode<T>* newNode = new ListNode<T>(value);

    // If there are no nodes in the list, set newNode as the head and tail
    if (!head) 
	{
        head = newNode;
        tail = newNode;
    }
	else 
	{
        // Otherwise, link the newNode to the end of the list
        tail->setNextPtr(newNode);
        tail = newNode;
    }
}

template <typename T>
void LinkedList<T>::deleteNode(int num)
{
	if (head == nullptr || num < 0) 
	{
        cout << "Invalid position" << endl;
        return;
    }

    ListNode<T>* temp;
    ListNode<T>* current = head;

    if (num == 0) 
	{  // Delete the head node
        temp = head;
        head = head->getNextPtr();
        delete temp;
        if (head == nullptr)
		{  // Update tail if list is now empty
            tail = nullptr;
        }
        return;
    }

    // Traverse to the node just before the specified position
    for (int i = 0; i < num - 1 && current->getNextPtr() != nullptr; ++i)
	{
        current = current->getNextPtr();
    }

    if (current->getNextPtr() == nullptr) 
	{
        cout << "Position out of range." << endl;
        return;
    }

    // Delete the node at the specified position
    temp = current->getNextPtr();
    current->setNextPtr(temp->getNextPtr());
    if (temp == tail) 
	{  // Update tail if the last node was deleted
        tail = current;
    }
    delete temp;
}

template <typename T>
void LinkedList<T>::displayList() const
{
	ListNode<T>* nodePtr = head;

    if (head == nullptr)
	{
        cout << "\nThere are no nodes in the list.\n";
        return;
    }

    while (nodePtr != nullptr) 
	{
        cout << nodePtr->getData();
        nodePtr = nodePtr->getNextPtr();
    }
    cout << endl;
};

template <typename T>
LinkedList<T>::~LinkedList()
{
	ListNode<T>* nodePtr = head;

    while (nodePtr != nullptr) 
	{
        ListNode<T>* nextNode = nodePtr->getNextPtr();
        delete nodePtr;
        nodePtr = nextNode;
    }
};

#endif
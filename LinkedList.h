/*****************************************************************
	Filename:       LinkedList.h - Class Specification File for 
				    LinkedList Template Class
	Date Created:   10/24/2024
	Author:         Bernie Friesel and Nathan 
	Purpose:        A Singly-Linked List implemented in a
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
        ListNode* mergeSort(ListNode* node, bool ascending);
        ListNode* getMiddle(ListNode* node);
        ListNode* merge(ListNode* left, ListNode* right, bool ascending);
        void updateTail();	

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
        void sortAscend();
        void sortDescend();
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
	ListNode *nodePtr;       // To traverse the list
	ListNode *previousNode;  // To point to the previous node
    int i = 0;
	// If the list is empty, do nothing.
	if (!head)
		return;

	// Determine if the first node is the one.
	if (num == 1)
	{
		nodePtr = head->next;
		delete head;
		head = nodePtr;
	}
	else
	{
		// Initialize nodePtr to head of list
		nodePtr = head;

		// Skip all nodes whose value member is 
		// not equal to num.
		while (nodePtr != NULL && i != num-1)
		{  
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
            i++;
		}

		// If nodePtr is not at the end of the list, 
		// link the previous node to the node after
		// nodePtr, then delete nodePtr.
		if (nodePtr)
		{
			if(nodePtr == tail)
			{
				tail = previousNode;
			}
			previousNode->next = nodePtr->next;
			delete nodePtr;
		}
	}
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
}

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
}

template <typename T>
void LinkedList<T>::addPet(LinkedList<Pet>* list)
{ 
string tempType;
string tempName;
int tempAge;
double tempBal;
double tempPaid;
double temptip;

cout << "Enter information about the new animal"<<endl;
cout << "\tType: ";
cin >> tempType;
cout << "\n\tName: ";
cin >> tempName;
cout << "\n\tAge: ";
cin >> tempAge;
cout << "\n\tCurrent Balance: ";
cin>> tempBal;
cout << "\n\tAmount already Paid: ";
cin >> tempPaid;
cout << "\n\tTip: ";
cin >> temptip;

FinInfo NewObject = FinInfo(tempBal, tempPaid, temptip);
Pet newPet(tempType, tempName, tempAge, NewObject);
list->appendNode(newPet);

}

template <typename T>
void LinkedList<T>::sortAscend() {
    head = mergeSort(head, true);  // Sort in ascending order
    updateTail();
}

template <typename T>
void LinkedList<T>::sortDescend() {
    head = mergeSort(head, false);  // Sort in descending order
    updateTail();
}

template <typename T>
typename LinkedList<T>::ListNode* LinkedList<T>::mergeSort(ListNode* startNode, bool ascending) {
    if (!startNode || !startNode->next)
	{
        return startNode;
	}

    ListNode* midNode = startNode;
    ListNode* endNode = startNode->next;

    while (endNode && endNode->next) 
	{
        midNode = midNode->next;
        endNode = endNode->next->next;
    }

    ListNode* rightHalfStart = midNode->next;
    midNode->next = nullptr;

    ListNode* leftSorted = mergeSort(startNode, ascending);
    ListNode* rightSorted = mergeSort(rightHalfStart, ascending);

    return merge(leftSorted, rightSorted, ascending);
}

template <typename T>
typename LinkedList<T>::ListNode* LinkedList<T>::merge(ListNode* leftNode, ListNode* rightNode, bool ascending) {
    ListNode tempHead(0);
    ListNode* mergedTail = &tempHead;

    while (leftNode && rightNode) {
        if ((ascending && leftNode->val.age <= rightNode->val.age) ||
            (!ascending && leftNode->val.age > rightNode->val.age)) 
		{
            mergedTail->next = leftNode;
            leftNode = leftNode->next;
        } 
		else 
		{
            mergedTail->next = rightNode;
            rightNode = rightNode->next;
        }
        mergedTail = mergedTail->next;
    }

    if (leftNode) 
	{
    	mergedTail->next = leftNode;
	} 
	else 
	{
		mergedTail->next = rightNode;
	}
    return tempHead.next;
}

template <typename T>
void LinkedList<T>::updateTail() 
{
    if (!head) 
	{
        tail = nullptr;
        return;
    }

    ListNode* currentNode = head;
    while (currentNode->next)
	{
        currentNode = currentNode->next;
	}
    tail = currentNode;
}

#endif
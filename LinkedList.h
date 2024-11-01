<<<<<<< Updated upstream
=======
/*****************************************************************
	Filename:       LinkedList.h - Class Specification File for 
				    LinkedList Template Class
	Date Created:   10/24/2024
	Author:         Bernie Friesel
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
class ListNode 
{
    private:
        T data;    // Stores data of template type T
        ListNode<T>* next;  // Pointer to the next node in the list
    public:
        // Constructor to initialize the node 
        ListNode(T value, ListNode<T>* nextNode = nullptr) 
        {
            data = value;
            next = nextNode;
        }
        // Getter for data
        T getData()
        {
            return data;
        }
        // Setter for data
        void setData(T value) 
        {
            data = value;
        }
        // Getter for the next pointer
        ListNode* getNextPtr()
        {
            return next;
        }
        // Setter for the next pointer
        void setNextPtr(ListNode* nextNode) 
        {
            next = nextNode;
        }
        // Destructor (does not delete attached nodes to allow manual cleanup)
        ~ListNode() {}
};
template <typename T>
class LinkedList
{
	private:
		ListNode<T>* head;	
		ListNode<T>* tail;	
		ListNode<T>* mergeSort(ListNode<T>* node, bool ascending);
        ListNode<T>* getMiddle(ListNode<T>* node);
        ListNode<T>* merge(ListNode<T>* left, ListNode<T>* right, bool ascending);
        void updateTail();	
	public:
		LinkedList()
		{ 
			head = nullptr; 
			tail = nullptr;
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
	ListNode<T>* newNode = new ListNode<T>(value);

	// If there are no nodes in the list make newNode the first node.
	if (!head ) 
	{
		head = newNode;
		tail = newNode;
	}
	else  // Otherwise, insert newNode at end.
	{
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
    {
        temp = head;
        head = head->getNextPtr();
        delete temp;
        return;
    }

    int i = 0;
    while (current && i < num-1) 
    {
        current = current->getNextPtr();
        i++;
    }

    if (!current || !current->getNextPtr()) 
    {
        cout << "Position out of range." << endl;
        return;
    }

    temp = current->getNextPtr();
    current->setNextPtr(temp->getNextPtr());
    delete temp;

    if (!current->getNextPtr())
	{
    	tail = current;
	}
}

template <typename T>
void LinkedList<T>::displayList() const
{
	if (!head) 
    {
        cout << "\nThere are no nodes in the list.\n\n";
        return;
    }
    ListNode<T>* nodePtr = head;
    while (nodePtr) 
    {
        cout << nodePtr->getData() << endl;
        nodePtr = nodePtr->getNextPtr();
    }
}

template <typename T>
LinkedList<T>::~LinkedList()
{
	ListNode<T>* nodePtr = head;
    while (nodePtr) 
    {
        ListNode<T>* nextNode = nodePtr->getNextPtr();
        delete nodePtr;
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
void LinkedList<T>::sortAscend() 
{
    head = mergeSort(head, true);  // Sort in ascending order
    updateTail();
}

template <typename T>
void LinkedList<T>::sortDescend() 
{
    head = mergeSort(head, false);  // Sort in descending order
    updateTail();
}

template <typename T>
ListNode<T>* LinkedList<T>::mergeSort(ListNode<T>* node, bool ascending) 
{
    if (!node || !node->getNextPtr()) 
	{
        return node;  // Base case: return if list is empty or has one node
    }
    
    // Split list into halves
    ListNode<T>* mid = getMiddle(node);
    ListNode<T>* rightHalf = mid->getNextPtr();
    mid->setNextPtr(nullptr);  // Split the list
    
    // Recursive sort on each half
    ListNode<T>* leftSorted = mergeSort(node, ascending);
    ListNode<T>* rightSorted = mergeSort(rightHalf, ascending);
    
    // Merge sorted halves
    return merge(leftSorted, rightSorted, ascending);
}

template <typename T>
ListNode<T>* LinkedList<T>::getMiddle(ListNode<T>* node) 
{
    ListNode<T>* leftWalker = node;
    ListNode<T>* rightWalker = node->getNextPtr();
    
    while (rightWalker && rightWalker->getNextPtr())
	{
        leftWalker = leftWalker->getNextPtr();
        rightWalker = rightWalker->getNextPtr()->getNextPtr();
    }
    return leftWalker;
}

template <typename T>
ListNode<T>* LinkedList<T>::merge(ListNode<T>* left, ListNode<T>* right, bool ascending)
 {
    ListNode<T>* tempHead;  // Temporary node to simplify the merging process
    ListNode<T>* mergeTail = &tempHead;
    
    while (left && right) 
	{
        // Compare nodes based on ascending or descending order
        if ((ascending && left->getData().age <= right->getData().age) ||
            (!ascending && left->getData().age > right->getData().age))
		{
            mergeTail->setNextPtr(left);
            left = left->getNextPtr();
        }
		else 
		{
            mergeTail->setNextPtr(right);
            right = right->getNextPtr();
        }
        mergeTail = mergeTail->getNextPtr();
    }
    
    // Attach remaining nodes
    if (left) 
	{
        mergeTail->setNextPtr(left);
    } 
	else 
	{
        mergeTail->setNextPtr(right);
    }
    
    return tempHead.getNextPtr();  // Head of the merged list
}

template <typename T>
void LinkedList<T>::updateTail()
{
    if (!head) 
	{
        tail = nullptr;
        return;
    }
    
    ListNode<T>* node = head;
    while (node->getNextPtr()) 
	{
        node = node->getNextPtr();
    }
    tail = node;
}

#endif
>>>>>>> Stashed changes

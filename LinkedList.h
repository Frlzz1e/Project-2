/*****************************************************************
	Filename:       LinkedList.h - Class Specification File for 
				    LinkedList Template Class
	Date Created:   10/24/2024
	Author:         Bernie Friesel and Nathan Lopp
	Purpose:        A Singly-Linked List implemented in a
				    LinkedList template class that contains a ListNode
				    structure variable
******************************************************************/

#ifndef LinkedList_H
#define LinkedList_H

#include "animal.h" 
#include <iostream>
using namespace std;

/*********************************************************** 
Title: ListNode
Purpose: List Node struct that assists the LinkedList class
***********************************************************/
template <typename T>
struct ListNode 
{
    T val;   //Value stored in the node
    ListNode* next;  //Pointer to the next node in the list

	//Constructor to initialize a node with a given value and set next to nullptr
    ListNode(T NV)
	{
    	val = NV;
    	next = nullptr;
	}

	// Getter function to retrieve the data stored in the node
	T getData() {return val;}

	// Setter function to update the node's value using data from another ListNode
	void setval(ListNode<T> object){val = object.getData();}
};

/*********************************************************** 
Title: LinkedList
Purpose: To create a linked list that stores data of Pets
***********************************************************/
template <typename T>
class LinkedList
{
	private:
		ListNode<T>* head;	//Points to List's first node
		ListNode<T>* tail;	//Points to List's last node
        ListNode<T>* mergeSort(ListNode<T>* startNode, bool ascending); //private function prototypes
        ListNode<T>* merge(ListNode<T>* leftNode, ListNode<T>* rightNode, bool ascending);
        void updateTail();	

	public:
		LinkedList()
		{ 
			head = NULL; 
			tail = NULL;
		}

		~LinkedList();     //public function prototypes
		void appendNode(T value);
		void deleteNode(int position);
		void displayList() const;
        void addPet(LinkedList<Pet>* list);
        void sortAscend();
        void sortDescend();
		void editNode(int position);
		void payBalance(int position);
};

/*********************************************************** 
Title: AppendNode
Purpose: Adds aa node with a value.
***********************************************************/
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
		
		tail->next = newNode;
		tail = newNode;
	}
}

/*********************************************************** 
Title: DeleteNode
Purpose: Deletes a node specified by the user. 
***********************************************************/
template <typename T>
void LinkedList<T>::deleteNode(int num)
{
	ListNode<T>* nodePtr;       // To traverse the list
	ListNode<T>* previousNode;  // To point to the previous node
    int i = 0;

	if (num < 1 || !head) //Ensure num is positive and list is not empty
	{
		cout << "Invalid Choice.\n";
		return;
	}

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
		else
        {
            cout << "Position exceeds list length.\n";
        }
	}
}

/*********************************************************** 
Title: DisplayList
Purpose: Displays the Contents of the List to the User.
***********************************************************/
template <typename T>
void LinkedList<T>::displayList() const
{
	ListNode<T>* nodePtr;

	if (!head)
    {
        cout << "The list is empty.\n";
        return;
    }
	else
	{
		// Position nodePtr at the head of the list.
		nodePtr = head;

		while (nodePtr)
		{
			cout << nodePtr->val << endl;
			nodePtr = nodePtr->next;
		}
	}
}

/*********************************************************** 
Title: ~LinkedList
Purpose: Frees and Deletes Nodes to prevent memory Leaks.
***********************************************************/
template <typename T>
LinkedList<T>::~LinkedList()
{
	ListNode<T>* nodePtr;   //To traverse the list
	ListNode<T>* nextNode;  //To point to the next node

	//Position nodePtr at the head of the list.
	nodePtr = head;

	//While nodePtr is not at the end of the list...
	while (nodePtr != NULL)
	{
		//Save a pointer to the next node.
		nextNode = nodePtr->next;

		//Delete the current node.
		delete nodePtr;

		//Position nodePtr at the next node.
		nodePtr = nextNode;
	}
}

/************************************************************
Title: AddPet
Purpose: Allowys a user to add a new Pet with its Financial 
info to the linked list
************************************************************/
template <typename T>
void LinkedList<T>::addPet(LinkedList<Pet>* list)
{ 
	string tempType; //Temporary vaules
	string tempName;
	int tempAge;
	double tempBal;
	double tempPaid;
	double temptip;

	//Gather information about the new pet from user input
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

	//Create a new FinInfo object with the input values
	FinInfo NewObject = FinInfo(tempBal, tempPaid, temptip);
	//Create a new Pet object with the input values
	Pet newPet(tempType, tempName, tempAge, NewObject);

	//Add the new Pet to the linked list
	list->appendNode(newPet);
}

/****************************************************************** 
Title: SortAscend
Purpose: Sorts the Linked List in Ascending order of the Pets' age.
******************************************************************/
template <typename T>
void LinkedList<T>::sortAscend() 
{
    head = mergeSort(head, true);  // Sort in ascending order
    updateTail();
}

/******************************************************************* 
Title: SortDescend
Purpose: Sorts the Linked List in Descending order of the Pets' age.
*******************************************************************/
template <typename T>
void LinkedList<T>::sortDescend() {
    head = mergeSort(head, false);  // Sort in descending order
    updateTail();
}

/*********************************************************** 
Title: MergeSort
Purpose: Recursively sorts the list using merge sort, 
with an option to specify ascending or descending order.
***********************************************************/
template <typename T>
ListNode<T>* LinkedList<T>::mergeSort(ListNode<T>* startNode, bool ascending)
{
	//Base case: return node if it's the last node or if the list is empty
    if (!startNode || !startNode->next)
	{
        return startNode;
	}

	//Split the list into two halves
    ListNode<T>* midNode = startNode;
    ListNode<T>* endNode = startNode->next;

    while (endNode && endNode->next) 
	{
        midNode = midNode->next;
        endNode = endNode->next->next;
    }

	//Divide the list at the midpoint
    ListNode<T>* rightHalfStart = midNode->next;
    midNode->next = nullptr;

	//Recursively sort both halves
    ListNode<T>* leftSorted = mergeSort(startNode, ascending);
    ListNode<T>* rightSorted = mergeSort(rightHalfStart, ascending);

	//Merge the sorted halves and return the merged list
    return merge(leftSorted, rightSorted, ascending);
}

/*********************************************************** 
Title: Merge
Purpose: Merges the two halves of the linked list based on 
which sorting order was chosen.
***********************************************************/
template <typename T>
ListNode<T>* LinkedList<T>::merge(ListNode<T>* leftNode, ListNode<T>* rightNode, bool ascending) {
    Pet tempPet;  //Create a temporary Pet object
    ListNode<T> tempHead(tempPet);
    ListNode<T>* mergedTail = &tempHead;

	//Merge the nodes in ascending or descending order based on the ascending boolean
    while (leftNode && rightNode) {
        if ((ascending && leftNode->val.getAge() <= rightNode->val.getAge()) ||
            (!ascending && leftNode->val.getAge() > rightNode->val.getAge())) 
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

	//Attach any remaining nodes from the left or right sublist
    if (leftNode) 
	{
    	mergedTail->next = leftNode;
	} 
	else 
	{
		mergedTail->next = rightNode;
	}
	//Return the head of the merged list
    return tempHead.next;
}

/*********************************************************** 
Title: UpdateTail
Purpose: Updates the tail pointer to point to the last node 
in the list.
***********************************************************/
template <typename T>
void LinkedList<T>::updateTail() 
{
    if (!head) //If list is empty, set tail to nullptr
	{
        tail = nullptr;
        return;
    }

	//Traverse the list to find the last node
    ListNode<T>* currentNode = head;
    while (currentNode->next)
	{
        currentNode = currentNode->next;
	}
	// Set tail to the last node
    tail = currentNode;
}

/*********************************************************** 
Title: EditNode
Purpose: Alowys the user to edit a Pet's information within
the Linked List.
***********************************************************/
template <typename T>
void LinkedList<T>::editNode(int num)
{
	if (num < 1 || !head) //Ensure num is positive and list is not empty
	{
		cout << "Invalid Choice.\n";
		return;
	}

	FinInfo object;
	Pet temp;			//Temporary Values
	string tempType;
	string tempName;
	int tempAge;
	double tempBal;
	double tempPaid;
	double temptip;
	ListNode<T>* nodePtr;       // To traverse the list
	ListNode<T>* previousNode;  // To point to the previous node
    int i = 0;

	//Traverse to the node at position num
    for (int i = 1; i < num && nodePtr; i++) 
	{
        previousNode = nodePtr;
        nodePtr = nodePtr->next;
    }

    // Check if the node to edit exists
    if (!nodePtr) 
	{
        cout << "Node at position " << num << " does not exist.\n";
        return;
    }

	// Determine if the first node is the one.
	if (num == 1)
	{

		nodePtr = head->next;
		head = nodePtr;

		cout << "Enter  the updated information about the animal."<<endl;
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

		temp = nodePtr->getData();
		temp.setType(tempType);
		temp.setName(tempName);
		temp.setAge(tempAge);

		object = temp.getObject();
		object.setbalance(tempBal);
		object.setpaid(tempPaid);
		object.settip(temptip);
		temp.setFin(object);

		// Delete the old node and append the new one
    	if (previousNode) 
		{
			previousNode->next = nodePtr->next;
		}
    	else 
		{
			head = nodePtr->next;
		}
    	if (nodePtr == tail) 
		{
			tail = previousNode;
		}

		delete nodePtr; // Free memory before appending
		appendNode(temp);


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
			
			cout << "Enter  the updated information about the animal."<<endl;
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

			temp = nodePtr->getData();
			temp.setType(tempType);
			temp.setName(tempName);
			temp.setAge(tempAge);

			object = temp.getObject();
			object.setbalance(tempBal);
			object.setpaid(tempPaid);
			object.settip(temptip);

			temp.setFin(object);

			appendNode(temp);

		}
	}
}

#endif
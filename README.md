# Project-2
Bernie Friesel
Nathaniel Lopp
README.md

For our project 2 we will re-use our idea from project-1, a vet office. Our linked list class will be a list of all the animals in our clinic. The private data will contain the pets information (Type, Name, Age, Balance). We will be able to add a pet, get a pet inoformation, and check out a pet. We will have a function that sorts the pets by age. Our new class will be operations. The operations will be able to change the balance assigned to each pet. We will use a smart pointer to track the number of operations that have been done on an animal. It will caompare to see how many has been done and if it can get another operation. 

class Pet{          //This is the data class
    public:
        Pet(){              //Default Constructor
            type = "Dog";
            name = "Doggy";
            age = 3;
            price = 5.99;
        }
    private:
        string type;
        string name;
        int age;
        double price;

};

class PetStorage{           //This is the storage class
    public:
        string parsingMethod();     //Used to parse the text file being read in
        Pet** petArrayPtr[];
};

class PetDescription{
    void description(string name){          //helper class that will return one of three descriptions at random

    };
};

// class Procedure {            
//     public:                  
//         string name;        
//         string procedure;   
// };


// Linked list operations
void appendNode(string newName)
{
	ListNode *newNode;

	newNode = new ListNode;
	newNode->name = newName;
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

void insertNode(int position, string newName)
{
	ListNode *nodePtr;
	ListNode *newNode;
	
	newNode = new ListNode;
	newNode->name = newName;
	
	if(!head)
	{
		if(position != 0)
		{
			cout << "\n\nUnable to insert a node at position " << position << " because there are currently no nodes in the list.  I am going to insert this node at position 1.\n\n";
		}
		head = newNode;
		tail = newNode;
	}
	else
	{
		nodePtr = head;
		int nodeCount = 0;
		if(position == 0)
		{
			newNode->next = head;
			head = newNode;
		}
		else
		{
			while(nodePtr != tail && nodeCount < position)
			{
				nodeCount++;
				if(nodeCount == position)
					break;
				nodePtr = nodePtr->next;
			}
			
			if(nodePtr->next == NULL)
				tail = newNode;
				
			newNode->next = nodePtr->next;
			nodePtr->next = newNode;
		}
	}	
}

void deleteNode(string newName)
{
	ListNode *nodePtr;     
	ListNode *previousNode;  

	// If the list is empty, do nothing.
	if (!head)
		return;

	// Determine if the first node is the one.
	if (head->name == newName)
	{
		nodePtr = head->next;
		delete head;
		head = nodePtr;
	}
	else
	{
		nodePtr = head;

		// Skip all nodes whose value member is not equal to num.
		while (nodePtr != NULL && nodePtr->name != newName)
		{  
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		// If nodePtr is not at the end of the list
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

void displayList() const
{
	ListNode *nodePtr;

	if(head != NULL)
	{
		// Position nodePtr at the head of the list.
		nodePtr = head;

		while (nodePtr)
		{
			cout << nodePtr->name << endl;
			nodePtr = nodePtr->next;
		}
	}
	else
		cout << "\nThere are no nodes in the list.\n\n";
}

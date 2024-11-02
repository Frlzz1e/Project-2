# Project-2
Bernie Friesel
Nathaniel Lopp
README.md

For our project 2 we re-used our idea from project-1, a vet office. Our data class will be all the animals in our clinic adn our linked list node will hold the information of the Pet class and financial Information class. The private data will contain the pets information (Type, Name, Age) and our second class will be financial Information. The user's forst option is to see all the aniamls in the clinic. The user can also choose if they want the list sorted or unsorted and how to sort the list. There is a function that sorts the animals by age, least to greatest or greatest to least. We have a listnode structure outside our linkedlist class. The other options for the user is to add, delete, and update a pet. The user also has a option to end the program when they are all done. Everyhting works as planned and is fully operational. The only thing we couldn't get to work is the makefile. Nathan and I split the work and worked on sperate thing until the last week where we brought everything together and debugged. 

Our process was pretty straight forward and thankfully worked well. Nathan tackled doing the sorting function and getting the linked list class and structure to work together outside of one another. He also did a lot of the comments. I did the driver and set up majority of the classes. We worked super well together and were both understanding of our busy schedules. We ended up coming together at the third week and making sure everyhting worked together. There was a few merging error, but we ended up getting it all to work together. 

If we had to do anything differently it would probably be not commmiting to main. We didn't make seperate branched until we messed up the main pretty badly. We made a seperate branch and then eventually got it back into the main.

The outcome of our program should be a fully operational vet menu. The user should be able to select animals and update them, add a new pet, delete a pet, and view every pet in the system. 



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

class FinInfo
{
	private:
		double currentBal; //Outstanding balance for the pet
		double Paid; //Amount paid to the Balance
		double tips; //Any Tips given

	public:
		// Default constructor initializing balance, paid amount, and tips to 0.
		FinInfo()
		{
			currentBal = 0.00;
			Paid = 0.00;
			tips = 0.00;
		}

		// Overloaded constructor initializing with specific balance, paid, and tip values
		FinInfo(double balance, double paid, double tip)
		{
			currentBal = balance;
			Paid = paid;
			tips = tip;
		}

		//Setters for currentBal, paid, and tips
		void setbalance(double givenbalance);
		void setpaid(double givenpaid);
		void settip(double giventip);

		//Getters for cuurentBal, paid , amd tips
		double getbalance();
		double getpaid();
		double gettip();
};

/*********************************************************** 
Title: Pet
Purpose: Class that stores information about Pets entered
 into the Veterinary office.
***********************************************************/
class Pet
{
	private:
		string type; //Animal type
		string name; // Pet's name
		int age; //Age of Pet
		FinInfo FinacialObject; //Financial info of the Pet
		
	public:
		//Default constructor initializing an empty Pet object
		Pet(){};
		//Overloaded constructor initializing with type, name, age, and financial imfo
	    Pet(string t, string n, int a, FinInfo f)
		{
			this->type = t;
			this->name = n;
			this->age = a;
			this->FinacialObject = f;
		}

		//Setters for Pet type, name, age , and financial info
		void setFin(FinInfo givenFin);
		void setType(string givenType);
		void setName(string givenName);
		void setAge(int givenAge);

		//Getter for financial info
		FinInfo getObject();

		//Getter for age (Used in sorting)
		int getAge() 
		{ 
			return age; 
		}

	
		//OVERLOADED << OPERATOR to display the pet with cout <<
		friend ostream & operator << (ostream & os, Pet p)
		{
			os << "\nAnimal Type: \t" << p.type;
			os << "\nAnimal Name: \t" << p.name;
			os << "\nAnimal Age: \t" << p.age;
			os << "\nCurrent Balance: \t" << p.FinacialObject.getbalance();
			os << "\nPaid towards Balance: \t" << p.FinacialObject.getpaid();
			os << "\nTips: \t" << p.FinacialObject.gettip();
			return os;
		}
};

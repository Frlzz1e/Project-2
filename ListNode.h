#ifndef LISTNODE_H
#define LISTNODE_H

template <typename T>
class ListNode 
{
    private:
        T data;                // Stores data of template type T
        ListNode<T>* next;        // Pointer to the next node in the list

    public:
        // Constructor to initialize the node 
        ListNode(T value, ListNode* nextNode = nullptr) 
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
        void setData(T& value) 
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

#endif 
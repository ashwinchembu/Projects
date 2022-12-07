// Filename: linkedlist.h
// 
// Header file for the class LinkedList that represents a linked list
// 
// Japheth Frolick, August 2019
// C. Seshadhri, Jan 2020

#ifndef LIST_H
#define LIST_H

#include <string>

using namespace std;

// node struct to hold data
struct Node
{
	int data;
	Node *next;
};

class LinkedList
{
	private:
		Node *head; // Stores head of linked list
	public:
		LinkedList(); // Default constructor sets head to null
        void insert(int); // insert int into list 
        Node* find(int); // find int in list, and return pointer to node with that int. If there are multiple copies, this only finds one copy
        Node* deleteNode(int); // remove a node with int (if it exists), and return pointer to deleted node. This does not delete all nodes with the value.
		void deleteList(); // deletes every node to prevent memory leaks, and frees memory
		string print(); // Construct string with data of list in order 
		int length(); // Returns the length of the linked list

        // Advanced functions follow
        void reverse(int); // reverse every segment of int entries
		void rotate(int);
        void reverseRotate(int);
		void reverseLastK(int);
		bool checkPalindrome(Node*,Node*);
		bool checkPalindrome();
		void deleteK(int,int);
		void makePalindrome();
		void deleteLast(int); //deletes last value of val
		int countVals(int); //counts the occurences of val
		void deleteAllButFirst(int);
		
};

#endif

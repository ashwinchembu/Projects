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
  string data;
	int count;
	Node *next;
};

class LinkedList
{
	private:
		Node *head; // Stores head of linked list
		Node *sorted;
    Node *sorted2;
	public:
		LinkedList(); // Default constructor sets head to null
    void insert(string); // insert string into list 
		void insertionfreqSort(); //sort based on frequency
   void  insertionalphaSort();//sort alphabetically
		void sortedfreqInsert(Node*);//helper function
    void sortedalphaInsert(Node*);//helper function
    string findit(int);//iterate through the LL until the pointer goes to the right place
    Node* find(string); // find int in list, and return pointer to node with that int. If there are multiple copies, this only finds one copy
    Node* deleteNode(string); // remove a node with int (if it exists), and return pointer to deleted node. This does not delete all nodes with the value.
    void deleteAndFreeNode(string);
		void deleteList(); // deletes every node to prevent memory leaks, and frees memory
		string print(); // Construct string with data of list in order 
    void println();
		int length(); // Returns the length of the linked list
		
};

#endif

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


		
    Node* insertNew(string, Node*); // insert int into list 
		void insert(Node**, string);
		Node* findInsert(string,Node*,Node*); //check if value is in list and perform accordingly
    Node* find(Node*, string); // find int in list, and return pointer to node with that int. If there are multiple copies, this only finds one copy
    Node* deleteNode(string,Node*); // remove a node with int (if it exists), and return pointer to deleted node. This does not delete all nodes with the value.
    void deleteAndFreeNode(string,Node*); // remove a node with int (if it exists), and free the memory.
		void deleteList(Node*); // deletes every node to prevent memory leaks, and frees memory
		string print(Node*); // Construct string with data of list in order 
		int LLlength(Node*); // Returns the length of the linked list

#endif

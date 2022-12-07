#ifndef BST_H
#define BST_H

#include <string>
#include <stdio.h>
#include <string.h>

using namespace std;

// node struct to hold data
class Node
{
	public:
      string key;
	    Node *left, *right, *parent;

        Node() // default constructor
        {
            left = right = parent = NULL; // setting everything to NULL
        }

        Node(string val) // constructor that sets key to val
        {
            key = val;
            left = right = parent = NULL; // setting everything to NULL
        }
        int height;
        
};

class BST
{
	private:
		Node *root; // Stores root of tree
	public:
		BST(); // Default constructor sets root to null
        void insert(string); // insert int into list 
        void insert(Node*, Node*); // recursive version that inserts a node
        Node* find(string); // find int in tree, and return pointer to node with that int. If there are multiple copies, this only finds one copy
        Node* find(Node*, string); // recursive version that finds in a rooted subtree
        Node* minNode(Node*); // gets minimum node in rooted subtree
        Node* maxNode(Node*); // gets maximum node in rooted subtree
        Node* deleteKey(string); // remove a node with int (if it exists), and return pointer to deleted node. This does not delete all nodes with the value.
        Node* deleteNode(Node*); // try to delete node pointed by argument. This also returns the node, isolated from the tree.
		    void deleteBST(); // deletes every node to prevent memory leaks, and frees memory
        void deleteBST(Node* start); // deletes every Node in subtree rooted at startto prevent memory leaks.
		    string printInOrder(); // Construct string with tree printed InOrder
		    string printInOrder(Node* start); // Construct string with rooted subtree printed InOrder
		    string printPreOrder(); // Construct string with tree printed PreOrder
		  string printPreOrder(Node* start); // Construct string with rooted subtree printed PreOrder
		string printPostOrder(); // Construct string with tree printed PostOrder
		string printPostOrder(Node* start); // Construct string with rooted subtree printed PostOrder
    int range(string,string);
    int range(Node* start, string, string);
};

#endif
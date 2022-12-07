#ifndef BST_H
#define BST_H

#include <string>
#include <stdio.h>
#include <string.h>

using namespace std;

class Node
{
	public:
      string data;
	    Node *left, *right;

        Node() // default constructor
        {
            left = right = parent = NULL; // setting everything to NULL
        }

        Node(string val) // constructor that sets key to val
        {
            data = val;
            left = right = parent = NULL; // setting everything to NULL
        }
        int height;
        
};

class AVL
{
  private: 
    Node *root;
  public: 
    AVL();
    int calheight(Node*);
    int bf(Node*);
    Node* llrotation(Node*);
    Node* rrrotation(Node*);
    Node* rlrotation(Node*);
    Node* lrrotation(Node*);
    Node* insert(Node*, string);
    void levelorder_newline();
    void levelorder_newline(Node*);
    Node* deleteNode(Node*, string);
    Node* inpre(Node*);
    Node* insuc(Node*);
};
#include <cstdlib>
#include <iostream>
#include <vector> 
#include <algorithm>
#include <string>
#include <stack>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <stdexcept>
#include <fstream>
#include <array>
#include <sstream>
#include <cstring>
//#include "avl.h"
using namespace std;
//duplicates and range
struct AVLwithparent {
    struct AVLwithparent* left =NULL;
    struct AVLwithparent* right=NULL;
    string key;
    struct AVLwithparent* par = NULL;
    int height;
    int ss = 1;
};
 
// Function to update the height of
// a node according to its children's
// node's heights
void Updateheight(
    struct AVLwithparent* root)
{
    if (root != NULL) {
 
        // Store the height of the
        // current node
        int val = 1;
 
        // Store the height of the left
        // and right subtree
        if (root->left != NULL)
            val = root->left->height + 1;
 
        if (root->right != NULL)
            val = max(
                val, root->right->height + 1);
 
        // Update the height of the
        // current node
        root->height = val;
    }
}
void Updatess(struct AVLwithparent* root){
  if(root != NULL){
    int val = 1;
    if (root->left!=NULL){
      val += root->left->ss;
  }
    if(root->right != NULL){
      val += root->right->ss;
    }
    root->ss = val ;
}
}
// Function to handle Left Left Case
struct AVLwithparent* LLR(struct AVLwithparent* root)
{
    // Create a reference to the
    // left child
    struct AVLwithparent* tmpnode = root->left;
 
    // Update the left child of the
    // root to the right child of the
    // current left child of the root
    root->left = tmpnode->right;
 
    // Update parent pointer of the
    // left child of the root node
    if (tmpnode->right != NULL)
        tmpnode->right->par = root;
 
    // Update the right child of
    // tmpnode to root
    tmpnode->right = root;
 
    // Update parent pointer of
    // the tmpnode
    tmpnode->par = root->par;
 
    // Update the parent pointer
    // of the root
    root->par = tmpnode;
 
    // Update tmpnode as the left or the
    // right child of its parent pointer
    // according to its key value
    if (tmpnode->par != NULL
        && root->key < tmpnode->par->key) {
        tmpnode->par->left = tmpnode;
    }
    else {
        if (tmpnode->par != NULL)
            tmpnode->par->right = tmpnode;
    }
 
    // Make tmpnode as the new root
    root = tmpnode;
 
    // Update the heights
    Updateheight(root->left);
    Updateheight(root->right);
    Updateheight(root);
    Updateheight(root->par);

    Updatess(root->left);
    Updatess(root->right);
    Updatess(root);
    Updatess(root->par);
 
    // Return the root node
    return root;
}
 
// Function to handle Right Right Case
struct AVLwithparent* RRR(
    struct AVLwithparent* root)
{
    // Create a reference to the
    // right child
    struct AVLwithparent* tmpnode = root->right;
 
    // Update the right child of the
    // root as the left child of the
    // current right child of the root
    root->right = tmpnode->left;
 
    // Update parent pointer of the
    // right child of the root node
    if (tmpnode->left != NULL)
        tmpnode->left->par = root;
 
    // Update the left child of the
    // tmpnode to root
    tmpnode->left = root;
 
    // Update parent pointer of
    // the tmpnode
    tmpnode->par = root->par;
 
    // Update the parent pointer
    // of the root
    root->par = tmpnode;
 
    // Update tmpnode as the left or
    // the right child of its parent
    // pointer according to its key value
    if (tmpnode->par != NULL
        && root->key < tmpnode->par->key) {
        tmpnode->par->left = tmpnode;
    }
    else {
        if (tmpnode->par != NULL)
            tmpnode->par->right = tmpnode;
    }
 
    // Make tmpnode as the new root
    root = tmpnode;
 
    // Update the heights
    Updateheight(root->left);
    Updateheight(root->right);
    Updateheight(root);
    Updateheight(root->par);
 
    Updatess(root->left);
    Updatess(root->right);
    Updatess(root);
    Updatess(root->par);
    // Return the root node
    return root;
}
 
// Function to handle Left Right Case
struct AVLwithparent* LRR(
    struct AVLwithparent* root)
{
    root->left = RRR(root->left);
    return LLR(root);
}
 
// Function to handle right left case
struct AVLwithparent* RLR(
    struct AVLwithparent* root)
{
    root->right = LLR(root->right);
    return RRR(root);
}
 
// Function to insert a node in
// the AVL tree
struct AVLwithparent* Insert(
    struct AVLwithparent* root,
    struct AVLwithparent* parent,
    string key)
{
 
    if (root == NULL) {
 
        // Create and assign values
        // to a new node
        root = new struct AVLwithparent;
 
        // If the root is NULL
        if (root == NULL) {
            cout << "Error in memory"
                 << endl;
        }
 
        // Otherwise
        else {
            root->height = 1;
            root->left = NULL;
            root->right = NULL;
            root->par = parent;
            root->key = key;
        }
    }
 
    else if (root->key > key) {
 
        // Recur to the left subtree
        // to insert the node
        root->ss ++;
        root->left = Insert(root->left,
                            root, key);
 
        // Store the heights of the
        // left and right subtree
        int firstheight = 0;
        int secondheight = 0;
 
        if (root->left != NULL)
            firstheight = root->left->height;
 
        if (root->right != NULL)
            secondheight = root->right->height;
 
        // Balance the tree if the
        // current node is not balanced
        if (abs(firstheight
                - secondheight)
            == 2) {
 
            if (root->left != NULL
                && key < root->left->key) {
 
                // Left Left Case
                root = LLR(root);
            }
            else {
 
                // Left Right Case
                root = LRR(root);
            }
        }
    }
 
    else if (root->key < key) {
 
        // Recur to the right subtree
        // to insert the node
        root->ss++;
        root->right = Insert(root->right,
                             root, key);
 
        // Store the heights of the
        // left and right subtree
        int firstheight = 0;
        int secondheight = 0;
 
        if (root->left != NULL)
            firstheight
                = root->left->height;
 
        if (root->right != NULL)
            secondheight = root->right->height;
 
        // Balance the tree if the
        // current node is not balanced
        if (abs(firstheight - secondheight) == 2) {
            if (root->right != NULL
                && key < root->right->key) {
 
                // Right Left Case
                root = RLR(root);
            }
            else {
 
                // Right Right Case
                root = RRR(root);
            }
        }
    }
 
    // Case when given key is already
    // in the tree
    else {
    }
 
    // Update the height of the
    // root node
    Updateheight(root);
    Updatess(root);
 
    // Return the root node
    return root;
}
 
// Function to print the preorder
// traversal of the AVL tree
void printpreorder(
    struct AVLwithparent* root)
{
    // Print the node's value along
    // with its parent value
    cout << "Node: " << root->key << "SubtreeSize" << root->ss
         << ", Parent Node: " ;
 
    if (root->par != NULL)
        cout << root->par->key << endl;
    else
        cout << "NULL" << endl;
 
    // Recur to the left subtree
    if (root->left != NULL) {
        printpreorder(root->left);
    }
 
    // Recur to the right subtree
    if (root->right != NULL) {
        printpreorder(root->right);
    }
}

int rangeHigh(struct AVLwithparent* start, string high){
  //cout << "checking if null" << endl;
  if(start == NULL){
    return 0;
    }
  //cout << "is not NULL:" << start->key << endl;
  //cout << (start->key == high) << endl;
  if (start->key == high){
    int sum = 1;
      if (start->left){
          sum += start->left->ss;
      }
      return sum;
  }
  if (high > start->key){
      int sum = start->left ? start->left->ss : 0;
      sum ++;
      if(start->right){
      //cout << "keep going right: " << start->right->key << endl;
      }
      else{
          //cout << "ending tree " << endl;
      }
      return sum + rangeHigh(start->right,high);
  }
  if(start->key > high){
      //cout << "get smaller" << endl;
      return rangeHigh(start->left,high);
  }
  /*
  if(start == NULL){
    return 0;
    }
  if (start->key == high){
    //return 1 + start->left->ss;
    return 1;
  }
  if (start->key < high){
      int sum;
      if(start->left == NULL){
          sum = 0;
      }
      else{
          sum = start->left->ss;
      }
      sum ++;
      return sum + rangeHigh(start->right,high);
  }
  if(start->key > high){
      return rangeHigh(start->right,high);
  }
  */
}
int rangeLow(struct AVLwithparent* start, string low){
    /*
    if(start == NULL){
    return 0;
    }
    if (start->key > low && start->right != NULL){
      cout << "checking low" << start->key << "ss" << start->ss << endl;
      return rangeLow(start->right,low);
  }
  else{
    //cout << "returning" << start->par->ss - start->ss << endl;
    return start->ss;
  }
  */
  //cout << "checking if null" << endl;
  if(start == NULL){
    return 0;
    }
  //cout << "is not NULL:" << start->key << endl;
  if (start->key == low){
      //cout << "found start" << endl;
      int sum = 1;
      if (start->right){
          sum += start->right->ss;
      }
      return sum;
  }
  
  if (low < start->key){
      int sum = start->right ? start->right->ss : 0;
      sum ++;
      /*
      if(start->left){
      //cout << "keep going left: " << start->left->key << endl;
      }
      else{
          //cout << "ending tree " << endl;
      }
      */
      return sum + rangeLow(start->left,low);
  }
  if(start->key < low){
        //cout << "get bigger" << endl;
      return rangeLow(start->right,low);
  }
  

}
int range(struct AVLwithparent* start, string high, string low){
    
  if(start == NULL){
    return 0;
  }
  /*
  cout << "checking" << start->key << endl;
  //cout << (start->key <= high) << endl;
  //cout << (start->key >= low) << endl;
  if(start->key <= high && start->key >= low){
        //cout << "recurring left and right" << endl;
        return rangeLow(start->left,low) + rangeHigh(start->right, high);
    }
  if(start->key < low){
    //cout << "recur right: " << start->right->key <<  endl;
    return range(start->right,high,low);
  }
  if(start->key > high){
    //cout << "recur left: " << start->left->key << endl;
    return range(start->left,high,low);
  }
  */
  //cout << "is not NULL:" << start->key << endl;
  //cout << high << start->key << endl;
  //cout << (high < start->key) << endl;
  if(high < start->key){
      //cout << "recur left: " << start->left->key <<  endl;
      return range(start->left,high,low);
  }
  if(low > start->key){
      //cout << "recur right: " << start->right->key << endl;
      return range(start->right,high,low);
  }
  int sum = 1;
  if(low < start->key){
      //cout << "rangeLow: " << start->left->key <<  endl;
      sum += rangeLow(start->left,low);
      //cout << "sumL: " << sum << endl;
      }
  if(start->key < high){
      //cout << "recurHigh: " << start->right->key <<  endl;
      sum += rangeHigh(start->right,high);
      //cout << "sumLnR: " << sum << endl;

  }
  return sum;
  
      
}


// Driver Code
int main(int argc, char** argv)
{
    if (argc < 3) // must provide two arguments as input
    {
        throw std::invalid_argument("Usage: ./avlwrapper <INPUT FILE> <OUTPUT FILE>"); // throw error
    }

    ifstream input; // stream for input file
    ofstream output; // stream for output file

    input.open(argv[1]); // open input file
    output.open(argv[2]); // open output file

    string command; // to store the next command and operation
    char *com, *dummy, *valstr, *valstr2, *op; // for using with strtok, strtol
    string val,val2; // the value from the command

    AVLwithparent* root; // initializing the linked list
    root = NULL;
        

    while(getline(input,command)) // get next line of input, store as repeat
    {
        if (command.length() == 0) // command is empty
            continue;
        com = strdup(command.c_str()); // annoying, first copy string into a "C-style" string
        op = strtok(com, " \t"); //tokenize command on whitespace, first token is operation

         // next token is value, as string (check out documentation on strtok, to understand the parsing)
        valstr = strtok(NULL, " \t");
        if(valstr != NULL) // first check if there is actually anything to convert into int
            val = valstr; // convert initial portion of valstr into an integer val, with base 10. Check out documentation on strtol for more details.
        valstr2 = strtok(NULL, " \t");
        if(valstr2 != NULL) // first check if there is actually anything to convert into int
            val2 = valstr2; // convert initial portion of valstr into an integer val, with base 10. Check out documentation on strtol for more details.
        
    
        if(strcmp(op,"i") == 0) // insert into list
        {
            //cout << "Insert "+ val << endl;
            root = Insert(root,NULL,val);
        }
        if(strcmp(op,"d") == 0) // delete from list
        {
            //cout << "Delete "+ val << endl;
            //free(myBST.deleteKey(val)); // delete the value, and free the memory
        }
        if(strcmp(op,"f") == 0) // delete from list
        {
            //string message;
            //if(myBST.find(val)) // yes, val is found in BST
                //message = " found";
            //else
                //message = " not found";
            //cout << val + message << endl;
            //output << val + message << endl;
        }
        if(strcmp(op,"pin") == 0) // print tree in order
        {
            //output << myBST.printInOrder() << endl; // write printed tree to file, and add new line
            //cout << "Print In Order" << endl;
            //cout << myBST.printInOrder() << endl; // printing to console
            continue; // move on to next command
        }
        if(strcmp(op,"ppre") == 0) // print tree pre order
        {
            //output << myBST.printPreOrder() << endl; // write printed tree to file, and add new line
            //cout << "Print Pre Order" << endl;
            //cout << myBST.printPreOrder() << endl; // printing to console
            printpreorder(root);
            continue; // move on to next command
        }
        if(strcmp(op,"ppost") == 0) // print tree post order
        {
            //output << myBST.printPostOrder() << endl; // write printed tree to file, and add new line
            //cout << "Print Post Order" << endl;
            //cout << myBST.printPostOrder() << endl; // printing to console
            continue; // move on to next command
        }
        if(strcmp(op,"r") == 0) // print tree post order
        {
            int m = range(root,val2,val);
            output << m << endl;
            //cout << "there are " << m << " between" << val << "and" <<  val2 << endl;
	}
     }
}

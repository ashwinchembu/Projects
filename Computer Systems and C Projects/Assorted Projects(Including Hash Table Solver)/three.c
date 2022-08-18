#include "final.h"

#include <stdio.h>

int depth_of_value(int value, BinaryTree *tree) {
  // Your code here!
  // Remember -- return 0 if the value is found at the root node, and -1 if the
  // value is not found in the tree at all.
  // You don't have to handle trees where the same value occurs more than once,
  // but if it does happen, you ought to return the shallowest depth of that
  // value.
  // Also remember that this is just a binary tree, not a binary *search* tree.
  //code adapted from python pseudocode in https://www.geeksforgeeks.org/program-to-calculate-height-and-depth-of-a-node-in-a-binary-tree/
  int result = -1;
  if(tree == NULL){
  	return -1;
  }
  if(tree->val == value){
   return result + 1;
  }
  result = depth_of_value(value,tree->left);
  if (result >= 0){
  return result + 1;
  }
  result = depth_of_value(value,tree->right);
  if (result >= 0){
  return result + 1;
  }
  return result;
}

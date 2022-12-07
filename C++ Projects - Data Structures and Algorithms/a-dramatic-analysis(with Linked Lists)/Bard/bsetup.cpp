#include "setup.h"
#include <cstdlib>
#include <iostream>
#include <vector> 
#include <algorithm>
#include <string>
using namespace std;


// Insert(string val): Inserts the int val into list, at the head of the list. Note that there may be multiple copies of val in the list. Increments the counter of the node if the value is found.
// Input: Int to insert into the linked list
// Output: Void, just inserts new Node
Node* insertNew(string val, Node* head){
    Node* toad = new Node;
    toad->data = val;
    toad->count = 0;
    return findInsert(val,head,toad);
}
void insert(Node** arr,string val)
{
  int value = val.length();
  int ind = value-5;
  Node *curr;
  curr = find(arr[ind],val);
  if (curr !=  NULL){
    arr[ind] = findInsert(val, arr[ind], curr);
  }
  else{
    arr[ind] = insertNew(val, arr[ind]);
  }
  std::cout << "Inserting Word: " << val << "into" << ind;
}
Node* findInsert(string val, Node* len, Node* ins){
    ins->count ++;
    int nfreq = ins->count++;
    Node* curr = len;//make case for before/after head
    string insw = ins->data;
    string curw = curr->data;
    //checks if ins belongs before head
    if (nfreq > curr->count){
        if (insw.compare(curw) < 0){
            Node* prev = len;
            while(prev->next != NULL){
                if (((prev->next->data).compare(insw)) == 0){
                    break;
                }
                prev = prev->next;
            }
            prev->next = ins->next;
            ins->next = len;
            len = ins;
            return len;
        }
    }
    //checks if ins belongs after head alphabetically
    if(nfreq-1 == curr->count){
        if (insw.compare(curw) > 0){
            Node* prev = len;
            while(prev->next != NULL){
                if (((prev->next->data).compare(insw)) == 0){
                    break;
                }
                prev = prev->next;
            }
            prev->next = ins->next;
            ins->next = curr->next;
            curr->next = ins;
            return len;
            
    }
    }
    //find pointer before ins's frequency
    while(curr->next !=NULL){
        if(curr->next->count == nfreq){
            curr = curr->next;
        }
    }
    //iterate through ins's frequency to determine where it belongs alphabetically
    nfreq --;
    Node* curr2 = curr;
    while(curr2->next != NULL){
        string curtw = curr->next->data;
        if (curr2->next->count == nfreq){
            if (insw.compare(curtw) > 0){
                curr2=curr2->next;
            }
            else{
                break;
            }
        }
    }
    Node* prev2 = len;
            while(prev2->next != NULL){
                if (((prev2->next->data).compare(insw)) == 0){
                    break;
                }
                prev2 = prev2->next;
            }
    prev2->next = ins->next;
    ins->next = curr2->next;
    curr2->next = ins;
    return len;
}

// find(int val): Finds a Node with data "val"
// Input: str to be found
// Output: a pointer to a Node containing val, if it exists. Otherwise, it returns NULL
// Technically, it finds the first Node in the list containing val
Node* find(Node* head, string val)
{
    Node *curr = head; // curr is the current Node as it progresses through the linked list. Initialized to head to start at the head of the list
    // curr will look over list. At every iteration, we will check if curr->data is val. If so, we are done. Otherwise, we proceed through the list.
    while(curr != NULL) //looping over list
    {
        if ((curr->data).compare(val)) // found val, so return curr
            return curr;
        curr = curr->next; // otherwise, proceed through list
    }
    // if loop terminates, val not found
    return NULL;
}

// deleteNode(int val): Delete a Node with data val, if it exists. Otherwise, do nothing.
// Input: int to be removed
// Output: pointer to Node that was deleted. If no Node is deleted, return NULL. If there are multiple Nodes with val, only the first Node in the list is deleted. Note that this removes the node from the list
//         but does not free the corresponding memory
Node* deleteNode(string val, Node* head)
{
    Node* prev = NULL;
    Node* curr = head;
    while(curr != NULL) // loop over list, starting from head
    {
        if(curr->data == val) // we found Node with val, so break
            break; 
        //otherwise, proceed list
        prev = curr; // move prev by one Node
        curr = curr->next; // move curr by one Node
    }
    // at this point, curr points to Node with val. If curr is null, then val is not in the list.
    if (curr == NULL) // val not found
        return NULL; 
    // val is in list. Note that curr is not NULL. There is a case analysis now. If prev is null, then curr is head. So we delete head directly.
    // Otherwise, we delete the Node after prev.
    if (prev == NULL) // we need to delete head
        head = head->next; // delete head
    else // we delete Node after prev. Note that both curr and prev are not NULL
        prev->next = curr->next; // make prev point to Node after curr. This removes curr from list
    curr->next = NULL; // set next pointer of curr to NULL, to ensure no dangling references
    return curr;
}


// deleteAndFreeNode(int val): Delete a Node with data val and free the memory, if it exists. Otherwise, do nothing.
// Input: int to be removed
// Output: void. If there are multiple Nodes with val, only the first Node in the list is deleted. Note that this frees the memory of that deleted node
void deleteAndFreeNode(string val, Node* head)
{
    Node* ptr = deleteNode(val,head); // get pointer to node with val
    if (ptr != NULL) // if node actually exists
    {
        ptr->next = NULL; // just be extra safe, probably don't need this
        delete(ptr); // free that memory
    }
    return; //DONE!
}

// Deletes every Node to prevent memory leaks.
// Input: None
// Output: Void, just deletes every Node of the list
void deleteList(Node* head)
{
	Node *curr = head; // curr is the current Node as it progresses through the linked list. Initialized to head to start at the head of the list
    Node *temp = NULL;

	// curr will loop over list. At every iteration, we first store a pointer to the next Node, and then delete the current Node.
    while(curr != NULL){ // Looping over list
		temp = curr->next; // store pointer to next Node in the list
		delete(curr); // delete the current Node
		curr = temp; // update curr to proceed through list
	}
	head = NULL;
}

// Prints list in order
// Input: None
// Output: string that has all elements of the list in order
string print(Node* head)
{
    string list_str = ""; // string that has list
	Node *curr = head; // curr is the current Node as it progresses through the linked list. Initialized to head to start at the head of the list
	// curr will loop over list. It prints the content of curr, and then moves curr to next Node.
	while(curr != NULL){ // looping over list
        list_str = list_str + curr->data + " "; //append string with current Node's data
		curr = curr->next; // proceed through list
	}
    if (list_str.length() > 0) // string is non-empty
        list_str.pop_back(); // remove the last (extra) space from string
    return list_str;
}

// Computes the length of the linked list
// Input: None
// Output: Int, length of list
int LLlength(Node* head)
{
    int length = 0; // initialize length to zero
	Node *curr = head; // curr is ths current Node as it progresses through the linked list. Initialized to head to start at the head of the list
	
	while(curr != NULL){ // looping over list
		length++; // increment length
		curr = curr->next; // proceed to next Node
	}
	return length;
}


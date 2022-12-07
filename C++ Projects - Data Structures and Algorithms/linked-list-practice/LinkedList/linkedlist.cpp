// Filename: linkedlist.cpp
// 
// Contains the class LinkedList that represents a linked list. This contains some basic operations, such as insert, delete, find, length
// 
// Japheth Frolick, August 2019
// C. Seshadhri, Jan 2020

#include "linkedlist.h"
#include <cstdlib>
#include <iostream>
#include <vector> 
#include <algorithm>
#include <string>
using namespace std;

// Default constructor sets head and tail to null
LinkedList :: LinkedList()
{
	head = NULL;
}

// Insert(int val): Inserts the int val into list, at the head of the list. Note that there may be multiple copies of val in the list.
// Input: Int to insert into the linked list
// Output: Void, just inserts new Node
void LinkedList :: insert(int val)
{
	Node *to_add = new Node; // creates new Node
	to_add->data = val; // sets the data to hold input val
	
    to_add->next = head; // make to_add point to existing head
    head = to_add; // set head to to_add
}

// find(int val): Finds a Node with data "val"
// Input: int to be found
// Output: a pointer to a Node containing val, if it exists. Otherwise, it returns NULL
// Technically, it finds the first Node in the list containing val
Node* LinkedList :: find(int val)
{
    Node *curr = head; // curr is the current Node as it progresses through the linked list. Initialized to head to start at the head of the list
    // curr will look over list. At every iteration, we will check if curr->data is val. If so, we are done. Otherwise, we proceed through the list.
    while(curr != NULL) //looping over list
    {
        if (curr->data == val) // found val, so return curr
            return curr;
        curr = curr->next; // otherwise, proceed through list
    }
    // if loop terminates, val not found
    return NULL;
}

// deleteNode(int val): Delete a Node with data val, if it exists. Otherwise, do nothing.
// Input: int to be removed
// Output: pointer to Node that was deleted. If no Node is deleted, return NULL. If there are multiple Nodes with val, only the first Node in the list is deleted.
Node* LinkedList :: deleteNode(int val)
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
    return curr;
}

// Deletes every Node to prevent memory leaks.
// Input: None
// Output: Void, just deletes every Node of the list
void LinkedList :: deleteList()
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
    return;
}

// Prints list in order
// Input: None
// Output: string that has all elements of the list in order
string LinkedList :: print()
{
    string list_str = ""; // string that has list
	Node *curr = head; // curr is the current Node as it progresses through the linked list. Initialized to head to start at the head of the list
	// curr will loop over list. It prints the content of curr, and then moves curr to next Node.
	while(curr != NULL){ // looping over list
        list_str = list_str + to_string(curr->data) + " "; //append string with current Node's data
		curr = curr->next; // proceed through list
	}
    if (list_str.length() > 0) // string is non-empty
        list_str.pop_back(); // remove the last (extra) space from string
    return list_str;
}

// Computes the length of the linked list
// Input: None
// Output: Int, length of list
int LinkedList :: length()
{
    int length = 0; // initialize length to zero
	Node *curr = head; // curr is ths current Node as it progresses through the linked list. Initialized to head to start at the head of the list
	
	while(curr != NULL){ // looping over list
		length++; // increment length
		curr = curr->next; // proceed to next Node
	}
	return length;
}

void LinkedList :: reverse(int val)
{
    Node *curr = head;
    while (val-1 >0 and curr != NULL){
        curr = curr->next; 
        val --;
    }
    Node *pnex =NULL;
    if (curr != NULL){
        if (curr->next != NULL){
    pnex = curr->next;
    curr->next = NULL;
        }
    }
    Node* rcur = head;
    Node* rpre = NULL;
    Node* rnex = NULL;
    while(rcur != NULL){
        rnex = rcur->next;
        rcur->next = rpre;
        rpre = rcur;
        rcur = rnex;
    }
    head = rpre;
    Node *iter = head;
    Node *piter = NULL;
    while (iter != NULL){
        piter = iter;
        iter = iter->next;
    }
    if (pnex!=NULL){
    piter->next = pnex;
    }    
    
}
void LinkedList :: rotate(int x){
    int count = 0;
    while (count < x){
        Node *curr = head;
        Node *prev; 
        while(curr->next != NULL){
            prev = curr;
            curr = curr->next;
        }
        prev->next = NULL;
        curr->next = head;
        head = curr;
        count ++;
    }
}
void LinkedList :: reverseRotate(int x){
    int count = 0;
    while (count < x){
        Node *tmp = head;
        Node *curr = head;
        Node *thead = curr->next;
        while(curr->next != NULL){
            curr = curr->next;
        }
        tmp->next = NULL;
        curr->next = tmp;
        head = thead;
        count ++;
}
}

bool LinkedList :: checkPalindrome(Node* curr, Node* temp){
    if (curr == NULL || curr->next == NULL){
        printf("1\n");
        return true;
    }
    while (temp->next->next != NULL){
        temp = temp->next;
    }
    if (curr->data == temp->next->data){
        temp->next = NULL;
        head = head->next;
        return checkPalindrome(head,head);
    }
    else{
        printf("0\n");
        return false;
    }
}
bool LinkedList :: checkPalindrome(){
    if (head == NULL || head->next ==NULL){
        printf("1\n");
        return true;
    }
    return checkPalindrome(head,head);
}

void LinkedList :: deleteK(int val, int k){
    int counter = 0;
    Node *prev = head;
    Node *curr = NULL;
    if (prev->next != NULL){
    curr = prev->next;
    }
    if (prev->data == val and k == 1){
        delete(prev);
        return;
    }
    if(prev->data == val){
        counter ++;
    }
    while(curr!=NULL){
        printf("finding data");
        printf("curr at: %d",curr->data);
        if (curr->data == val){
            counter ++;
            if (k==counter){
                if (curr->next != NULL){
                prev->next = curr->next;
                }
                else{
                    prev->next = NULL;
                }
                curr->next = NULL;
                printf("deleting: %d",curr->data);
                delete(curr);
                return;
            }
            
        }
        prev = curr;
        curr = curr->next;
    }
    return;
}
void LinkedList :: reverseLastK(int val){
    int len = 1;
    Node *curr = head;
    while(curr->next!=NULL){
        curr = curr->next;
        len ++;
    }
    int stop = len-val;
    if (stop > 1){
    curr = head;
    Node *prev = NULL;
    while(stop > 0){
        prev = curr;
        curr = curr->next;
        stop --;
        printf("prev: %d", prev->data);
    }
    }
    prev->next = NULL;
    Node *rcur = curr;
    Node *rpre = NULL;
    Node *rnex = NULL;
    while(rcur->next != NULL){
        rnex = rcur->next;
        rcur->next = rpre;
        rpre = rcur;
        rcur = rnex;
    }
    rcur->next = rpre;
    prev->next = rcur;
}
void LinkedList :: makePalindrome(){
    Node *curr = head;
    Node *prev = NULL;
    Node * next = NULL;
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    curr = head;
    while(curr != NULL){
        insert(curr->data);
        printf("%d",curr->data);
        curr = curr->next;
    }
}
void LinkedList :: deleteLast(int val)
{
    int max = countVals(val);
    deleteK(val, max);
}
int LinkedList :: countVals(int val){
    int counter = 0;
    Node *curr = head;
    while (curr != NULL){
        if (curr->data == val){
            counter ++;
        }
        curr = curr->next;
    }
    printf("%d", counter);
    return counter;
}
void LinkedList :: deleteAllButFirst(int val){
    Node *first;
    first = find(val);
    int count = countVals(val);
    int i = 2;
    if (count > 1){
        while(count >1){
            printf("deleting %d occurence",i);
            deleteK(val,2);
            count--;
        }
    }
    }



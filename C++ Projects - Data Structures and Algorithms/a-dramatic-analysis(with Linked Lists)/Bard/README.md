# Much Ado About Linking
## Resources Used:

 - Linked List Implementation (codio resource provided by Prof. Demetrius)
 - Geeks 4 Geeks Linked List Insertion Sort ([Linked List](https://www.geeksforgeeks.org/insertion-sort-for-singly-linked-list/))
 - Geeks 4 Geeks Array of Linked Lists([Array](https://www.geeksforgeeks.org/array-of-linked-list-in-c-cpp/#:~:text=They%20can%20be%20used%20to,as%20structures,%20pointers,%20etc))
 - TA Vincent's Code(explained during his section)
## File Tree:
 - bard.cpp
	 - initializes an array of linked lists indexed by length and sets each linked list to null
	 - parses through the files text, input, and output(input and output provided as command line arguments)
	 - inserts and sorts to inputs from text file into appropriate LinkedList
	 - finds words by parsing through input and writes them to output file
	 - deletes linked lists are closes file
 - setup.h
	 - houses the library of all files necessary for bard.cpp to run, and holds the necessary constructors for the LinkedList class
 - setup.cpp
	 - LinkedList(); - Default constructor sets head to null
	 - void  insert(string); -insert string into list
	 - void  insertionfreqSort(); - sort based on frequency
	 - void  insertionalphaSort();- sort alphabetically
	 - void  sortedfreqInsert(Node*);-helper function
	 - void  sortedalphaInsert(Node*);-helper function
	 - string findit(int);-iterate through the LL until the pointer goes to the right place
	 - Node*  find(string); - find int in list, and return pointer to node with that string. If there are multiple copies, this only finds one copy
	 - Node*  deleteNode(string); - remove a node with string (if it exists), and return pointer to deleted node. This does not delete all nodes with the value.
	 - void  deleteAndFreeNode(string); - deletes and frees necessary node
	 - void  deleteList(); - deletes every node to prevent memory leaks, and frees memory
	 - string print(); - Construct string with data of list in order
	 - void  println(); - prints out Linked List to command line
	 - int  length(); - Returns the length of the linked list

## How to Run:

 1. ensure that the text file "shakespeare-cleaned5.txt" is in the proper folder and exists
 2. ensure that there is an input file that includes the proper formatting
 3. ensure that executables are made using "make" and "make clean"
 4. input ./bard < input > < output > to command line
 5. check output file for results


#include <iostream>
#include "setup.h"
#include <stack>
#include <stdexcept>
#include <fstream>
#include <array>
#include <vector> 
#include <algorithm>
#include <sstream>
#include <cstring>
using namespace std;

int main(int argc, char** argv)
{
  
    ifstream text; //stream for text

    text.open("shakespeare-cleaned5.txt");
    //array of LL code adapted from: https://www.geeksforgeeks.org/array-of-linked-list-in-c-cpp/#:~:text=They%20can%20be%20used%20to,as%20structures%2C%20pointers%2C%20etc.
    //array of linked lists(double pointer)
    LinkedList *top[37];
    //setting all values to NULL
    string line;
    while(getline(text,line)){
        string word;
        stringstream ss(line);
        ss >> word;
        insert(top,word);
        std::cout << "Inserting Word: " << word;
    }
    
}
    
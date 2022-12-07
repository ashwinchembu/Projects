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
    if (argc < 3) // must provide two arguments as input
    {
        throw std::invalid_argument("Usage: ./hello <INPUT FILE> <OUTPUT FILE>"); // throw error
    }
    ifstream text; //stream for text
    
    text.open("shakespeare-cleaned5.txt");
    //array of LL code adapted from: https://www.geeksforgeeks.org/array-of-linked-list-in-c-cpp/#:~:text=They%20can%20be%20used%20to,as%20structures%2C%20pointers%2C%20etc.
    //array of linked lists(double pointer)
    LinkedList *top[40];
    for(int i = 0; i < 40; i++){
        top[i] = new LinkedList;
    }
    //setting all values to NULL
    string line;
    //reading file and placing it into the respective LL
    while(getline(text,line)){
        string word;
        stringstream ss(line);
        ss >> word;
        //converts to c-type string
        string val = strdup(word.c_str());
        int len = val.length();
        top[len]->insert(val);
        //std::cout << "Inserting Word: " << word;
    }
    //sortin
    for(int i = 0; i < 37; i++){
        top[i]->insertionalphaSort();
        top[i]->insertionfreqSort();
        //std::cout << "Word of Length: " << i << "\n";
    }
    top[6]->println();
    //initialize and open input/output files
    ifstream input;
    ofstream output;
    input.open(argv[1]);
    output.open(argv[2]);
    //parse input file 
    string command;
    char *com,*dummy,*valstr,*op;
    int val;
    while(getline(input,command)){
      //ensure the command is one integer, a space, and another integer
      if (command.length() < 3){
        //std::cout << "Word of Length: " << i << "\n";
        output << "-" << endl;
        continue;
      }
      com = strdup(command.c_str());
      //serparate first value
      op = strtok(com, " \t");
      int num = stoi(op);
      //if the length doesn't fit in the array
      if (num >= 40){
        output << "-" << endl;
        continue;
      }
      //separate second value
      valstr = strtok(NULL, "\t");
      if(valstr != NULL)
        val = strtol(valstr, &dummy, 10);
      //find word and send to output
      string ret = top[num]->findit(val);
      output << ret << endl;
      continue; 
    }
    //delete list and eliminate any leaks
    for(int i = 0; i < 40; i++){
        top[i]->deleteList();
    }
    //close modified files
    text.close();
    input.close();
    output.close();
}

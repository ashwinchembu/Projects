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

bool compareRow(Pair one, Pair two){
        return(one.col<two.col);
      }

int main(int argc, char** argv)
{
   
    if (argc < 3) // must provide two arguments as input
    {
        throw std::invalid_argument("Usage: ./nqueens <INPUT FILE> <OUTPUT FILE>"); // throw error
    }
    ifstream text; //stream for text
    
    
    ifstream input;
    ofstream output;
    input.open(argv[1]);
    output.open(argv[2]);
    //parse input file 
    string command;
    char *com;;
    while(getline(input,command)){
      std::vector<class Pair> q;
      //cout << command << endl;
      //ensure the command is one integer, a space, and another integer
      if (command.length() < 2){
        //std::cout << "Word of Length: " << i << "\n";
        output << " " << endl;
        continue;
      }
      if (isspace(command.back())){
        command.pop_back();
      }
      string temp = "";
      int num;
      int counter = 0;
      com = strdup(command.c_str());
      for(int i = 0; i<3; i++){
        temp += com[i];
        counter++;
        if(isspace(com[i])){
          num = stoi(temp);
          break;
        }
      }
      /*
      cout << "board size " << num << endl;
      cout << "running code" << endl;
      cout << "counter " << counter << endl;
      */
      if(num < 4){
        if(num == 1){
          continue;
        }
        //cout << "No solution" << endl;
        output << "No solution" << endl;
        continue;
      }     
      
      int k = counter;
      temp = "";
      int count = 0;
      Pair queen;
      for(unsigned int i = k; i < command.length(); i++){
        //cout << i << endl;
        //cout << command.at(i) << endl;
        if (!isspace(command.at(i))){
          temp += command.at(i);
          //cout << "temp" << temp << endl;
        }
        else if(count == 0){
          //cout << "adding col" << endl;
          //cout << temp << endl;
          queen.col = stoi(temp);
          temp.clear();
          count ++;
        }
        else if(count == 1){
          //cout << "adding row" << endl;
          //cout << temp << endl;
          queen.row = stoi(temp);
          q.push_back(queen);
          temp.clear();
          count --;
        }
      }

          //cout << "adding row1" << endl;
          queen.row = stoi(temp);
          q.push_back(queen);
      /*
      for(unsigned int i = 0; i < q.size(); i++){
        int r  = q[i].row;
        int c = q[i].col;
        cout << "r " << r << " ";
        cout << "c " << c << " ";
      }
      */
      /*
      com = strdup(command.c_str());
      cout << "com " <<com << endl;
      op = strtok(com, " \t");
      cout << op << endl;
      num = stoi(op);
      while(true){
        //serparate first value
        op1 = strtok(NULL, " \t");
        if(op1 == "\n"){
          break;
        }
        op2 = strtok(NULL, " \t");
        num1 = stoi(op1);
        num2 = stoi(op2);
        cout << "com " << com << endl;
        cout << op1 << endl;
        cout << op2 << endl;
        Pair n;
        n.row = num1;
        n.col = num2; 
        q.push_back(n);
      }
      */
      //cout << "running stack code" << endl;
      bool value;
      value = true;
      //cout << value << endl;
      for (unsigned int i = 0;i < q.size(); i++){
        /*
        for (unsigned int j = 0; j < q.size(); j++){
          if (i==j){
            continue;
          }
          */
          int n = q[i].row;
          int m = q[i].col;
          //cout << "testin " << endl;
          for(unsigned int k = 0;k < q.size(); k++){
            //cout << "running code on iteration" << k << endl;
            int r = q[k].row;
            int j = q[k].col;
            //cout << "initialized i,j " << r << j << endl;
            //cout << "initialized row,col " << n << m << endl;
            if (n == r && m == j){
              continue;
            }
            if (n == r){
              //cout << "on row" << endl;
              value = false;
              break;
            }
            if (m == j){
              //cout << "on col" << endl;
              value = false; 
              break;
            }
            float line = float(r-n)/float(j-m);
            //cout << "initialized line " << line << endl;
            if (line == 1 || line == -1){
            //cout << "on diag " << line << endl;
              value = false;
            }
        }
          //cout << value << endl;
        }
    
     // cout << "testin for segfaults" << endl;
      if(!value){
        //cout << "failed self tests" << endl;
        //cout << "No solution" << endl;
        output << "No solution" << endl;
        continue;
      }
      //cout << "testin for segfaults2" << endl;
      stack<int> Stack;
      for (int i = 1; i <= num; i++){
        bool inside = false;
          for (unsigned int j = 0; j < q.size(); j++){
            if (i == q[j].row)
              inside = true;
          }
        if (!inside){
          //cout << "adding row" << i << endl;
          Stack.push(i);
        }
      }
      int ncol = 1;
      //cout << " pushed all to stack " << endl;
      int s = Stack.size();
      //cout << "stack size1: " <<s << endl;
      while(!Stack.empty()){
        
        int curr;
        curr = Stack.top();
        //cout << "now placing: "<< curr << endl;
        Stack.pop();
        //cout << "curr " << curr << endl;;
        //cout << "ncol " << ncol << endl;
        int col = ncol;
        while (!isSafe(curr,col,q)){
          col++;
          if(col > num){
            //cout << "backtracking" << endl;
            break;
          }
          
        }
        if(col > num){
              Pair rem = q.back();
              Stack.push(curr);
              Stack.push(rem.row);
              int siz = Stack.size();
              //cout << "stack size2: " << siz << endl;
              //cout << "compared: " << (siz > s) << endl;
              if(s < Stack.size()){
                //cout << "end of board" << endl;
                break;
                }
              q.pop_back();
              ncol = rem.col;
              ncol ++;
              if(ncol>num && curr > num){
                //cout << "No solution2" << endl;
                //output << "No solution2" << endl;
                break;
              }
            }
        else{
          Pair temp;
          temp.row = curr;
          temp.col = col;
          //cout <<  "placed row:  " << curr << "placed  col: "<<  col << endl;
          q.push_back(temp);
          ncol = 1;
        }
      }
      //cout << "q.size " <<  q.size() << endl;
      if (q.size() != num){
        //cout << "No solution3" << endl;
        output << "No solution" << endl;
        continue;
      }
      sort(q.begin(),q.end(),compareRow);
      for(unsigned int i = 0; i < q.size(); i++){
        int r  = q[i].row;
        int c = q[i].col;
        
        output << c << " ";
        output << r << " ";
        //cout << c << " ";
        //cout << r << " ";
      }
      output << endl;
      
    //cout << "done with row" << endl;
    }
    //cout << "done with file" << endl;
    //close modified files
    input.close();
    output.close();
}

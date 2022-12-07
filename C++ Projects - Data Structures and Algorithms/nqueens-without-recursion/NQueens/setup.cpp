#include "setup.h"
#include <cstdlib>
#include <iostream>
#include <vector> 
#include <algorithm>
#include <string>
using namespace std;

bool isSafe(int row,int col, vector<Pair> vect)
{
  //cout << "runinn safe" << endl;
  for(int k = 0;k < vect.size(); k++){
    //cout << "running code on iteration" << k << endl;
    int i = vect[k].row;
    int j = vect[k].col;
    //cout << "initialized i,j " << i << j << endl;
    //cout << "initialized row,col " << row << col << endl;
    
    if (row == i){
      //cout << "on row" << endl;
      return false;
    }
  
    if (col == j){
      //cout << "on col" << endl;
      return false;
    } 
    float line = float(i-row)/float(j-col);
    //cout << "initialized line " << line << endl;
    if (line == 1 || line == -1){
      //cout << "on diag " << line << endl;
      return false;
    }
  }
  //cout << "si safe  " << endl;
  return true;
}
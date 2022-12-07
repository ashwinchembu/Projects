#ifndef LIST_H
#define LIST_H
#include <string>
#include "setup.h"
#include <cstdlib>
#include <iostream>
#include <vector> 
#include <algorithm>
#include <string>
using namespace std;
using namespace std;

class Pair
{
  public:
    int row;
    int col;
};

bool isSafe(int,int,vector<Pair>);

#endif
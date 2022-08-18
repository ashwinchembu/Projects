#include "final.h"

#include <stdio.h>
#include <limits.h>

void find_two_biggest(LLint *linkedlist, int *biggest, int *nextbiggest) {
  int b= INT_MIN;
  int b1 = INT_MIN;
  LLint *ll = linkedlist;
  while(ll->next !=NULL){
  	int s = ll->val;
  	if (s > b){
  	b1 = b;
  	b = s;
  	}
  	else if(b1 < s){
  	b1 = s;
  	}
  	ll = ll->next;
  }

  *biggest = b;
  *nextbiggest = b1;
  return;
}

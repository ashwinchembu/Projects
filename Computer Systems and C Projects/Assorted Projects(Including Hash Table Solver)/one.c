#include "final.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

size_t word_count(char *text) {
  // Your code here!
  // Count up all the words that occur in the given string. A new word starts
  // when you see a letter a-z or A-Z.
  size_t counter = 0;
  int index = 0;
  int length = strlen(text);
  char c;
  char f;
  do{
  	  f = text[index];	
	  do{
	  c = text[index];
	  //printf("character c: %c \n",c);
	  index +=1;
	  }while(isalpha(c));
	  //printf("character f: %c \n",f);
	  if (isalpha(f)){
	  counter +=1;
	  }
  }while(index < (length-1));
  return counter;
}

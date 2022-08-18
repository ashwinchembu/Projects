#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "stack_calculator.h"

// Allocate a new Stack struct and return a pointer to it.
Stack *stack_create(void) {
  // this one is complete, no need to change it!
  Stack *out;
  out = (Stack *)calloc(1, sizeof(Stack));
  return out;
}

// Add a new node at the front of the stack. Return false if we are unable to do
// so (eg, if memory allocation fails).
//push and pop derived from Prof Rudnick's examples
bool stack_push(Stack *s, CalculatorItem item) {
  // your code here
  Node *n = (Node *)calloc(1,sizeof(Node));
  if (n == NULL){
      return false;
  }
  n->item = item;
  n->next = s->top;
  s->top = n;
  return true;
}

// Pop the stack and put the result into the output pointer.
// return false if the stack is NULL or if it is empty.
bool stack_pop(Stack *s, CalculatorItem *output) {
  // your code here
  if (s==NULL||s->top==NULL){
      //printf("no more");
      return false;
  }
  else{
  CalculatorItem r =s->top->item;
  *output = r;
  Node *d = s->top;
  s->top = s->top->next;
  free(d);
  return true;
  }
}

// Returns true if the specified stack is empty.
bool stack_empty(Stack *s) {
  // your code here
  if (s->top == NULL){
       return true;
  }
  else {
      return false;
  }
 
}

// Free all of the memory used by this stack, including its linked list.
// When you are done, set the pointer to NULL.
void stack_delete(Stack **s) {
  // your code here
  Stack *m;
  m = *s;
  while (!stack_empty(*s)){
  	Node *d = (*s)->top;
  	(*s)->top = (*s)->top->next;
  	free(d);
  }
  free(*s);
  *s = NULL;
}

// Returns true if we were able to successfully perform the computation step,
// and false if there was an error of some kind.
bool stack_compute_step(Stack *s, CalculatorItem item) {
  // your code here
  CalculatorItem b;
  CalculatorItem c;
  float n;
  if (item.type == NUMBER){
      //printf("number,%f",item.value);
      stack_push(s,item);
  }
  else if (item.type == ADD||item.type == SUBTRACT||item.type == MULTIPLY||item.type ==  DIVIDE){
      //printf("operator");
      bool b1 = stack_pop(s,&b);
      
     //printf("%f",b.value);
     bool c1 = stack_pop(s,&c);
     //printf("%f",c.value);
     if (b1 && c1){
      if (item.type == ADD){
          //printf("ADD");
          n = b.value + c.value;
          CalculatorItem y;
      	  y.type = NUMBER;
      	  y.value = n; 
      	  stack_push(s,y);
      }
      else if (item.type == SUBTRACT){
      	//printf("ADD");
          n = c.value - b.value;
          CalculatorItem y;
      y.type = NUMBER;
      y.value = n; 
      stack_push(s,y);
      }
      else if (item.type == MULTIPLY){
          n = b.value * c.value;
          CalculatorItem y;
      y.type = NUMBER;
      y.value = n; 
      stack_push(s,y);
      }
      else if (item.type == DIVIDE){
          n = c.value/b.value;
          if (b.value==0){
          return false;
          }
          else{
          
          CalculatorItem y;
      y.type = NUMBER;
      y.value = n; 
      stack_push(s,y);
      }
      }
      
  }
  else{
  return false;
  }
  }
  else {
      return false;
  }
  
  return true;
}

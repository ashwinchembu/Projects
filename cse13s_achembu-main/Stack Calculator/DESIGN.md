# dynamic memory, linked lists and stacks

## Purpose
The purpose of "dynamic memory, linked lists and stacks" is to return a certain value based on 3 inputs from a stack, 2 values, and an operator.
# Layout/Structure

### stack_calculator.c

contains methods to push to the stack, pop from the stack, empty the stack, delete the stack, and compute its steps

### stack_calculator.h
contains library from stack_calculator.c

### input.txt

stores inputs for the stack_calculator.c

## Pseudocode(stack_calculator.c)
 ```
stack_push(Stack *s, CalculatorItem item) {
m = create node instance(item)
 node = malloc(m)
 if (node == NULL)
	 return false
assign n's item to item argument
assign n's next to s's top
assign s's top to n
 return true
}
bool stack_pop(Stack *s, CalculatorItem *output) {
n = len(s)
output = s[n]
 if (output == NULL)
	 return false
assign the item at the top of the stack to a calc item R
set *output to r
increment next
free D
return output;
}
stack_empty(Stack *s) {
n = len(s)
 if n < 0:
	 return true;
else return false
}
stack_delete(Stack **s) {
	stack *m 
	m = *s
 for d in s:
	store top in node D
	incement next
	increment next
	free D	
	 e  =free(m)
free *s
*s=null
}
stack_compute_step(Stack *s, CalculatorItem item) {

b = stackpop(s,*b)
c = stackpop(s,*c)
if statement to check operator or number 
	if number
		push to stack
	if operator and minimum 2 value in stack
		pop b,c
		do operation
		store in CalculatorItem[s]
		if divided by 0, return false
 return true;
}
```

# functions, arrays, and pointers

## Purpose
The purpose of "functions, arrays and pointers" is to return a certain value based on the function that is called. Each function manipulates or outputs a value from an array and returns that array.
# Layout/Structure

### hw2.c

runs methods in num_arrays.c and generates array to do so

### num_arrays.h

stores methods and arguments

### num_arrays.c

stores methods and has the necessary information to run

## Pseudocode(num_arrays.c)
```
max(){
max = 0
for loop for length of array:
	if max < array[i]:
		max = array[i]
return max
}
sum_positive(){
sum = 0 
for loop for length of array:
	if array[i] > 0
		sum += array[i]
return sum
	}
reduce(){
acr = 0;
if inital > 0
	value = acr 
else 
	value =0
for loop for length of array:
	call function on array[i]
	value = array[i]
return value
}
maximum_with reduce(){
	m = reduce(max2)
	return m
}
max2 {
	if val > max
		max = val
	return max
}
pos {
	if val > 0
		sum += 	val
	return sum
}
sum positive with reduce(){
	m = reduce(pos)
	return m
}
neg {
	if val > 0
		sum +=1
	return sum
}
count negative with reduce(){
	m = reduce(neg)
	return m
}


```


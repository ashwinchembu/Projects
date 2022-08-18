# strings, searching, words

  

## Purpose

The purpose of "functions, arrays and pointers" is to simulate the popular game "worlde," which involves guessing a 5-letter word based on whether or not certain letters appear in it.

# Layout/Structure

  

### hw5.c

  

contains the methods necessary to run the game, including checking if guesses are valid, generating an array of words from a text file, returning a 5-letter output to play the game, and actually run the game 

  

### vocabulary.txt

  

a text file that stores a list of 5-letter words separated by a newline

# Pseudocode
## score_guess

    reset result to empty string
    check if guess == secret 
	 return 'ggggg'
	 else
	 create array to store secret and guess characters and their location
	double for loop
		check if there are any repetitive letters in secret and change them so they have the same location and exit loop
	double for loop
		check if secret's letter is in the same postion as guess and put 'g' in that place in result
		else check if its in the wrong postion and put 'y' in its place in result
	else just put it in x		


		
## add2guesses
	allocate a new spot for guesses	
	add guess to array
	return bigger array
## valid guess

    linear search through vocab to check if word is in there
    if num_guesses >1
	    reset result
	    compare previous guesses with results
	    for loop
		    check if letters in results have already been marked 'x' and output that letter cannot be guessed
		    if letter has been marked 'y' say that it has already been guessed in the wrong spot
## load vocab

    open file
    create buffer
    allocate new space of array
    set counter = 1
    fgets to buffer
    set array[counter-1] to buffer
    increase size of array y 1
    increase counter by 1
       set num_words to counter-1
       close file
       reutrn array
   ## free vocab
	   loop through vocab with for loop and free each string
	   free vocab pointer
## main

    initialize vocab, number of words, number of guesses, array of guesses and set seed for random
    load vocabulary
    randomly select word from vocabulary
    get buffer to get a guess from user
    check if guess is valid, and increment num_guesses by one and add it to guesses using add2guesses
    check if word is correct using score_guess
    print guess and result
    free vocab and num_guesses
    reutrn 0;




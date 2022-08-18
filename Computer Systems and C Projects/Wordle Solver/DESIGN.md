# Strings, Searching, Pointers!

  

## Purpose

The purpose of "Strings, Searching, Pointers!" is to simulate  a solver for the popular game "worlde," which involves guessing a 5-letter word based on whether or not certain letters appear in it.

# Layout/Structure

  

### search_util.c



  

contains the methods necessary to run the game, including checking if guesses are valid, which words contain a certain letter, calculates the score for a word, return the optimal guess, filters out improbable words, and free the stack 
  

### **solver.c**

 contains methods necessary to generate an array of words from a text file, returning a 5-letter output to play the game, and actually run the game 

### vocabulary.txt
 a text file that contains 5-letter valid guesses, separated by a newline

# Pseudocode
## `score_letter`
    counter = 0
    create empty list 
    loop over vocabulary
	    if it holds the character increment counter	
    return counter

		
## `score_word`
        score = 0 
	create empty list
	ind = letter - a
	loop over word and check if each letter is in list
		add to scores by accessing letter_Scores[ind] and add letter in list
	return score
## `filter_vocabulary_gray`
    counter = 0
    loop over vocab
    	check if word is NULL
    		use for loop to go through each letter in vocab
    			if letter == word, free word & add to counter
    return counter
## `filter_vocabulary_yellow`
    counter = 0
    loop over vocab
    	check if word is NULL
    		check if the letter is in the word[position]
    			free vocab
    		use for loop to go through each letter in vocab
    			if letter == word and position is the same, free word & add to counter
    return counter
## `filter_vocabulary_green`
    counter = 0 
    loop over vocab
    	check if word is NULL
    		if (letter is not in word[position])
    			free word & add to counter
    return counter

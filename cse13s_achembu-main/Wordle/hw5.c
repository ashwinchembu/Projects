#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Returns true if the guess is an exact match with the secret word, but
// more importantly, fills in the result with the following:
// - 'x' goes in a slot if the corresponding letter in the guess does not appear
//   anywhere in the secret word
// - 'y' goes in a slot if the corresponding letter in the guess appears in the
//   secret word, but not in the corresponding slot
// - 'g' goes in a slot if the corresponding letter in the guess appears in the
//   corresponding slot in the secret word.
//   You can assume that result points at enough memory for a string of length
//   5. (ie, at least 6 bytes long)
bool score_guess(char *secret, char *guess, char *result) {
  // TODO(you): finish this function
  //printf("%s",result);
  //printf("%d\n",strncmp(secret,guess,5));
for (int a = 0; a < 5;++a){
      result[a] =' ';
      }
//checks if guess is the same a secret
  if ((strncmp(secret,guess,5))==0){
      //printf("%i",strcmp(secret,guess));
      //printf("same word");
      for (int a = 0; a < 5;++a){
      result[a] ='g';
      }
      //printf("%s",result);
      return true;
  }
  //checks for multiple instance of letters
  else {
  int secret1[] = {secret[0],1000+secret[1],2000+secret[2],3000+secret[3],4000+secret[4]};
    int guess1[] = {guess[0],1000+guess[1],2000+guess[2],3000+guess[3],4000+guess[4]};
    for (int a = 0; a < 5;++a){
    	for (int b = 0; b < 5;++b){

    		if (secret[a] == secret[b] && secret1[a] != secret1[b]&&guess1[a] != guess1[b]){
    		//printf("multiple instances of %c found in secret\n", secret[b]);
    		//printf("changing value: %d to %d\n",secret1[b],secret1[a]);
    		secret1[a] = secret1[b];
    		b = 5;
    		}
    	}
    }
    //checks each letter induviduals and sets result
      for (int a = 0; a < 5;++a){
        bool inword = false;
        char s = guess[a];
        for (int b = 0; b < 5;++b){
            if ((secret[b]==s && a==b)||secret1[b] == guess1[a]){
                result[a] = 'g';
                inword = true;
                break;
            }
            else if (secret[b]==s && a!=b && secret1[b] != guess1[a] ){
            	//printf("%d and %d\n", secret1[b],guess1[a]);
                result[a] = 'y';
                inword = true;
                break;
            }
        if (!inword){
            result[a] = 'x';
        }
    }

        }
        
    }
  
  return false;
}
char **add2guesses(char **guesses, int num_guesses,char *guess){
  //creates new space for new guesses
    guesses  = realloc(guesses,(num_guesses)*sizeof(char*));
    //printf("%s",guesses[num_guesses-1]);
    //adds guess to array
    guesses[num_guesses-1] = strdup(guess);
    return guesses;
}

// Returns true if the specified guess is one of the strings in the vocabulary,
// and false otherwise. num_words is the length of the vocabulary.
// A simple linear scan over the strings in vocabulary is fine for our purposes,
// but consider: could you do this search more quickly?
bool valid_guess(char *guess, char **vocabulary, size_t num_words, char **guesses,int num_guesses,char *secret) {
  // TODO(you): finish this function
  //checks if its in vocab
  bool s = true;
  bool invocab = false;
  int words = num_words;
  for (int b = 0; b < words;++b){
      //printf("comparing: %s and %s",vocabulary[b],guess);
      //printf("%d",strcmp(vocabulary[b],guess));
      if (strncmp(vocabulary[b],guess,5)==0){
          //printf("%s",vocabulary[b]);
         //printf("in vocab\n");
          invocab = true;
          break;
      }
  }
  //checks with previous evidence
  if (num_guesses >= 1&&invocab){
      //printf("more than one guess and inside of vocabulary\n");
  s = true;
  for (int i = 0; i < num_guesses;++i){
    //printf("guesses[i] is: %s\n",guesses[i]);
    char result[6] = {0};
    s = score_guess(secret, guesses[i], result);
    for(int j = 0; j < 5;++j){
    	//printf("checking character of result: %c\n",result[j]);
    	//printf("comparing %c\n",guesses[i][j]);
    	if (result[j] == 'x'){	
    		for (int a = 0; a< 5;++a){
    			if (guesses[i][j] == guess[a]){
    			printf("you already guessed the letter %c (not in the word)\n",guess[a]);
    			return false;
    			}
    	}
    	
    	}
    	else if (result[j] == 'y'){
    		for (int a = 0; a< 5;++a){
    			if (guesses[i][j] == guess[a] && a==j){
    			printf("you already guessed the letter %c in the wrong spot\n",guess[a]);
    			return false;
    			}
    	}
    }
  }
  }
  }
  
  if (invocab){
      return true;
  }

 
  return false;
  
}

// Returns an array of strings (so, char **), where each string contains a word
// from the specified file. The file is assumed to contain 5-letter words, one
// per line.
// Also, this function sets the value pointed at by *num_words to be the number
// of words read.
// This will need to allocate enough memory to hold all of the char* pointers --
// so you will keep track of the size of your char** array and then use realloc
// to make the array larger over time, so that you have enough space for the
// dynamically-growing array of char *.
// Use fopen to open the input file for reading,
// strdup (or strndup) to make copies of each word read from that file, and
// fclose to close the file when you are done reading from it.
// Each element of the array should be a single five-letter word,
// null-terminated.
//adapted from Prof Rudnick's lectures
char **load_vocabulary(char *filename, size_t *num_words) {
  FILE* infile;
  char buf[7];
  char **out = (char**)malloc(sizeof(char*));
  int counter = 1;
  infile  =fopen(filename,"r");
  while(fgets(buf,7,infile) != NULL){
    //printf("%s" , buf);
    out[counter-1] = strdup(buf);
    out = realloc(out,(counter+1)*sizeof(char*));
    
    //printf("array word: %s array index: %d\n",out[counter-1],counter);
    counter+=1;
  }
    *num_words = counter-1;

  // TODO(you): finish this function
fclose(infile);
  return out;
}


// Free each of the strings in the vocabulary, as well as the pointer vocabulary
// itself (which points to an array of char *).
void free_vocabulary(char **vocabulary, size_t num_words) {
  // TODO(you): finish this function
  int words = num_words;
  for (int i =0;i<words;++i){
      free(vocabulary[i]);
  }
  free(vocabulary);
}


// Once your other functions are working, please revert your main() to its
// initial state, but please feel free to change it, during development. You'll
// want to test out each individual function!
int main(void) {
  char **vocabulary;
  size_t num_words;
  int num_guesses = 0;
  char **guesses = (char**)malloc(sizeof(char*));
  srand(time(NULL));

  // load up the vocabulary and store the number of words in it.
  vocabulary = load_vocabulary("vocabulary.txt", &num_words);
  //printf("%d",num_words);

  // Randomly select one of the words from the file to be today's SECRET WORD.
  int word_index = rand() % num_words;
  //int word_index = 121;
  char *secret = vocabulary[word_index];

  // input buffer -- we'll use this to get a guess from the user.
  char guess[80];

  // buffer for scoring each guess.
  char result[6] = {0};
  bool success = false;

  printf("time to guess a 5-letter word! (press ctrl-D to exit)\n");
  //printf("%s\n",secret);
  while (!success) {
    printf("guess: ");
    if (fgets(guess, 80, stdin) == NULL) {
      break;
    }
    // Whatever the user input, cut it off at 5 characters.
    guess[5] = '\0';

    if (!valid_guess(guess, vocabulary, num_words,guesses, num_guesses,secret)) {
      printf("not a valid guess\n");
      continue;
    } else {
        num_guesses++;
        //printf("adding 2 guesses: %s\n",guess);
        guesses = add2guesses(guesses,num_guesses,guess);
      
    }
    success = score_guess(secret, guess, result);
    printf("%s\n", guess);
    printf("result: %s\n", result);
  }

  if (success) {
    printf("you win, in %d guesses!\n", num_guesses);
  }
  free_vocabulary(vocabulary, num_words);
  for (int i =0;i<num_guesses;++i){
  free(guesses[i]);
  }
  free(guesses);
  

  return 0;
}




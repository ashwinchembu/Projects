#include "final.h"

#include <stdio.h>
#include <string.h>

// YOUR CODE GOES IN THIS FUNCTION!! Probably don't change the other ones.
WordCountTable *sum_word_count_tables(WordCountTable *table_a,
                                      WordCountTable *table_b) {

  // Your code here! You can change whatever you want in this function.
  // return an empty one just so we don't crash.

  WordCountTable *out = build_word_count_table(table_a->num_buckets);
  for(size_t i = 0; i<table_a->num_buckets;++i){
  WordCountNode *nodea= table_a->buckets[i];
  while(nodea != NULL){
  char* word = nodea->word;
  int count = nodea->count;
  //printf("%s count: %d",word,count);
  set_word_count(word, count, out);
  nodea = nodea->next;
  //printf("putting word: %s in bucket: %zu",word,i);
  }
  
  }
  WordCountTable *temp = build_word_count_table(out->num_buckets);
  for(size_t e = 0; e<out->num_buckets;++e){
  WordCountNode *nodet= out->buckets[e];
  while(nodet != NULL){
  char* word = nodet->word;
  int count = nodet->count;
  //printf("%s count: %d",word,count);
  set_word_count(word, count, temp);
  nodet = nodet->next;
  //printf("putting word: %s in bucket: %zu",word,e);
  }
  
  }
  out = temp;
  for(size_t j = 0; j<table_b->num_buckets;++j){
	  WordCountNode *nodeb = table_b->buckets[j];
	  while(nodeb!=NULL){
		  char* word = nodeb->word;
		  int count = nodeb->count;
		  int counto = get_word_count(word, out); 
	  	  if(counto == 0){
	  	  //printf("word: %s not found, adding to output\n",word);
	  	  set_word_count(word, count, out);
	  	  }
	  	  else{
	  	  //printf("word: %s is in output already\n",word);
	  	  size_t bucketo = hash(word) % out->num_buckets;
	  	  WordCountNode *nodeo = out->buckets[bucketo];
	  	  while(nodeo != NULL){
	  	  	//printf("looking for word: %s in bucket%zu\n",word, bucketo);
	  	  	if(strcmp(word,nodeo->word)==0){
	  	  	        //printf("%s count: %d",word,nodeo->count);
	  	  		//printf("found word: %s\n",word);
	  	  		nodeo->count +=count;
	  	  		printf("%d", nodeo->count);
	  	  	}
	  	  	//printf("word not in this node\n");
	  	  	nodeo = nodeo->next;
	  	  }
	  	  //printf("going to next word\n");
	  	  	  	  
	  	  }
	  	  nodeb = nodeb->next;
	  
	  }
  }
  
  return out;
}

//// more functions, table infrastructure. Please don't change these.

// Thank you Dan Bernstein.
unsigned long hash(char *str) {
  unsigned long hash = 5381;
  int c;

  while (*str != '\0') {
    c = *str;
    hash = ((hash << 5) + hash) + (unsigned char)c; /* hash * 33 + c */
    str++;
  }
  return hash;
}

WordCountNode *set_word_count_in_list(char *word, int count,
                                      WordCountNode *bucket) {
  WordCountNode *new_node;

  new_node = malloc(sizeof(WordCountNode));
  new_node->word = strdup(word);
  new_node->count = count;
  new_node->next = bucket;
  return new_node;
}

void set_word_count(char *word, int count, WordCountTable *table) {
  size_t which_bucket = hash(word) % table->num_buckets;

  // We're going to "overwrite" the previous value here (if it exists) by simply
  // putting a new value at the front of the linked list in the appropriate
  // bucket. This is faster and simpler, but will use more memory.
  table->buckets[which_bucket] =
      set_word_count_in_list(word, count, table->buckets[which_bucket]);
}

// Construct an empty WordCountTable.
WordCountTable *build_word_count_table(size_t num_buckets) {
  WordCountTable *out;

  out = calloc(1, sizeof(WordCountTable));
  out->num_buckets = num_buckets;

  // bunch of NULL pointers to WordCountNode.
  out->buckets = calloc(num_buckets, sizeof(WordCountNode *));
  return out;
}

int get_word_count_in_list(char *word, WordCountNode *node) {
  if (node == NULL) {
    return 0;
  }

  if (strcmp(word, node->word) == 0) {
    return node->count;
  }
  return get_word_count_in_list(word, node->next);
}

int get_word_count(char *word, WordCountTable *table) {
  size_t which_bucket = hash(word) % table->num_buckets;

  return get_word_count_in_list(word, table->buckets[which_bucket]);
}

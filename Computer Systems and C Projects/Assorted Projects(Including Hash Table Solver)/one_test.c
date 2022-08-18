#include "final.h"

#include <stdio.h>
#include <stdlib.h>

void try_word_count(char *text, size_t desired) {
  size_t num_words = word_count(text);
  printf("counting words in: %s\n", text);
  printf("%s: wanted %lu, got %lu\n",
         (num_words == desired) ? "SUCCESS" : "FAILURE", desired, num_words);
}

int main(void) {

  try_word_count("", 0);
  try_word_count("good afternoon", 2);
  try_word_count("hello to...   ... all of my friends!", 6);
  try_word_count("Rudnick's class",3);
  try_word_count("ih gao7idfhiauodsfasd\ngsfd",4);
  try_word_count(" bob\0 chicken ",1);
  return 0;
}

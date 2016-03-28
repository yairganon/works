/* $Id: count-words.c 858 2010-02-21 10:26:22Z tolpin $ */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* return string "word" if the count is 1 or "words" otherwise */
char *words(int count) {
  char *word = (char*)malloc(5+1);
  strcpy(word ,"words");
  if(count==1) 
    word[strlen(word)-1] = '\0';
  return word;
}

/* print a message reportint the number of words */
int print_word_count(char **argv) {
  int count = 0;
  char **a = argv;
  while(*(a++))
    ++count;
  char *word = words(count);
  printf("The sentence contains %d %s.\n", count, word);
  free(word);
  return count;
}

/* print the number of words in the command line and return the number as the exit code */
int main(int argc, char **argv) {
  return print_word_count(argv+1);
}

   

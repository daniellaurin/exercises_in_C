/* Function SmashSentence(words_array):
    Initialize empty_result_string

    For each word in words_array:
        If result_string is not empty:
            Add a space to result_string
        Add current word to result_string

    Return result_string

Main:
    words = ["hello", "world", "this", "is", "great"]
    sentence = SmashSentence(words)
    Print sentence

   This pseudocode outlines the basic steps:

1. Create a function that takes an array of words as input.
2. Initialize an empty result string.
3. Iterate through each word in the input array.
4. If the result string isn't empty (i.e., it's not the first word), add a space
before adding the new word.
5. Add the current word to the result string.
6. After processing all words, return the result string.
7. In the main program, create an array of words and call the function with this
array.
8. Print the resulting sentence.
    */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *smash(const char *const *words, size_t count) {
  int letterCount = 0;

  // finds how many words
  for (int i = 0; i < count; i++) {
    const char *word = words[i];
    letterCount += strlen(word);
  }

  // alocates spaces for it
  int responseLength = letterCount + count;
  char *response = malloc(responseLength * sizeof(char));
}

int main() {
  const char *words[] = {"hello", "world", "this", "is", "great"};

  size_t count = sizeof(words) / sizeof(words[0]);

  char *result = smash(words, count);

  printf("Smashed string: %s\n", result);
}
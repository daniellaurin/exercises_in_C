/* Sentence Smash

Write a function that takes an array of words and smashes them together into a
sentence and returns the sentence. You can ignore any need to sanitize words or
add punctuation, but you should add spaces between each word. Be careful, there
shouldn't be a space at the beginning or the end of the sentence!

Example
['hello', 'world', 'this', 'is', 'great']  =>  'hello world this is great'
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *smash(const char *const *words, size_t count) {
  // Initialize a counter for the total number of letters
  int letterCount = 0;

  // Loop through each word to count total letters
  for (int x = 0; x < count; x++) {
    const char *word = words[x]; // Get the current word
    letterCount += strlen(word); // Add the length of the current word
  }

  // Calculate total response length (letters + spaces + null terminator)
  int responseLength = letterCount + count;

  // Allocate memory for the response string
  char *response = malloc(responseLength * sizeof(char));

  // Loop to construct the response string
  for (int x = 0, r = 0; x < count; x++) {
    const char *word = words[x];   // Get the current word
    int wordLength = strlen(word); // Get the length of the current word

    // Copy each character of the current word to the response
    for (int y = 0; y < wordLength; y++, r++) {
      response[r] = word[y];
    }

    response[r++] = ' '; // Add a space after each word
  }

  // Replace the last space with a null terminator
  response[responseLength - 1] = '\0';

  // Return the constructed string
  return response;
}

int main() {
  // Initialize an array of words
  const char *words[] = {"hello", "world", "this", "is", "great"};

  // Calculate the number of words in the array
  size_t count = sizeof(words) / sizeof(words[0]);

  // Call the smash function to combine the words
  char *result = smash(words, count);

  // Check if smash was successful
  if (result) {
    // Print the result
    printf("Smashed string: %s\n", result);
    free(result); // Free the allocated memory
  } else {
    // Print an error message if smash failed
    printf("Failed to smash the words.\n");
  }

  return 0; // End the program
}
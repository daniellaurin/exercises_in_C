/*Rule 1: If a word begins with a vowel sound, add an "ay" sound to the end of
 the word (e.g. "apple" -> "appleay"). Please note that "xr" and "yt" at the
 beginning of a word make vowel sounds (e.g. "xray" -> "xrayay", "yttria" ->
 "yttriaay"). X

 Rule 2: If a word begins with a consonant sound, move it to the
 end of the word and then add an "ay" sound to the end of the word (e.g. "pig"
 -> "igpay"). Consonant sounds can be made up of multiple consonants, such as
 the "ch" in "chair" or "st" in "stand" (e.g. "chair" -> "airchay"). X

 Rule 3: If
 a word starts with a consonant sound followed by "qu", move them to the end of
 the word, and then add an "ay" sound to the end of the word (e.g. "square" ->
 "aresquay").

 Rule 4: If a word contains a "y" after a consonant cluster or as
 the second letter in a two letter word it makes a vowel sound (e.g. "rhythm" ->
 "ythmrhay", "my" -> "ymay").*/

#include <stdbool.h>
#include <stdio.h>

static bool is_vowel(char c) {

  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
}

int main(void) {
  char word[100];
  char pig_latin[100];

  printf("Enter a word: ");
  scanf("%s", word);

  if (is_vowel(word[0])) {

    printf("%s-ay", word);

    return 0;
  }

  if ((is_vowel(word[0]) && (word[1])) == false) {

    pig_latin[0] = word[0];
    pig_latin[1] = word[1];

    char *new_word = word + 2;
    printf("%s-%say\n", new_word, pig_latin);

    return 0;
  }
  // Add step 3 and step 4 using the is_vowel statement

  else {

    pig_latin[0] = word[0];
    char *new_word = word + 1;
    printf("%s-%cay", new_word, *pig_latin);

    return 0;
  }
}

//   if ((word[0] == 'a') || (word[0] == 'e') || (word[0] == 'i') ||
//       (word[0] == 'o') || (word[0] == 'u') || (word[0] == 'y') ||
//       (word[0] == 'x' && word[1] == 'r') ||
//       (word[0] == 'y' && word[1] == 't')) {

//     printf("%s-ay", word);

//     return 0;
//   }
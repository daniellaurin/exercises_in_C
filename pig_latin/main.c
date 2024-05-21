/*Rule 1: If a word begins with a vowel sound, add an "ay" sound to the end of
 the word (e.g. "apple" -> "appleay"). Please note that "xr" and "yt" at the
 beginning of a word make vowel sounds (e.g. "xray" -> "xrayay", "yttria" ->
 "yttriaay"). X

 Rule 2: If a word begins with a consonant sound, move it to the
 end of the word and then add an "ay" sound to the end of the word (e.g. "pig"
 -> "igpay"). Consonant sounds can be made up of multiple consonants, such as
 the "ch" in "chair" or "st" in "stand" (e.g. "chair" -> "airchay"). X

 Rule 3: If a word starts with a consonant sound followed by "qu", move them to
 the end of the word, and then add an "ay" sound to the end of the word (e.g.
 "square" -> "aresquay"). X

 Rule 4: If a word contains a "y" after a consonant cluster or as
 the second letter in a two letter word it makes a vowel sound (e.g. "rhythm" ->
 "ythmrhay", "my" -> "ymay").*/

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

static bool is_vowel(char c) {

  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
}

int main(void) {
  char word[100];
  char pig_latin[100];
  int cluster;

  printf("Enter a word: ");
  scanf("%s", word);

  int len = strlen(word);

  for (int i = 0; i < len; i++) {
    if (is_vowel(word[i]) == false) {
      cluster++;
    }
  }
  cluster += 1;

  if (word[0] == 'y') {
    printf("%s%cay\n", word + 1, word[0]);

    return 0;
  }

  // Rule 1:
  if ((is_vowel(word[0])) || (word[0] == 'x' && word[1] == 'r') ||
      (word[0] == 'y' && word[1] == 't')) {

    printf("%say\n", word);

    return 0;
  }

  // // Rule 3:
  if ((is_vowel(word[0]) == false) && (word[1] == 'q') && (word[2] == 'u')) {

    pig_latin[0] = word[0];
    char *new_word = word + 3;

    printf("%s%cquay\n", new_word, *pig_latin);

    return 0;
  }

  // Rule 4:
  if ((cluster >= 2) && (word[cluster - 1] == 'y')) {

    char last = word[len - 1];
    word[len - 1] = '\0';

    printf("%c%say\n", last, word);

    return 0;
  }

  // Rule 2: This is problematic
  if ((is_vowel(word[0]) == false) && (is_vowel(word[1]) == false)) {
    pig_latin[0] = word[0];
    pig_latin[1] = word[1];

    char *new_word = word + 2;
    printf("%s%say\n", new_word, pig_latin);

    return 0;
  }

  // // Rule 4:
  if ((len == 2) && (word[1] == 'y')) {

    printf("%s%cay\n", word + 1, word[0]);

    return 0;
  }

  // // Rule 2:
  else {

    char *new_word = word + 1;
    printf("%s%cay\n", new_word, word[0]);

    return 0;
  }
}
/*
"apple" -> "appleay"
"xray" -> "xrayay"
"yttria" -> "yttriaay"
"pig" -> "igpay"
"chair" -> "airchay"
"square" -> "aresquay"
"rhythm" -> "ythmrhay"
"my" -> "ymay"
"thyme" ->  ymethay
"flly" --> "yfllay"
*/
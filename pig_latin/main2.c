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

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// finds if it a vowel
static bool is_vowel(int c) {

  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

// finds if its a consonent by chekcing if it matches to is_vowel function
static bool is_consonent(int c) { return isalpha(c) && !is_vowel(c); }

// this checks the first character of the word to check if it meets these
// criteria
static bool is_vowel_sound(char const *p) {

  return (p[0] == 'x' && p[1] == 'r') || (p[0] == 'y' && p[1] == 't');
}

static int find_consonents(char const *p) {

  if (p[0] == 'q' && p[1] == 'u') {

    return 2;
  }

  if (is_consonent(p[0]) && p[1] == 'q' && p[2] == 'u') {

    /* rule 3 */

    return 3;
  }

  int cnt = 1;

  p++;

  while (is_consonent(*p) && *p != 'y') {

    cnt++;

    p++;
  }

  return cnt;
}
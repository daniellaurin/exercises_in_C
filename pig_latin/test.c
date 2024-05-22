
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include <ctype.h>

static bool isVowel(int c) {

  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

static bool isConsonent(int c) { return isalpha(c) && !isVowel(c); }

static bool isVowelSound(char const *p) {

  return (p[0] == 'x' && p[1] == 'r')

         || (p[0] == 'y' && p[1] == 't');
}

static int findConsonents(char const *p) {

  if (p[0] == 'q' && p[1] == 'u') {

    return 2;
  }

  if (isConsonent(p[0]) && p[1] == 'q' && p[2] == 'u') {

    /* rule 3 */

    return 3;
  }

  int cnt = 1;

  p++;

  while (isConsonent(*p) && *p != 'y') {

    cnt++;

    p++;
  }

  return cnt;
}

char *translate(const char *phrase) {

  char *result = malloc(30); /* realloc later */

  char *q = result;

  const char *p = phrase;

  while (*p) {

    if (isalpha(*p)) {

      if (isVowel(*p) || isVowelSound(p)) {

        /* rule 1 */

        while (isalpha(*p))
          *q++ = *p++;

        *q++ = 'a';
        *q++ = 'y';

      } else {

        /* rule 2, 3, 4 */

        int len = findConsonents(p);

        char const *pc = p;

        p += len;

        while (isalpha(*p))
          *q++ = *p++;

        while (len > 0) {
          *q++ = *pc++;
          len--;
        }

        *q++ = 'a';
        *q++ = 'y';
      }

    } else {

      while (isspace(*p))
        *q++ = *p++;
    }
  }

  *q = '\0';

  return result;
}

int main(int argc, char *argv[]) {
  // Check if a phrase was passed as a command-line argument
  if (argc < 2) {
    printf("Usage: %s <phrase>\n", argv[0]);
    return 1; // Exit with error code
  }

  // Translate the phrase
  char *translatedPhrase = translate(argv[1]);

  // Print the translated phrase
  printf("%s\n", translatedPhrase);

  // Free the allocated memory
  free(translatedPhrase);

  return 0; // Successful execution
}
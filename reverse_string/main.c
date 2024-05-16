// Reverse a String - Enter a string and the program will reverse it and print
// it out.
//  doing it without string.h library

#include <stdio.h>

int main(void) {

  char str[30];
  int i, rStr, leng = -1;

  printf("Enter String: ");
  fgets(str, 30, stdin);

  for (i = 0; str[i] != '\0'; i++) {
    leng++;
  }

  for (; leng >= 0; leng--) {
    rStr = str[leng];
    printf("%c", rStr);
  }

  return 0;
}
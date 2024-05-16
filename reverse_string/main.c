// Reverse a String - Enter a string and the program will reverse it and print
// it out.
//  doing it without string.h library

#include <stdio.h>

int main(void) {

  char str[100];
  int i, leng;

  printf("Enter String: ");
  fgets(str, 30, stdin);

  for (i = 0; str[i] != '\0'; i++) {
    leng++;
  }

  for (; leng >= 0; leng--) {
    printf("%c", str[leng]);
  }

  return 0;
}
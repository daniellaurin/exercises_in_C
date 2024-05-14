#include <stdio.h>
// Fizz Buzz - Write a program that prints the numbers from 1 to 100. But for
// multiples of three print “Fizz” instead of the number and for the multiples
// of five print “Buzz”. For numbers which are multiples of both three and five
// print “FizzBuzz”.

int main(void) {
  int i;

  for (i = 1; i <= 100; i++) {

    if (i % 3 == 0)
      printf("Fizz");

    if (i % 5 == 0)
      printf("Buzz");
    // I guess this is a necessary operation in C? else statement is not enough
    // for the correct output
    else if (i % 3 != 0 && i % 5 != 0)
      printf("%d", i);

    printf("\n");
  }
  return 0;
}

#include <stdio.h>

// The Fibonacci sequence is a sequence where the next term is the sum of the
// previous two terms.
//  The first two terms of the Fibonacci sequence are 0 followed by 1.
// take input and generate a Fibonacci sequence to the Nth number
// example output:  0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144

int main(void) {
  int n, i;
  int t1 = 0, t2 = 1;
  int temp;

  printf("enter number to generate a Fibonacci sequence: ");
  scanf("%d", &n);

  for (i = 0; i <= n; i++) {
    printf("%d\n", t1);
    temp = t1 + t2;
    t1 = t2;
    t2 = temp;
  }
  return 0;
}

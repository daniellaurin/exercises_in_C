#include <stdio.h>

int main() {
  int num, temp;
  char calc;

  do {
    printf("input number: ");
    scanf("num1=%d, calc=%c", &num, &calc);

    switch (calc) {
    case '+':
      temp = temp + num;
      break;
    case '-':
      temp = temp - num;
      break;
    case '/':
      temp = temp / num;
      break;
    case '*':
      temp = temp * num;
      break;
    }

    printf("your number is %d\n", temp);

  } while (num != EOF);

  return 0;
}

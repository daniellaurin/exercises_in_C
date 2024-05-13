#include <stdio.h>

int main() {
  int num1, num2, temp;
  char opp, continue_calc;

  do {
    printf("input num, opp, num: ");
    if (scanf("%d %c %d", &num1, &opp, &num2) != 3) {
      printf("Error Invalid input.\n");
    } else {
      switch (opp) {
      case '+':
        temp = num1 + num2;
        break;
      case '-':
        temp = num1 - num2;
        break;
      case '/':
        temp = num1 / num2;
        break;
      case '*':
        temp = num1 * num2;
        break;
      default:
        printf("Error operator is not correct\n");
        continue;
      }
      printf("%d %c %d = %d\n", num1, opp, num2, temp);

      printf("Do you wnat to continue? (y/n): ");
      scanf(" %c", &continue_calc);
      getchar();
    }
  } while (continue_calc == 'y' || continue_calc == 'Y');

  return 0;
}

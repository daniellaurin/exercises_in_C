#include <stdbool.h>
#include <stdio.h>

int main() {

  const int class_points[] = {50, 75, 90, 30, 40, 55};
  const int class_size = 7;
  const int your_points = 90;

  int i;
  int classSum = 0;

  for (i = 0; i < class_size; i++) {
    classSum += class_points[i];
  }

  int average = (classSum + your_points) / (class_size + 1);

  bool answer = your_points > average;

  printf("%s", answer ? "true" : "false");

  return answer;
}

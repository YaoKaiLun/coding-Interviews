#include <stdio.h>

int jumpFloor(int number) {
  if (number == 0) return 0;
  int first = 1;
  if (number == 1) return first;
  int second = 2;
  if (number == 2) return second;
  int result;
  for (int i = 3; i <= number; i++) {
    result = first + second;
    first = second;
    second = result;
  }
  return result;
}

int main(int argv, char *argc[]) {
  printf("%d", jumpFloor(3));
}
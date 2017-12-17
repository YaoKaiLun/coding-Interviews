#include <stdio.h>

int Fibonacci(int n) {
  int first = 0;
  if (n == 0) return first;
  int second = 1;
  if (n == 1) return second;
  int result;
  for (int i = 2; i <= n; i++) {
    result = first + second;
    first = second;
    second = result;
  }
  return result;
}

int main(int argv, char *argc[]) {
  printf("%d", Fibonacci(3));
}
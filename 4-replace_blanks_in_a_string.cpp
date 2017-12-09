#include <stdio.h>
#include <string.h>

void replaceSpace(char *str, int length) {
  int spaceAmount = 0;
  for(int i = 0; i < length; i++) {
    if(str[i] == ' ') {
      spaceAmount++;
    }
  }
  int newLength = length + spaceAmount * 2;
  int pointer = newLength - 1;
  for(int i = length - 1; i >= 0 ; i--) {
    if(str[i] != ' ') {
      str[pointer--] = str[i];
    } else {
      str[pointer--] = '0';
      str[pointer--] = '2';
      str[pointer--] = '%';
    }
  }
}

int main(int argv, char *argc[]) {
  char str[1000] = " We are happy. ";
  printf("before: %s\n", str);
  replaceSpace(str, strlen(str));
  printf("after: %s\n", str);
}
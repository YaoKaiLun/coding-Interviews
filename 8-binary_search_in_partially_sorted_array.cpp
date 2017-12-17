#include <stdio.h>
#include <vector>
using namespace std;

int ordinaryMethodFindMinNumber(vector<int> rotateArray) {
  int min = rotateArray[0];
  for(int i = 1; i < rotateArray.size(); i++) {
    if(min > rotateArray[i]) {
      min = rotateArray[i];
    }
  }
  return min;
}

int minNumberInRotateArray(vector<int> rotateArray) {
  if (rotateArray.size() == 0) {
    return 0;
  }

  int left = 0;
  int right = rotateArray.size() - 1;
  // 不旋转
  if (rotateArray[left] < rotateArray[right]) {
    return rotateArray[left];
  }

  int mid = 0;
  while(right - left > 1) {
    mid = (left + right) / 2;

    //eg. [1, 0, 1, 1, 1] and [1, 1, 1, 0, 1]
    if(rotateArray[left] == rotateArray[right] && rotateArray[left] == rotateArray[mid]) {
      return ordinaryMethodFindMinNumber(rotateArray);
    }

    if(rotateArray[mid] > rotateArray[left]) {
      left = mid;
    } else {
      right = mid;
    }
  }
  return rotateArray[right];
}

int main(int argv, char *argc[]) {
  vector<int> rotateArray;
  rotateArray.push_back(3);
  rotateArray.push_back(4);
  rotateArray.push_back(5);
  rotateArray.push_back(1);
  rotateArray.push_back(2);
  int min = minNumberInRotateArray(rotateArray);
  printf("min: %d \n", min);
}
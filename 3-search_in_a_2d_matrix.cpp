#include <vector>

using namespace std;

bool find(int target, vector<vector<int> > array) {
  int rowCount = (int)array.size();
  int columnCount = (int)array[0].size();
  int row = 0;
  int column = columnCount - 1;

  while(column >= 0 && row  < rowCount) {
    if (array[row][column] > target) {
      column--;
    } else if (array[row][column] == target) {
      return true;
    } else if (array[row][column] < target) {
      row++;
    }
  }
  return false;
}

int main(int argv, char *argc[]) {
  int target = 10;
  vector<vector<int> > array(3, vector<int>(3));
  array[0][0] = 2;
  array[0][1] = 4;
  array[0][2] = 6;
  array[1][0] = 3;
  array[1][1] = 5;
  array[1][2] = 7;
  array[2][0] = 4;
  array[2][1] = 6;
  array[2][2] = 10;

  bool result = find(target, array);
  printf("result: %d", result);
}
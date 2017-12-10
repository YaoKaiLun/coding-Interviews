#include<stdio.h>
#include<vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
  if(pre.size() == 0) return NULL;

  TreeNode *node = new TreeNode(pre[0]);

  vector<int>::iterator index = find(vin.begin(), vin.end(), pre[0]);

  if(index != vin.begin()) {
    vector<int> leftPre = vector<int>(pre.begin() + 1, index - vin.begin() + pre.begin() + 1);
    vector<int> leftVin = vector<int>(vin.begin(), index);
    node->left = reConstructBinaryTree(leftPre, leftVin);
  }

  if(index + 1 != vin.end()) {
    vector<int> rightPre = vector<int>(index - vin.begin() + pre.begin() + 1, pre.end());
    vector<int> rightVin = vector<int>(index + 1, vin.end());
    node->right = reConstructBinaryTree(rightPre, rightVin);
  }

  return node;
}

int main(int argv, char *argc[]) {
  vector<int> preOrder;
  preOrder.push_back(1);
  preOrder.push_back(2);
  preOrder.push_back(4);
  preOrder.push_back(7);
  preOrder.push_back(3);
  preOrder.push_back(5);
  preOrder.push_back(6);
  preOrder.push_back(8);
  vector<int> inOrder;
  inOrder.push_back(4);
  inOrder.push_back(7);
  inOrder.push_back(2);
  inOrder.push_back(1);
  inOrder.push_back(5);
  inOrder.push_back(3);
  inOrder.push_back(8);
  inOrder.push_back(6);
  TreeNode *head = reConstructBinaryTree(preOrder, inOrder);
  printf("left: %d\n", head->left->left->right->val);
  printf("right: %d\n", head->right->right->val);
}

#include <stdio.h>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  struct ListNode *next;
};

/* recursive function */
// vector<int> printListFromTailToHead(ListNode* head) {
//   vector<int> result;
//   if (head->next != NULL) {
//     result = printListFromTailToHead(head->next);
//   }
//   result.push_back(head->val);
//   return result;
// }

vector<int> printListFromTailToHead(ListNode* head) {
  vector<int> result;

  ListNode *temp = head;
  while(temp != NULL) {
    result.push_back(temp->val);
    temp = temp->next;
  }

  return vector<int>(result.rbegin(), result.rend());
}

void printVector(vector<int> result) {
  for (vector<int>::iterator it = result.begin() ; it != result.end(); ++it) {
    printf("%d ", *it);
  }
}

int main(int argv, char *argc[]) {
  ListNode* head = new ListNode();
  head->val = 0;
  ListNode* node1 = new ListNode();
  node1->val = 1;
  ListNode* node2 = new ListNode();
  node2->val = 2;
  ListNode* node3 = new ListNode();
  node3->val = 3;
  head->next = node1;
  node1->next = node2;
  node2->next = node3;
  node3->next = NULL;

  vector<int> result = printListFromTailToHead(head);
  printVector(result);
}
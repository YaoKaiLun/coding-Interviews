#include<stdio.h>
#include<stack>

using namespace std;

class Queue {
public:
    void push(int node) {
      stack1.push(node);
    }

    int pop() {
      if(stack2.empty()) {
        while(!stack1.empty()) {
          stack2.push(stack1.top());
          stack1.pop();
        }
      }

      int node = stack2.top();
      stack2.pop();
      return node;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

int main(int argv, char *argc[]) {
  Queue *queue = new Queue();
  queue->push(1);
  queue->push(2);
  queue->push(3);
  printf("%d ",  queue->pop());
  printf("%d ",  queue->pop());
  printf("%d ",  queue->pop());
}
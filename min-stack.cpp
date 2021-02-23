#include<cmath>
using namespace std;

class MinStack {
public:
	/** initialize your data structure here. */
	struct minStack
	{
		int data;
		minStack* next;
	};
	minStack* head;
	minStack* topStack;
	minStack* pre, *now;
	int mintemp;
	int numOfStack = 0;
	
	MinStack() {
		head = new minStack;
		head->next = nullptr;
	}
	~MinStack()
	{
		delete head;
	}
	void push(int x) {
		topStack = new minStack;
		topStack->data = x;
		topStack->next = head->next;
		head->next = topStack;
		numOfStack++;
	}

	void pop() {
		topStack = head->next;
		head->next = topStack->next;
		delete topStack;
		topStack = head->next;
		numOfStack--;
	}

	int top() {
		topStack = head->next;
		return topStack->data;
	}

	int getMin() {
		mintemp = INT_MAX;
		pre = head;
		for (int i = 0; i < numOfStack; i++) {
			now = pre->next;
			if (now->data < mintemp) {
				mintemp = now->data;
			}
			pre = now;
		}
		return mintemp;
	}
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
int main() {
	MinStack* obj = new MinStack();
	obj->push(-2);
	obj->push(0);
	obj->push(-3);
	int param_1 = obj->getMin();
	obj->pop();
	int param_3 = obj->top();
	int param_4 = obj->getMin();
}
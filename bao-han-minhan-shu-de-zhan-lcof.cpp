#include"headfile.h"
using namespace std;

class MinStack {
public:
	/** initialize your data structure here. */
	stack<int> mStack;
	stack<int> minStack;
	MinStack() {

	}

	void push(int x) {
		mStack.push(x);
		if (minStack.empty() || x <= minStack.top()) {
			minStack.push(x);
		}
	}

	void pop() {
		if (mStack.top() == minStack.top()) {
			minStack.pop();
		}
		mStack.pop();
	}

	int top() {
		return mStack.top();
	}

	int min() {
		return minStack.top();
	}
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */
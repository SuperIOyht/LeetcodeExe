#include"headfile.h"
using namespace std;

class MyQueue {
public:
	stack<int> my_stack1, my_stack2;
	int size;
	/** Initialize your data structure here. */
	MyQueue() {
		size = 0;
	}

	/** Push element x to the back of queue. */
	void push(int x) {
		size++;
		while (!my_stack1.empty())
		{
			my_stack2.push(my_stack1.top());
			my_stack1.pop();
		}
		my_stack1.push(x);
		while (!my_stack2.empty())
		{
			my_stack1.push(my_stack2.top());
			my_stack2.pop();
		}
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		int temp = my_stack1.top();
		my_stack1.pop();
		return temp;
	}

	/** Get the front element. */
	int peek() {
		return my_stack1.top();
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		return my_stack1.empty();
	}
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
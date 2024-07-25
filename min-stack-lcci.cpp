#include"headfile.h"
using namespace std;

	class MinStack {
	public:
		/** initialize your data structure here. */
		stack<int> my_stack;
		stack<int> temp_stack;
		MinStack() {
			temp_stack.push(INT_MAX);
		}

		void push(int x) {
			my_stack.push(x);
			temp_stack.push(min(x, temp_stack.top()));
		}

		void pop() {
			my_stack.pop();
			temp_stack.pop();
		}

		int top() {
			return my_stack.top();
		}

		int getMin() {
			return temp_stack.top();
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


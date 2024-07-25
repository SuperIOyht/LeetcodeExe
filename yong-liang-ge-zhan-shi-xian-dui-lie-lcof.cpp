#include"headfile.h"
using namespace std;

class CQueue {
public:
	stack<int> real;
	stack<int> temp;
	CQueue() {
		real = stack<int>();
		temp = stack<int>();
	}

	void appendTail(int value) {
		real.push(value);
	}

	int deleteHead() {
		int n = real.size();
		if (n == 0) {
			return -1;
		}
		for (int i = 0; i < n - 1; i++)
		{
			int temp_num = real.top();
			temp.push(temp_num);
			real.pop();
		}
		int return_num = real.top();
		real.pop();
		int m = temp.size();
		for (int i = 0; i < m; i++) {
			int temp_num = temp.top();
			temp.pop();
			real.push(temp_num);
		}
		return return_num;
	}
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */

int main() {
	CQueue* obj = new CQueue();
	obj->appendTail(2);
	int param_2 = obj->deleteHead();
}
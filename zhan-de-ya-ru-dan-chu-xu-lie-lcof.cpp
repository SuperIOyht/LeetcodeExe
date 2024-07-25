#include"headfile.h"
using namespace std;

class Solution {
public:
	bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
		stack<int> myStack;
		int point = 0;
		for (int i = 0; i < pushed.size(); ++i) {
			myStack.push(pushed[i]);
			while (!myStack.empty() && myStack.top() == popped[point])
			{
				myStack.pop();
				++point;
			}
		}
		return myStack.empty();
	}
};


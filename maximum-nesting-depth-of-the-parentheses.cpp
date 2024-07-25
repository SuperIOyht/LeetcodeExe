#include"headfile.h"
using namespace std;

class Solution {
public:
	int maxDepth(string s) {
		int max = 0;
		stack<char> mystack;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(') {
				mystack.push('(');
				max = max > mystack.size() ? max: mystack.size();
			}
			else if (s[i] == ')') {
				mystack.pop();
			}
		}
		return max;
	}
};
#include<stack>
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
	bool isValid(string s) {
		stack<char> stack1;
		unordered_map<char, char> a = {
			{'}','{'},{']','['},{')','('}
		};
		for (int i = 0; i < s.size(); i++) {
			if (a.count(s[i])) {
				if (stack1.empty() || stack1.top() != a[s[i]]) {
					return false;
				}
				stack1.pop();
			}
			else
			{
				stack1.push(s[i]);
			}
		}
		return stack1.empty();
	}
};
int main() {
	Solution s;
	s.isValid("()");
	return 0;
}
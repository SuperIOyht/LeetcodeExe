#include<iostream>
#include<stack>
#include<string>
using namespace std;

class Solution {
public:
	int calculate(string s) {
		stack<int> ns;
		char preS = '+';
		int num = 0,temp=0,ans=0;
		for (int i = 0; i < s.size(); i++) {
			if (isdigit(s[i])) {
				num = num * 10 + (s[i] - '0');
			}
			if ((!isdigit(s[i]) && s[i] != ' ') || i == s.size()-1) {
				switch (preS)
				{
				case ('+'):
					ns.push(+num);
					break;
				case ('-'):
					ns.push(-num);
					break;
				case ('*'):
					temp = ns.top();
					ns.pop();
					ns.push(temp*num);
					break;
				case('/'):
					temp = ns.top();
					ns.pop();
					ns.push(temp / num);
				}
				num = 0;
				preS = s[i];
			}
		}
		while (!ns.empty()) {
			ans += ns.top();
			ns.pop();
		}
		return ans;
	}
};
int main() {
	Solution s;
	s.calculate("32");
	return 0;
}
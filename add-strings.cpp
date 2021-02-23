#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	string addStrings(string num1, string num2) {
		string ans;
		int cur = 0, i = num1.size() - 1, j = num2.size() - 1;
		while (i >= 0 || j >= 0 || cur > 0) {
			if (i >= 0) {
				cur += num1[i--] - '0';
			}
			if (j >= 0) {
				cur += num2[j--] - '0';
			}
			ans += to_string(cur % 10);
			cur /= 10;
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}
};
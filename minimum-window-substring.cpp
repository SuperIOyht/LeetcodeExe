//给你一个字符串 S、一个字符串 T，请在字符串 S 里面找出：包含 T 所有字符的最小子串。
//
//示例：
//
//输入 : S = "ADOBECODEBANC", T = "ABC"
//	输出 : "BANC"
//	说明：
//
//	如果 S 中不存这样的子串，则返回空字符串 ""。
//	如果 S 中存在这样的子串，我们保证它是唯一的答案。
//
//	来源：力扣（LeetCode）
//	链接：https ://leetcode-cn.com/problems/minimum-window-substring
#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	string minWindow(string s, string t) {
		int longLength = s.size();
		string boolString;
		string* hashArray = new string[longLength]();
		int minLengh = INT_MAX;
		int ansbegin = 0;
		for (int i = 0; i < longLength; i++) {
			if (t.find(s[i]) != t.npos) {
				hashArray[i] = s[i];
			}
		}
		for (int begin = 0; begin < longLength; begin++) {
			if (hashArray[begin] != "") {
				boolString = t;
				for (int end = begin; end < longLength; end++) {
					if (hashArray[end] != "") {
						if (boolString.find(hashArray[end]) != boolString.npos) {
							boolString.erase(boolString.find(hashArray[end]), 1);
						}
						if (boolString.empty()) {
							if (end - begin + 1 < minLengh) {
								minLengh = end - begin + 1;
								ansbegin = begin;
							}
							break;
						}
					}
				}
			}
		}
		if (minLengh == INT_MAX) {
			return "";
		}
		else
		{
			return s.substr(ansbegin, minLengh);
		}
	
	}
};
int main() {
	Solution a;
	cout << a.minWindow("A", "BA");
	system("pause");
	return 0;
}
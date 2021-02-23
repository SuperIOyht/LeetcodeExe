//给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
//
//示例 1：
//
//输入 : "babad"
//	输出 : "bab"
//	注意 : "aba" 也是一个有效答案。
//	示例 2：
//
//	输入 : "cbbd"
//	输出 : "bb"
//
//	来源：力扣（LeetCode）
//	链接：https ://leetcode-cn.com/problems/longest-palindromic-substring

#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
	string longestPalindrome(string s) {
		int n = s.size();
		int maxSize = 0;
		int begin = 0;
		vector<vector<bool>> dp(n, vector<bool>(n));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= i; j++) {
				if (s[i] != s[j]) {
					dp[j][i] = false;
				}
				else {
					if ((i - 1) - (j + 1) + 1 < 2) {
						dp[j][i] = true;
					}
					else
					{
						dp[j][i] = dp[j + 1][i - 1];
					}
				}
				if (dp[j][i] && i - j + 1 > maxSize) {
					maxSize = i - j + 1;
					begin = j;
				}
			}
		}
		return s.substr(begin,maxSize);
	}
};
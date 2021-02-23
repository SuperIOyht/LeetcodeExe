//����һ���ַ��� S��һ���ַ��� T�������ַ��� S �����ҳ������� T �����ַ�����С�Ӵ���
//
//ʾ����
//
//���� : S = "ADOBECODEBANC", T = "ABC"
//	��� : "BANC"
//	˵����
//
//	��� S �в����������Ӵ����򷵻ؿ��ַ��� ""��
//	��� S �д����������Ӵ������Ǳ�֤����Ψһ�Ĵ𰸡�
//
//	��Դ�����ۣ�LeetCode��
//	���ӣ�https ://leetcode-cn.com/problems/minimum-window-substring
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
#include"headfile.h"
using namespace std;

class Solution {
public:
	bool canPermutePalindrome(string s) {
		sort(s.begin(), s.end());
		bool flag = true;
		char pre =' ';
		int num = 0;
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] == pre) {
				num++;
				continue;
			}
			if (s[i] != pre) {
				pre = s[i];
				if (num % 2 == 1) {
					if (flag) {
						flag = false;
					}
					else
					{
						return false;
					}
				}
				num = 1;
			}
		}

		if (num % 2 == 1) {
			if (flag) {
				flag = false;
			}
			else
			{
				return false;
			}
		}
		return true;
	}
};


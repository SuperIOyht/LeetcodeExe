#include"headfile.h"
using namespace std;

class Solution {
public:
	string modifyString(string s) {
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] == '?') {
				s[i] = 'a';
				if (i == 0) {
					if (s[i] == s[i + 1]) {
						s[i]++;
					}
				}
				else if (i  == s.size() - 1) {
					if (s[i] == s[i - 1]) {
						s[i]++;
					}
				}
				else
				{
					while (s[i] == s[i - 1] || s[i] == s[i + 1]) {
						s[i]++;
					}
				}
			}
		}
		return s;
	}
};


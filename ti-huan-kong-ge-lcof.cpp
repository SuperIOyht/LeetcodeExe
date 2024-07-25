#include"headfile.h"
using namespace std;

class Solution {
public:
	string replaceSpace(string s) {
		string ans;
		for (auto& it : s) {
			if (it == ' ') {
				ans.append("%20");
			}
			else
			{
				ans.push_back(it);
			}
		}
		return ans;
	}
};
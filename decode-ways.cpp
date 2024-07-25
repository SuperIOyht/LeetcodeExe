#include"headfile.h"
using namespace std;

class Solution {
public:
	int numDecodings(string s) {
		if (s[0] == '0' || s.empty()) {
			return 0;
		}
		int size = s.size();
		vector<int> dp(size, 0);
		dp[0] = 1;
		for (int i = 1; i < size; ++i) {
			if (s[i] != '0') {
				dp[i] += dp[i - 1];
			}
			int num = stoi(s.substr(i - 1, 2));
			if (num > 10 && num <= 26) {
				if (i == 1) {
					++dp[i];
				}
				else
				{
					dp[i] += dp[i - 2];
				}
			}
		}
		return dp[size - 1];
	}
};
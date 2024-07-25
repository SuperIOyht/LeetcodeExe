#include"headfile.h"
using namespace std;

class Solution {
public:
	vector<string> simplifiedFractions(int n) {
		vector<string> ans;
		if (n == 1) {
			return ans;
		}

		for (int i = 1; i < n; ++i) {
			for (int j = i + 1; j <= n; ++j) {
				if (j % i == 0) {
					ans.push_back(to_string(i) + "/" + to_string(j));
				}
			}
		}
		return ans;
	}
};

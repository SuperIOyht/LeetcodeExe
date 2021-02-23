#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
	vector<int> countBits(int num) {
		vector<int> ans(num + 1);
		int dec = 0;
		ans[0] = 0;
		for (int i = 1; i <= num; i++) {
			ans[i] = ans[i - pow(2, (int)log2(i))] + 1;
		}
		return ans;
	}
};

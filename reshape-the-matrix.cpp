#include"headfile.h"
using namespace std;

class Solution {
public:
	vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
		int old_r = nums.size();
		int old_c = nums[0].size();
		if (r*c != old_r * old_c) {
			return nums;
		}
		vector<vector<int>> ans;
		ans.resize(r);
		for (auto& it : ans) {
			it.resize(c);
		}
		for (int i = 0; i < old_r; ++i) {
			for (int j = 0; j < old_c; ++j) {
				int sum = i * old_c + j;
				ans[sum / c][sum % c] = nums[i][j];
			}
		}
		return ans;
	}
};
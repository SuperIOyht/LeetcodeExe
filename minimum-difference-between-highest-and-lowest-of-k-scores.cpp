#include"headfile.h"
using namespace std;

class Solution {
public:
	int minimumDifference(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end());
		int ans = INT_MAX;
		for (int i = 0; i < nums.size() - k; ++i) {
			ans = min(ans, abs(nums[i] - nums[i + k]));
		}
		return ans;
	}
};
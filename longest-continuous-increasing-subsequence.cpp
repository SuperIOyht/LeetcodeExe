#include"headfile.h"
using namespace std;

class Solution {
public:
	int findLengthOfLCIS(vector<int>& nums) {
		if (nums.empty()) {
			return 0;
		}
		int n = nums.size();
		vector<int> dp(n,1);
		for (size_t i = 1; i < n; i++)
		{
			dp[i] = nums[i] > nums[i - 1] ? dp[i-1] + 1 : 1;
		}
		return *max_element(dp.begin(), dp.end());
	}
};

int main() {
	Solution s;
	vector<int>a({ 1,3,5,4,7 });
	s.findLengthOfLCIS(a);
}
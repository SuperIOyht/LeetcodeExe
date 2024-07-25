#include"headfile.h"
#include<mutex>
using namespace std;

class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		int size = nums.size();
		vector<int> dp(size, 1);
		dp[0] = 1;
		int ans = 1;
		for (int i = 1; i < size; ++i) {
			int maxNum = 1;
			for (int j = 0; j < i; ++j) {
				if (nums[i] > nums[j]) {
					maxNum = max(maxNum, dp[j] + 1);
				}
			}
			dp[i] = maxNum;
			ans = max(ans, dp[i]);
		}
		return ans;
	}
};
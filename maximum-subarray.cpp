#include"headfile.h"
using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int size = nums.size();
		vector<int> dp(size, 0);
		dp[0] = nums[0];
		int max_num = dp[0];
		for (int i = 1; i < size; ++i) {
			dp[i] = max(nums[i], nums[i] + dp[i - 1]);
			max_num = max(max_num, dp[i]);
		}
		return max_num;
	}
};

int main() {
	Solution s;
	vector<int> a{ -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	s.maxSubArray(a);
}
#include"headfile.h"
using namespace std;

class Solution {
public:
	double findMaxAverage(vector<int>& nums, int k) {
		int num = accumulate(nums.begin(), nums.begin() + k, 0);
		int maxnum = num;
		for (int i = 1; i <= nums.size() - k; i++) {
			num = num - nums[i - 1] + nums[i + k - 1];
			maxnum = max(maxnum, num);
		}
		return (double)maxnum / k;
	}
};

int main() {
	Solution s;
	vector<int> nums = { 0,4,0,3,2 };
	s.findMaxAverage(nums, 1);
}
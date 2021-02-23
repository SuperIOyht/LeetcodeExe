#include"headfile.h"
using namespace std;

class Solution {
public:
	bool checkPossibility(vector<int>& nums) {
		int n = nums.size();
		if (nums.empty() || n <= 1) {
			return true;
		}
		int count = 0;
		for (int i = 1; i < n && count < 2; ++i) {
			if (nums[i] >= nums[i - 1]) {
				continue;
			}
			++count;
			if (i - 2 > 0 && nums[i - 2] > nums[i]) {
				nums[i] = nums[i - 1];
			}
			else
			{
				nums[i - 1] = nums[i];
			}
		}
		return count <= 1;
	}
};
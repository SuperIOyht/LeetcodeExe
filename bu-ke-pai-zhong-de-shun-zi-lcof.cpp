#include"headfile.h"
using namespace std;

class Solution {
public:
	bool isStraight(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int king = 0;
		for (int i = 0; i < 5; ++i) {
			if (nums[i] == 0) {
				king++;
			}
		}
		if (king >= 4) {
			return true;
		}
		if (nums[4] - nums[king] < nums[4]) {
			return true;
		}
		return false;
	}
};
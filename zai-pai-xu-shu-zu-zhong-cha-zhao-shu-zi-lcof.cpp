#include"headfile.h"
using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target) {
		int ans = 0;
		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] == target) {
				ans++;
			}
			if (nums[i] < target) {
				continue;
			}
			if (nums[i] > target) {
				break;
			}
		}
		return ans;
	}
};
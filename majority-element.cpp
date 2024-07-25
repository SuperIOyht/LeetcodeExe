#include"headfile.h"
using namespace std;

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		/*sort(nums.begin(), nums.end());
		return nums[nums.size() / 2];*/
		int vote = 0;
		int x;
		for (int i = 0; i < nums.size(); ++i) {
			if (vote == 0) {
				x = nums[i];
			}
			vote += x == nums[i] ? 1 : -1;
		}
		return x;
	}
};
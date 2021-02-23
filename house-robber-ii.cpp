#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int rob(vector<int>& nums) {
		if (nums.size() == 0)
		{
			return 0;
		}
		else if(nums.size() == 1)
		{
			return nums[0];
		}
		vector<int> max1(nums.size() + 1);
		vector<int> max2(nums.size() + 1);
		int ans1 = 0, ans2 = 0;
		max1[0] = 0; max1[1] = 0; max2[0] = 0; max2[1] = 0;
		for (int i = 2; i < nums.size() + 1; i++) {
			max1[i] = max1[i - 2] + nums[i - 2];
			max1[i] > ans1 ? ans1 = max1[i] : max1[i] = ans1;
		}
		for (int i = 2; i < nums.size() + 1; i++) {
			max2[i] = max2[i - 2] + nums[i - 1];
			max2[i] > ans2 ? ans2 = max2[i] : max2[i] = ans2;
		}
		return max(ans1, ans2);
	}
};
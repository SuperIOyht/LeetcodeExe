#include"headfile.h"
using namespace std;

class Solution {
public:
	vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
		unordered_map<int, int> map;
		vector<int> ans(nums);
		sort(nums.begin(), nums.end());
		int count = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (!map.count(nums[i]))
			{
				map[nums[i]] = count;
			}
			++count;
		}
		for (int i = 0; i < nums.size(); i++)
		{
			ans[i] = map[ans[i]];
		}
		return ans;
	}
};
#include"headfile.h"
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		/*unordered_map<int, int> hash;
		vector<int> ans;
		for (int i = 0; i < nums.size(); ++i) {
			hash[nums[i]] = 1;
		}
		for (int i = 0; i < nums.size(); ++i) {
			if (hash.count(target - nums[i])) {
				ans.push_back(nums[i]);
				ans.push_back(target - nums[i]);
				return ans;
			}
		}
		return ans;*/
		vector<int> ans;
		int low = 0, high = nums.size() - 1;
		while (low < high)
		{
			if (nums[low] + nums[high] == target) {
				ans.push_back(nums[low]);
				ans.push_back(nums[high]);
				return ans;
			}
			else if (nums[low] + nums[high] < target) {
				low++;
				continue;
			}
			else if (nums[low] + nums[high] > target) {
				high--;
				continue;
			}
		}
		return ans;
	}
};

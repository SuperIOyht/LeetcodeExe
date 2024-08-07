#include"headfile.h"
using namespace std;
class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> ans;
		if (nums.size() < 4) {
			return ans;
		}
		sort(nums.begin(), nums.end());
		int len = nums.size();
		for (int i = 0; i < len - 3; i++) {
			if (i > 0 &&nums[i] == nums[i - 1]) {
				continue;
			}
			for (int j = i + 1; j < len - 2; j++) {
				if (j > i + 1 && nums[j] == nums[j - 1]) {
					continue;
				}
				int left = j + 1, right = len - 1;
				while (left < right)
				{
					int sum = nums[i] + nums[j] + nums[left] + nums[right];
					if (sum == target) {
						ans.push_back({ nums[i] , nums[j] , nums[left] , nums[right] });
						while (left<right && nums[left] ==nums[left+1])
						{
							left++;
						}
						left++;
						while (left < right && nums[right] == nums[right-1])
						{
							right--;
						}
						right--;
					}
					else if(sum<target)
					{
						left++;
					}
					else
					{
						right--;
					}
				}
			}
		}
		return ans;
	}
};


void main() {
}

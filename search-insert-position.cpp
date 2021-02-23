#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int left = 0, mid, right = nums.size() - 1;
		int ans = nums.size();
		while (left <= right)
		{
			mid = (right + left) / 2;
			if (target > nums[mid]) {
				left = mid + 1;
			}
			else if(target <= nums[mid])
			{
				right = mid - 1;
				ans = mid;
			}
		}
		return ans;
	}
};
int main() {
	Solution s;
	vector<int> a = { 1,3,5,6 };
	s.searchInsert(a, 7);
}
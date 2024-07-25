#include"headfile.h"
using namespace std;

class Solution {
public:
	int singleNonDuplicate(vector<int>& nums) {
		if (nums.size() == 1) {
			return nums[0];
		}
		int begin = 0, end = nums.size() - 1;
		int mid;
		while (begin < end) {
			mid = (begin + end) / 2;
			if (nums[mid] == nums[mid + 1]) {
				if ((end - mid - 1) % 2 == 0) {
					end = mid - 1;
				}
				else
				{
					begin = mid + 2;
				}
			}
			else if (nums[mid] == nums[mid - 1]) {
				if ((end - mid) % 2 == 0) {
					end = mid - 2;
				}
				else {
					begin = mid + 1;
				}
			}
			else {
				return nums[mid];
			}
		}
		return nums[begin];
	}
};

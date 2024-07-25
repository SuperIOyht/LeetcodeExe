#include"headfile.h"
using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int left = 0, right = 0;
		int size = nums.size();
		int maxNum = INT_MIN;
		while (left < size)
		{
			int temp = 0;
			if (nums[left] <= 0) {
				left++;
				continue;
			}
			else
			{
				right = left;
				while (temp >= 0 && right < size)
				{
					temp += nums[right];
					maxNum = max(temp, maxNum);
					right++;
				}
				left++;
			}
		}
		return maxNum;
	}
};


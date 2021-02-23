#include"headfile.h"
using namespace std;

class Solution {
public:
	int findMaxConsecutiveOnes(vector<int>& nums) {
		int n = nums.size();
		int max = INT_MIN, cur = 0;
		for (auto&it : nums) {
			if (it) {
				++cur;
			}
			else
			{
				max = std::max(max, cur);
				cur = 0;
			}
		}
		max = std::max(cur, max);
		return max;
	}
};
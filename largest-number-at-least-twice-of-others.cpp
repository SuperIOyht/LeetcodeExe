#include"headfile.h"
using namespace std;

class Solution {
public:
	int dominantIndex(vector<int>& nums) {
		int index;
		int maxNUm = INT_MIN;
		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] > maxNUm) {
				maxNUm = nums[i];
				index = i;
			}
		}
		for (int i = 0; i < nums.size(); ++i) {
			if (i == index) {
				continue;
			}
			if (nums[i] * 2 > maxNUm) {
				return -1;
			}
		}
		return index;
	}
};
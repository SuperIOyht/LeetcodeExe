#include"headfile.h"
using namespace std;

class Solution {
public:
	vector<int> exchange(vector<int>& nums) {
		vector<int> a;
		vector<int> b;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] % 2) {
				a.emplace_back(nums[i]);
			}
			else {
				a.emplace_back(nums[i]);
			}
		}
		a.insert(a.end(), b.begin(), b.end());
		return a;
	}
};
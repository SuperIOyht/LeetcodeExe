#include"headfile.h"
using namespace std;

class Solution {
public:
	vector<int> findDisappearedNumbers(vector<int>& nums) {
		int n = nums.size();
		vector<int> hash(n + 1, 0);
		vector<int> ans;
		for (auto& it : nums) {
			++hash[it];
		}
		for (int i = 1; i <= n; i++) {
			if (hash[i] == 0) {
				ans.emplace_back(i);
			}
		}
	}
};
#include"headfile.h"
using namespace std;

class Solution {
public:
	long int ans = 0;
	int findTargetSumWays(vector<int>& nums, int S) {
		dfs(nums, S, 0);
		return ans;
	}
	void dfs(vector<int>& nums,long int S, int pos) {
		if (pos == nums.size()) {
			if(S == 0)
			++ans;
			return;
		}
		dfs(nums, S + nums[pos], pos + 1);
		dfs(nums, S - nums[pos], pos + 1);
	}
};
int main() {
	vector<int> a = { 2,107,109,113,127,131,137,3,2,3,5,7,11,13,17,19,23,29,47,53 };
	Solution s; 
	s.findTargetSumWays(a, 2147483647);
	system("pause");
}
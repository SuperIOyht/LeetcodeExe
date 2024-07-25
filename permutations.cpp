#include"headfile.h"
using namespace std;

class Solution {
public:
	vector<vector<int>> result;
	vector<bool> vis;
	vector<vector<int>> permute(vector<int>& nums) {
		int size = nums.size();
		vis.resize(size);
		vector<int> ans;
		dfs(nums, ans);
		return result;
	}
	void dfs(vector<int>& nums, vector<int> ans) {
		if (ans.size() == nums.size()) {
			result.push_back(ans);
		}
		for (int i = 0; i < nums.size(); ++i) {
			if (vis[i] == false) {
				ans.push_back(nums[i]);
				vis[i] = true;
				dfs(nums, ans);
				vis[i] = false;
				ans.pop_back();
			}
		}
	}
};
#include"headfile.h"
using namespace std;
//class Solution {
//private:
//	vector<int> temp;
//	set<vector< int >> set;
//	vector<bool> used;
//public:
//	vector<vector<int>> permuteUnique(vector<int>& nums) {
//		for (auto it : nums) {
//			used.emplace_back(false);
//		}
//		dfs(nums);
//		vector<vector<int>> ans;
//		for (auto it : set) {
//			ans.emplace_back(it);
//		}
//		return ans;
//	}
//	void dfs(vector<int> nums) {
//		if (temp.size() == nums.size()) {
//			set.insert(temp);
//			return;
//		}
//		for (int i = 0; i < nums.size();i++) {
//			if (!used[i]) {
//				temp.push_back(nums[i]);
//				used[i] = true;
//				dfs(nums);
//				temp.pop_back();
//				used[i] = false;
//			}
//		}
//	}
//};

class Solution {
	vector<int> vis;

public:
	void backtrack(vector<int>& nums, vector<vector<int>>& ans, int idx, vector<int>& perm) {
		if (idx == nums.size()) {
			ans.emplace_back(perm);
			return;
		}
		for (int i = 0; i < (int)nums.size(); ++i) {
			if (vis[i] || (i > 0 && nums[i] == nums[i - 1] && !vis[i - 1])) {
				continue;
			}
			perm.emplace_back(nums[i]);
			vis[i] = 1;
			backtrack(nums, ans, idx + 1, perm);
			vis[i] = 0;
			perm.pop_back();
		}
	}

	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>> ans;
		vector<int> perm;
		vis.resize(nums.size());
		sort(nums.begin(), nums.end());
		backtrack(nums, ans, 0, perm);
		return ans;
	}
};

int main() {
	Solution s;
	vector<int> a = { 1,1,1,2 };
	s.permuteUnique(a);
	return 0;
}
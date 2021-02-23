#include"headfile.h"
using namespace std;

class Solution {
public:
	vector<vector<int>> ans;
	vector<int> temp;
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		for (int i = 0; i < candidates.size();i++) {
			dfs(i, candidates, target);
		}
		return ans;
	}
	void dfs(int num, vector<int>& candidates, int target) {
		temp.push_back(candidates[num]);
		int sum = 0;
		for (auto it : temp) {
			sum += it;
		}
		if (sum == target) {
			ans.push_back(temp);
			temp.pop_back();
			return;
		}
		if (sum > target) {
			temp.pop_back();
			return;
		}
		for (int i = num; i < candidates.size(); i++) {
			dfs(i, candidates, target);
		}
		temp.pop_back();
	}
};

int main() {
	vector<int> a = { 2,3,6,7 };
	Solution s;
	s.combinationSum(a, 7);
}
#include"headfile.h"
using namespace std;
class Solution {
private: 
	vector<vector<int>> ans;
	vector<int> temp;
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		ans.push_back(temp);
		dfs(nums, 0);
		return ans;
	}
	void dfs(vector<int> nums, int pos) {
		if (pos == nums.size()) {
			return;
		}
		for (int i = pos; i < nums.size(); i++)
		{
			temp.push_back(nums[i]);
			ans.push_back(temp);
			dfs(nums, ++pos);
			temp.pop_back();
		}
	}
};

int main() {
	Solution s;
	vector<int> a = { 1,2,3 };
	s.subsets(a);
}
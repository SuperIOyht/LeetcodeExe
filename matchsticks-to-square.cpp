#include"headfile.h"
using namespace std;

class Solution {
public:
	bool makesquare(vector<int>& nums) {
		if (nums.size() < 4) {
			return false;
		}
		int sideLen,sum = 0;
		for (auto it : nums) {
			sum += it;
		}
		if (sum % 4 == 0) {
			sideLen =sum / 4;
		}
		else
		{
			return false;
		}
		vector<int> lens = { sideLen ,sideLen ,sideLen ,sideLen };
		return dfs(nums, 0, lens);
	}
	bool dfs(vector<int>& nums, int pos, vector<int> lens) {
		if (pos == nums.size()) {
			return lens[0] == 0 && lens[0] == lens[1] && lens[1] == lens[2] && lens[2] == lens[3];
		}
		for (int i = 0; i < 4; i++)
		{
			vector<int> temp = lens;
			if (temp[i] - nums[pos] >= 0) {
				temp[i] = temp[i] - nums[pos];
				if (dfs(nums, 1 + pos, temp)) {
					return true;
				}
			}
		}
	}
};

int main() {
	Solution s;
	vector<int> a = { };
	s.makesquare(a);
}
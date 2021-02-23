#include"headfile.h"
using namespace std;

class Solution {
public:
	vector<vector<int>> ans;
	vector<int> temp;
	vector<vector<int>> combinationSum3(int k, int n) {
		if (n < k || n>9 * k) {
			return ans;
		}
		else
		{
			dfs(k, n, 1);
		}
		return ans;
	}
	void dfs(int k, int n, int num) {
		if (temp.size() == k || n <= 0) {
			if (temp.size() == k && n == 0) {
				ans.push_back(temp);
			}
			return;
		}
		for (int i = num; i <= 9; i++) {
			temp.push_back(i);
			dfs(k, n - i, i + 1);
			temp.pop_back();
		}
	}
};
int main() {
	Solution s;
	s.combinationSum3(3, 7);
}
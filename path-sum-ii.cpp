#include"headfile.h"
using namespace std;

class Solution {
private:
	vector<int> temp;
	vector<vector<int>> ans;
public:
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		dfs(root, sum);
		return ans;
	}
	void dfs(TreeNode* root, int sum) {
		if (root == nullptr) {
			return;
		}
		temp.push_back(root->val);
		if (sum - root->val == 0 && root->right == nullptr && root->left == nullptr) {
			ans.push_back(temp);
		}
		dfs(root->left, sum - root->val);
		dfs(root->right, sum - root->val);
		temp.pop_back();
	}
};
int main() {
	Solution s;
	TreeNode* a5 = new TreeNode(-2);
	a5->right = new TreeNode(-3);
	s.pathSum(a5,-2);
}
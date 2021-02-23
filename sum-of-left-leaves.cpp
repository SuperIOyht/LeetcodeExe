#include"headfile.h"
using namespace std;

class Solution {
public:
	int ans = 0;
	int sumOfLeftLeaves(TreeNode* root) {
		dfs(root);
		return ans;
	}
	void dfs(TreeNode* root) {
		if (root == nullptr) {
			return;
		}
		if (root->left != nullptr) {
			dfs(root->left);
			if (root->left->left == nullptr && root->left->right == nullptr) {
				ans += root->left->val;
			}
		}
		if (root->right != nullptr) {
			dfs(root->right);
		}
	}
};

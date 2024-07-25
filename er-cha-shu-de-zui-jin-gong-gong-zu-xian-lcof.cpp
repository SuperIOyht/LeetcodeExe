#include"headfile.h"
using namespace std;

class Solution {
public:
	TreeNode* ans;
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		dfs(root, p, q);
		return ans;
	}
	bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == nullptr) {
			return false;
		}
		bool left = dfs(root->left, p, q);
		bool right = dfs(root->right, p, q);
		if ((left && right) || ((root->val == p->val || root->val == q->val) && (right || left))) {
			ans = root;
		}
		return right || left || (root->val == p->val || root->val == q->val);
	}
};
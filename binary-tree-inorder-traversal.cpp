#include"headfile.h"
using namespace std;
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> ans;
		mid(root, ans);
		return ans;
	}
	void mid(TreeNode* root, vector<int>& ans) {
		if (root != nullptr) {
			if (root->left != nullptr)
			{
				mid(root->left, ans);
			}
			ans.push_back(root->val);
			if (root->right != nullptr) {
				mid(root->right, ans);
			}
		}
	}
};

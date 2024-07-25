#include"headfile.h"
using namespace std;

class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		if (root == nullptr) {
			return true;
		}
		return is_same(root->left, root->right);
	}
	bool is_same(TreeNode* left, TreeNode* right) {
		if (left == nullptr && right == nullptr) {
			return true;
		}
		if (left == nullptr || right == nullptr) {
			return false;
		}
		if (left->val == right->val) {
			return is_same(left->left, right->right) && is_same(left->right, right->left);
		}
		return false;
	}
};
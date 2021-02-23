#include"headfile.h"
class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
 
		if (root->left == nullptr && root->right == nullptr) {
			return root;
		}
		TreeNode* temp;
		temp = root->left;
		root->left = root->right;
		root->right = temp;
		if (root->left != nullptr) {
			invertTree(root->left);
		}
		if (root->right != nullptr) {
			invertTree(root->right);
		}
		return root;
	}
};
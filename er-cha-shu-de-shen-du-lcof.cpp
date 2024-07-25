#include"headfile.h"
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	int maxDepth(TreeNode* root) {
		if (root == nullptr) {
			return 0;
		}
		int leftNum = maxDepth(root->left);
		int rightNum = maxDepth(root->right);
		return max(leftNum + 1, rightNum + 1);
	}
};
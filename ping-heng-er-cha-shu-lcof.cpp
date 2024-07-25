#include"headfile.h"
using namespace std;

class Solution {
public:
	bool isBalanced(TreeNode* root) {
		if (root == nullptr) {
			return true;
		}
		if (isBalanced(root->left) & isBalanced(root->right)) {
			
		}
		else {
			return false;
		}
		int left = getDepth(root->left);
		int right = getDepth(root->right);
		if (abs(right - left) > 1) {
			return false;
		}
		return true;
	}
	int getDepth(TreeNode* root) {
		if (root == nullptr) {
			return 0;
		}
		int right, left = 0;
		left = getDepth(root->left);
		right = getDepth(root->right);
		return max(left + 1, right + 1);
	}
};
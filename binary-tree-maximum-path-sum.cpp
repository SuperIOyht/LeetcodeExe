#include"headfile.h"
using namespace std;

class Solution {
public:
	int ans = INT_MIN;
	int get_max(TreeNode* root) {
		if (root == nullptr) {
			return 0;
		}
		int leftValue = max(get_max(root->left), 0);
		int rightValue = max(get_max(root->right), 0);

		ans = max(ans, leftValue + rightValue + root->val);

		return max(leftValue + root->val, rightValue + root->val);

	}
	int maxPathSum(TreeNode* root) {
		get_max(root);
		return ans;
	}
};
#include"headfile.h"
using namespace std;

class Solution {
public:
	int ans,kth;
	int kthLargest(TreeNode* root, int k) {
		kth = k;
		getkth(root);
		return ans;
	}
	void getkth(TreeNode* root) {
		if (root == nullptr) {
			return;
		}
		getkth(root->right);
		if (kth == 0) {
			return ;
		}
		if (--kth == 0) {
			ans = root->val;
		}
		getkth(root->left);
	}
};
#include"headfile.h"
using namespace std;

class Solution {
public:
	TreeNode* insertIntoBST(TreeNode* root, int val) {
		if (root == nullptr) {
			root = new TreeNode(val);
		}
		if (root->val > val) {
			if (root->left == nullptr) {
				root->left = new TreeNode(val);
			}
			else
			{
				insertIntoBST(root->left, val);
			}
		}
		if (root->val < val) {
			if (root->right == nullptr) {
				root->right = new TreeNode(val);
			}
			else
			{
				insertIntoBST(root->right, val);
			}
		}
		return root;
	}
};
int main() {
	TreeNode* a = new TreeNode(4);
	a->left = new TreeNode(2);
	a->right = new TreeNode(7);
	a->left->left = new TreeNode(1);
	a->left->right = new TreeNode(3);
	Solution s;
	s.insertIntoBST(a,5);

}
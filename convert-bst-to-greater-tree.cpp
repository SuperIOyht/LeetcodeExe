#include"headfile.h"
using namespace std;

class Solution {
private:
	int pre = 0;
public:
	TreeNode* convertBST(TreeNode* root) {
 		if (root != nullptr) {
			lastOrder(root);
		}
		return root;	
	}
	void lastOrder(TreeNode* root) {
		if (root->right != nullptr) {
			lastOrder(root->right);
		}
		root->val += pre;
		pre = root->val;
		if (root->left != nullptr) {
			lastOrder(root->left);
		}
	}
};
int main() {
	TreeNode* a = new TreeNode;
	a->val = 5;
	a->left = new TreeNode(2);
	a->right = new TreeNode(13);
	Solution s;
	s.convertBST(a);
}
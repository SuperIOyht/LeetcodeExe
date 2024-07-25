#include"headfile.h"
using namespace std;

class Solution {
public:
	TreeNode* mirrorTree(TreeNode* root) {
		if (root == nullptr) {
			return root;
		}
		TreeNode* left_temp = root->left;
		root->left = mirrorTree(root->right);
		root->right = mirrorTree(left_temp);
		return root;
	}
};

int main() {
	TreeNode* a = new TreeNode(4);
	a->left = new TreeNode(2);
	a->right = new TreeNode(7);
	Solution s;
	s.mirrorTree(a);
}
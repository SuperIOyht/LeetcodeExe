#include<iostream>
#include<vector>
#include"Tree.h"
using namespace std;

class Solution {
public:
	TreeNode* temp;
	void flatten(TreeNode* root) {
		reverse(root);
	}
	void reverse(TreeNode* root) {
		TreeNode* rightEnd = root;
		if (root == nullptr) {
			return;
		}
		else if (root->left == nullptr && root->right == nullptr) {
			return;
		}
		else
		{
			reverse(root->left);
			reverse(root->right);
			temp = root->right;
			root->right = root->left;
			while (rightEnd->right != nullptr)
			{
				rightEnd = rightEnd->right;
			}
			rightEnd->right = temp;
			root->left = nullptr;
		}
	}
};
int main() {
	TreeNode root(1);
	root.left = new TreeNode(2);
	root.right = new TreeNode(5);
	Solution s;
	s.flatten(&root);
}
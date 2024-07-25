#include"headfile.h"
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
	int get_left(TreeNode* root) {
		TreeNode* temp = root->left;
		while (temp->right != nullptr)
		{
			temp = temp->right;
		}
		return temp->val;
	}
	int get_right(TreeNode* root) {
		TreeNode* temp = root->right;
		while (temp->left != nullptr)
		{
			temp = temp->left;
		}
		return temp->val;
	}
	TreeNode* deleteNode(TreeNode* root, int key) {
		if (root == nullptr) {
			return nullptr;
		}
		if (root->val > key) {
			root->left = deleteNode(root->left, key);
		}
		if (root->val < key) {
			root->right = deleteNode(root->right, key);
		}
		if (root->val == key) {
			if (root->left == nullptr && root->right == nullptr) {
				root = nullptr;
			}
			else if (root->right != nullptr) {
				root->val = get_right(root);
				root->right = deleteNode(root->right, root->val);
			}
			else
			{
				root->val = get_left(root);
				root->left = deleteNode(root->left, root->val);
			}
		}
		return root;
	}
};
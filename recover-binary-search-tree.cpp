#include"Tree.h"
#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
	void recoverTree(TreeNode* root) {
		stack<TreeNode*> stack;
		TreeNode* pre = nullptr;
		TreeNode* x = nullptr, *y = nullptr;
		while (root !=nullptr ||  !stack.empty())
		{
			while (root != nullptr)
			{
				stack.push(root);
				root = root->left;
			}
			root = stack.top();
			stack.pop();
			if (pre != nullptr && root->val < pre->val) {
				y = root;
				if (x==nullptr) {
					x = pre;
				}
			}
			pre = root;
			root = root->right;
		}
		swap(x->val, y->val);
	}
};
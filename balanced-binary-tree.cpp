#include<iostream>
#include<vector>
#include<algorithm>
#include"Tree.h"
using namespace std;

class Solution {
public:
	bool isBalanced(TreeNode* root) {
		return dfs(root) != -1;
	}
	int dfs(TreeNode* root) {
		if (root == nullptr) {
			return 0;
		}
		int left = dfs(root->left);
		if (left == -1) {
			return -1;
		}
		int right = dfs(root->right);
		if (right == -1) {
			return -1;
		}
		return abs(left - right) < 2 ? max(left, right) + 1 : -1;
	}
};
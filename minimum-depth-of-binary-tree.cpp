#include"Tree.h"
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
	int minDepth(TreeNode* root) {
		if (root == nullptr) {
			return 0;
		}
		int left = minDepth(root->left) + 1;
		int right = minDepth(root->right) + 1;
		return min(left,right);
	}
};
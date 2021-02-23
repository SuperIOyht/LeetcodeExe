#include<iostream>
#include"Tree.h"
#include<queue>
using namespace std;

class Solution {
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (p == nullptr && q == nullptr) {
			return true;
		}
		else if(p == nullptr || q == nullptr)
		{
			return false;
		}
		else if (p->val == q->val)
		{
			return true;
		}
		return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
	}
};
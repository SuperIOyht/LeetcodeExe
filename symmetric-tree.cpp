/*
给定一个二叉树，检查它是否是镜像对称的。



例如，二叉树 [1, 2, 2, 3, 4, 4, 3] 是对称的。

1
 \
2   2
 \ / \
3  4 4  3


但是下面这个 [1, 2, 2, null, 3, null, 3] 则不是镜像对称的:

1
 \
2   2
\   \
3    3

链接：https ://leetcode-cn.com/problems/symmetric-tree
*/

  //Definition for a binary tree node.
#include<iostream>
#include<stack>
#include<vector>
using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
  class Solution {
  public:
	  bool check(TreeNode *p, TreeNode *q) {
		  if (!p && !q) return true;
		  if (!p || !q) return false;
		  return p->val == q->val && check(p->left, q->right) && check(p->right, q->left);
	  }

	  bool isSymmetric(TreeNode* root) {
		  return check(root, root);
	  }
  };

int main() {
	Solution a;
	TreeNode *root =new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	a.isSymmetric(root);
	return 0;
}

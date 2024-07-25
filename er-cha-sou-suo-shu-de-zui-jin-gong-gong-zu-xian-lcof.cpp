#include"headfile.h"
using namespace std;

class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		//if (root->val > p->val && root->val > q->val) {
		//	return lowestCommonAncestor(root->left, p, q);
		//}
		//if (root->val < p->val && root->val < q->val) {
		//	return lowestCommonAncestor(root->right, p, q);
		//}
		//return root;
		TreeNode* cur = root;
		while (cur != nullptr)
		{
			if (cur->val > p->val && cur->val > q->val) {
				cur = cur->left;
			}
			else if (cur->val < p->val && cur->val < q->val) {
				cur = cur->right;
			}
			else
			{
				break;
			}
		}
		return cur;
	}
};
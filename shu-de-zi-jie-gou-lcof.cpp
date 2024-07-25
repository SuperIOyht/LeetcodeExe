#include"headfile.h"
using namespace std;

class Solution {
public:
	bool isSubStructure(TreeNode* A, TreeNode* B) {
		if (A == nullptr || B == nullptr) {
			return false;
		}
		return isSame(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
	}
	bool isSame(TreeNode* A, TreeNode* B) {
		if (B == nullptr) {
			return true;
		}
		if (A == nullptr) {
			return false;
		}
		return A->val == B->val &&	isSame(A->left, B->left) && isSame(A->right, B->right);
	}
};


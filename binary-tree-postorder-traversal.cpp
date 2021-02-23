#include"headfile.h"
using namespace std;

class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> ans;
		if (root == nullptr) {
			return ans;
		}
		stack<TreeNode*> treeStack;
		treeStack.push(root);
		while (!treeStack.empty())
		{
			TreeNode* temp = treeStack.top();
			treeStack.pop();
			ans.emplace(ans.begin(), temp->val);
			if (temp->left != nullptr) {
				treeStack.push(temp->left);
			}
			if (temp->right != nullptr) {
				treeStack.push(temp->right);
			}
		}
		return ans;
	}
};

int main() {
	TreeNode* a = new TreeNode(3);
	TreeNode* b = new TreeNode(1);
	TreeNode* c = new TreeNode(2);
	a->left = b; a->right = c;
	Solution s;
	s.postorderTraversal(a);
}
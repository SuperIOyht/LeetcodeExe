#include"headfile.h"

using namespace std;

class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> ans;
		if (root == nullptr)
		{
			return ans;
		}
		stack<TreeNode*> stack;
		stack.push(root);
		while (!stack.empty())
		{
			TreeNode* temp = stack.top();
			stack.pop();
			ans.push_back(temp->val);
			if (temp->right != nullptr)
			{
				stack.push(temp->right);
			}
			if (temp->left != nullptr)
			{
				stack.push(temp->left);
			}
		}
		return ans;
	}
};

int main() {
	TreeNode a(1);
	TreeNode b(2);
	TreeNode c(3);
	a.right = &b;
	b.right = &c;
	Solution s;
	s.preorderTraversal(&a);
}
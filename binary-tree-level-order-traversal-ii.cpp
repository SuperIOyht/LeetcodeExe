#include"Tree.h"
#include"headfile.h"
using namespace std;

class Solution {
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		queue<TreeNode*> a, next;
		vector<vector<int>> ans;
		vector<int> tempans;
		if (root == nullptr) {
			return ans;
		}
		next.push(root);
		while (!next.empty())
		{
			a = next;
			while (!next.empty())
			{
				next.pop();
			}
			while (!a.empty())
			{
				TreeNode* temp = a.front();
				a.pop();
				if (temp->left != nullptr) {
					next.push(temp->left);
				}
				if (temp->right != nullptr) {
					next.push(temp->right);
				}
				tempans.push_back(temp->val);
			}
			ans.push_back(tempans);
			tempans.clear();
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}
};

int main() {
	TreeNode* root = nullptr;
	//root->left = new TreeNode(9);
	//root->right = new TreeNode(30);
	//root->right->left = new TreeNode(15);
	//root->right->right = new TreeNode(7);
	Solution s;
	s.levelOrderBottom(root);
}
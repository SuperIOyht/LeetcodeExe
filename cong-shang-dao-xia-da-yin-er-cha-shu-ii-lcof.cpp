#include"headfile.h"
using namespace std;

class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> ans;
		queue<TreeNode*> que;
		que.push(root);
		while (!que.empty())
		{
			int size = que.size();
			vector<int> tempVec;
			for (int i = 0; i < size; i++)
			{
				TreeNode* tempNode = que.front();
				tempVec.push_back(tempNode->val);
				if (tempNode->left != nullptr) {
					que.push(tempNode->left);
				}
				if (tempNode->right != nullptr) {
					que.push(tempNode->right);
				}
				que.pop();
			}
			ans.push_back(tempVec);
		}
		return ans;
	}
};
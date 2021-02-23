#include"headfile.h"
using namespace std;

class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> ans;
		if (root == nullptr)
		{
			return ans;
		}
		queue<TreeNode*> que;
		que.push(root);
		int count = 0;
		int num = 1, tempnum = 0;
		vector<int> temp;
		while (!que.empty())
		{
			TreeNode* tempNode = que.front();
			que.pop();
			temp.push_back(tempNode->val);
			--num;
			if (tempNode->left != nullptr)
			{
				que.push(tempNode->left);
				tempnum++;
			}
			if (tempNode->right != nullptr)
			{
				que.push(tempNode->right);
				tempnum++;
			}
			if (num == 0)
			{
				++count;
				if (count % 2 == 0)
				{
					reverse(temp.begin(), temp.end());
				}
				ans.push_back(temp);
				temp.clear();
				num = tempnum;
				tempnum = 0;
			}
		}
		return ans;
	}
};
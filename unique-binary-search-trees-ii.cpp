/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
using namespace std;
#include<iostream>
#include<vector>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}	
};

class Solution {
public:
	vector<TreeNode*> generateTrees(int n) {
		vector<TreeNode*> ans;
		TreeNode *now = nullptr;
		int size = 0;
		ans.push_back(&TreeNode(1));
		if (n == 1)
		{
			return ans;
		}
		for (int i = 2; i < n; i++) {
			size = ans.size();
			for (int j = 0; j < size; j++) {
				TreeNode *newNode = new TreeNode(i);
				newNode->left = ans[j];
				ans.push_back(newNode);//需要浅拷贝二叉树才能成功运行
				now = ans[j];
				while (true)
				{
					if (i > now->val && now->right != nullptr) {
						now = now->right;
					}
					else if (i > now->val && now->right == nullptr)
					{
						now->right = new TreeNode(i);
						break;
					}
				}
			}
		}
		return ans;
	}
};

int main() {
	vector<TreeNode*> ans;
	Solution s;
	ans = s.generateTrees(5);
	cout << ans.size();
}
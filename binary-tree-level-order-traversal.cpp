#include<queue>
#include<iostream>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> ans;
		vector<int> temp;
		queue<TreeNode*> treeQueue;
		int num = 0, tempNum = 0;
		TreeNode *front;
		if (root != nullptr) {
			treeQueue.push(root);
			num++;
		}
		while (!treeQueue.empty())
		{
			front = treeQueue.front();
			treeQueue.pop();
			temp.push_back(front->val);
			num--;
			if (front->left != nullptr) {
				treeQueue.push(front->left);
				tempNum++;
			}
			if (front->right != nullptr) {
				treeQueue.push(front->right);
				tempNum++;
			}
			if (num == 0) {
				ans.push_back(temp);
				temp.clear();
				num = tempNum;
				tempNum = 0;
			}
		}
		return ans;
	}
};
int main() {
	TreeNode *tree = new TreeNode(1);
	tree->left = new TreeNode(2);
	tree->right = new TreeNode(3);
	tree->left->left = new TreeNode(4);
	tree->left->right = new TreeNode(5);
	Solution a;
	a.levelOrder(tree);
	return 0;
}
/*
层次输出，使用tempNum存储下一层的Node个数
队列实现BFS：
基本思路
if(!queue.empty()){
	front = queue.front()//得到首元素，进行操作
	queue.pop()//出队列
	//树的左右节点入队列
	if(front->left != nullptr){
		queue.push(front -> left);
	}
	if(front->right != nullptr){
		queue.push(front -> right);
	}
}
*/
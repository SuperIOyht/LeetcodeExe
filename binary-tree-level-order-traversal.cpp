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
��������ʹ��tempNum�洢��һ���Node����
����ʵ��BFS��
����˼·
if(!queue.empty()){
	front = queue.front()//�õ���Ԫ�أ����в���
	queue.pop()//������
	//�������ҽڵ������
	if(front->left != nullptr){
		queue.push(front -> left);
	}
	if(front->right != nullptr){
		queue.push(front -> right);
	}
}
*/
#include"ListNode.h"
#include"Tree.h"
#include<vector>
using namespace std;

class Solution {
public:
	TreeNode* sortedListToBST(ListNode* head) {
		vector<int> list;
		while (head != nullptr) {
			list.push_back(head->val);
			head = head->next;
		}
		return dfs(list, 0, list.size() - 1);
	}
	TreeNode* dfs(vector<int> list, int begin, int end) {
		if (begin > end) {
			return nullptr;
		}
		int mid = (begin + end) / 2;
		TreeNode *root = new TreeNode(list[mid]);
		vector<int> leftList, rightList;
		root->left = dfs(list, begin, mid - 1);
		root->right = dfs(list, mid + 1, end);
		return root;
	}
};
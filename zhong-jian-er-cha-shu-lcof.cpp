#include"headfile.h"
using namespace std;

class Solution {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		TreeNode* root = &TreeNode();
		build(preorder, inorder, root);
		return root;
	}
	void build(vector<int>& preorder, vector<int>& inorder, TreeNode* node) {
		int node_value = preorder[0];
		node->val = node_value;
		if (preorder.size() == 1) {
			return;
		}
		int node_pos = 0;
		for (int i = 0; i < inorder.size(); ++i) {
			if (inorder[i] == node_value) {
				node_pos = i;
			}
		}
		vector<int> left_preorder{ preorder.begin() + 1, preorder.begin() + 1 + node_pos };
		vector<int> right_preoderd{ preorder.begin() + 1 + node_pos , preorder.end() };
		vector<int> left_inorder{ inorder.begin(), inorder.begin() + node_pos };
		vector<int> right_inorder{ inorder.begin() + node_pos + 1, inorder.end() };
		if (!left_preorder.empty()) {
			node->left = new TreeNode();
			build(left_preorder, left_inorder, node->left);
		}
		if (!right_preoderd.empty()) {
			node->right = new TreeNode();
			build(right_preoderd, right_inorder, node->right);
		}
	}
};

int main() {
	Solution s;
	vector<int> a({ 3, 9, 20, 15, 7 });
	vector<int> b({ 9,3,15,20,7 });
	s.buildTree(a,b);
}
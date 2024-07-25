#include"headfile.h"
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
class Codec {
public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		string codeStr;
		if (root == nullptr) {
			return codeStr;
		}
		queue<TreeNode*> mQueue;
		mQueue.push(root);
		while (!mQueue.empty())
		{
			TreeNode* temp = mQueue.front();
			mQueue.pop();
			if (temp == nullptr) {
				codeStr.append("null ");
				continue;
			}
			codeStr.append(to_string(temp->val) + " ");
			mQueue.push(temp->left);
			mQueue.push(temp->right);
		}
		codeStr.pop_back();
		return codeStr;
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		if (data.empty()) {
			return nullptr;
		}
		istringstream sstream(data);
		vector<TreeNode*> ans;
		string temp;
		while (sstream>>temp)
		{
			if (temp == "null") {
				ans.push_back(nullptr);
			}
			else
			{
				ans.push_back(new TreeNode(stoi(temp)));
			}
		}
		for (int i = 0; i < ans.size(); ++i) {
			if (!ans[i]) {
				continue;
			}
			if (2 * i + 1 < ans.size()) {
				ans[i]->left = ans[2 * i + 1];
			}
			if (2 * i + 2 < ans.size()) {
				ans[i]->right = ans[2 * i + 2];
			}
		}
		return ans[0];
	}
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

int main() {
	Codec ser, deser;
	deser.deserialize(ser.serialize(deser.deserialize("1 2 3 null null 4 5 6 7 ")));
}
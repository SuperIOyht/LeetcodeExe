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
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (!n) {
            return {};
        }
        return func(1, n);
    }
    vector<TreeNode*> func(int begin, int end) {
        if (begin > end) {
            return { nullptr };
        }
        vector<TreeNode*> res;
        vector<TreeNode*> vec_left;
        vector<TreeNode*> vec_right;
        for (int i = begin; i <= end; ++i) {
            vec_left = func(begin, i - 1);
            vec_right = func(i + 1, end);
            for (TreeNode* left : vec_left) {
                for (TreeNode* right : vec_right) {
                    TreeNode* now = new TreeNode(i);
                    now->left = left;
                    now->right = right;
                    res.emplace_back(now);
                }
            }
        }
        return res;
    }
};
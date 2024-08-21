#include<vector>
using namespace std;


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
    TreeNode* buildTree(vector<int> inorder, vector<int> postorder) {
        int psize = postorder.size();
        int isize = inorder.size();
        TreeNode* root = func(postorder, 0, psize - 1, inorder, 0, isize - 1);
        return root;
    }
    TreeNode* func(vector<int>& postorder, int pstart, int pend, vector<int>& inorder, int istart, int iend) {
        TreeNode* node = new TreeNode{ postorder[pend] };
        if (pstart == pend) {
            return node;
        }
        int node_val = postorder[pend];
        auto i_it = std::find(inorder.begin() + istart, inorder.begin() + iend, node_val);
        int left_tree_end = i_it - inorder.begin() - 1;
        int right_tree_begin = i_it - inorder.begin() + 1;
        if (istart <= left_tree_end) {
            node->left = func(postorder, pstart, pstart + (left_tree_end - istart), inorder, istart, left_tree_end);
        }
        if (right_tree_begin <= iend) {
            node->right = func(postorder, pstart + (left_tree_end - istart) + 1, pend, inorder, right_tree_begin, iend);
        }
        return node;
    }
};

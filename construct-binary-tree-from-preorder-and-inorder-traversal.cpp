class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int psize = preorder.size();
        int isize = inorder.size();
        TreeNode* root = func(preorder, 0, psize - 1, inorder, 0, isize - 1);
        return root;
    }
    TreeNode* func(vector<int>& preorder, int pstart, int pend, vector<int>& inorder, int istart, int iend) {
        TreeNode* node = new TreeNode{ preorder[pstart] };
        if (pstart == pend) {
            return node;
        }
        int node_val = preorder[pstart];
        auto i_it = std::find(inorder.begin() + istart, inorder.begin() + iend, node_val);
        int left_tree_end = i_it - inorder.begin() - 1;
        int right_tree_begin = i_it - inorder.begin() + 1;
        if (istart <= left_tree_end) {
            node->left = func(preorder, pstart + 1, pstart + (left_tree_end - istart + 1), inorder, istart, left_tree_end);
        }
        if (right_tree_begin <= iend) {
            node->right = func(preorder, pstart + (left_tree_end - istart) + 2, pend, inorder, right_tree_begin, iend);
        }
        return node;
    }
};
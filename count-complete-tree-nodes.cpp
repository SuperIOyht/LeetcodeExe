#include"headfile.h"
using namespace std;

class Solution {
public:
	int countNodes(TreeNode* root) {
		if (root == nullptr)
		{
			return 0;
		}
		TreeNode* temp = root;
		int len = 0;
		while (temp->left != nullptr)
		{
			++len;
			temp = temp->left;
		}
		int low = 1 << len, high = (1 << (len + 1)) - 1;
		while (low < high)
		{
			int mid = (high - low+1) / 2 + low;
			if (is_exsit(len, mid, root)) {
				low = mid;
			}
			else
			{
				high = mid - 1;
			}
		}
		return low;
	}
	bool is_exsit(int level, int k, TreeNode* root) {
		int bits = 1 << (level - 1);
		TreeNode* node = root;
		while (node != nullptr && bits > 0) {
			if (!(bits & k)) {
				node = node->left;
			}
			else {
				node = node->right;
			}
			bits >>= 1;
		}
		return node != nullptr;
	}
};
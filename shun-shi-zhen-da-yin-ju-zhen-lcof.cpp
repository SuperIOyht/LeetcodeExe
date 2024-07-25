#include"headfile.h"
using namespace std;

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> ans;
		if (matrix.empty()) {
			return ans;
		}
		int row = matrix.size();
		int col = matrix[0].size();
		int left = 0, right = col - 1;
		int top = 0, bottom = row - 1;
		while (true)
		{
			for (int i = left; i <= right; ++i) {
				ans.push_back(matrix[top][i]);
			}
			if (++top > bottom) {
				break;
			}
			for (int i = top; i <= bottom; ++i) {
				ans.push_back(matrix[i][right]);
			}
			if (--right < left) {
				break;
			}
			for (int i = right; i >= left; --i) {
				ans.push_back(matrix[bottom][i]);
			}
			if (--bottom < top) {
				break;
			}
			for (int i = bottom; i >= top; --i) {
				ans.push_back(matrix[i][left]);
			}
			if (++left > right) {
				break;
			}
		}
		return ans;
	}
};
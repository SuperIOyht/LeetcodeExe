#include"headfile.h"
using namespace std;

class Solution {
public:
	vector<int> luckyNumbers(vector<vector<int>>& matrix) {
		vector<int> ans;
		if (matrix.empty()) {
			return ans;
		}
		int n = matrix[0].size();
		int m = matrix.size();
		vector<int> colMax(n, INT_MIN);
		vector<int> volMax(m, INT_MAX);
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (matrix[i][j] < volMax[i]) {
					volMax[i] = matrix[i][j];
				}
				if (matrix[i][j] > colMax[j]) {
					colMax[j] = matrix[i][j];
				}
			}
		}
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (colMax[j] == volMax[i]) {
					ans.push_back(volMax[i]);
				}
			}
		}
		return ans;
	}
};
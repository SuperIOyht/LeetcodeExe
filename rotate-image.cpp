#include"headfile.h"
using namespace std;

class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		for (int i = 0; i < matrix.size() / 2; ++i) {
			layer_rotate(matrix, i, matrix.size() - i - 1);
		}
	}
	void layer_rotate(vector<vector<int>>& matrix, int x, int y) {
		if (x >= y) {
			return;
		}
		int n = matrix.size();
		for (int i = 0; i < y-x-1; ++i) {
			int temp = matrix[x][x + i];
			matrix[x][x + i] = matrix[y - i][x];
			matrix[y - i][x] = matrix[y][y - i];
			matrix[y][y - i] = matrix[x + i][y];
			matrix[x + i][y] = temp;
		}
	}
};

int main() {
	Solution s;
	vector<int>a = { 2, 29, 20, 26, 16, 28 };
	vector<int>b = { 12, 27, 9, 25, 13, 21 };
	vector<int>c = { 32, 33, 32, 2, 28, 14 };
	vector<int>d = { 13, 14, 32, 27, 22, 26 };
	vector<int>e = { 33, 1, 20, 7, 21, 7 };
	vector<int>f = { 4, 24, 1, 6, 32, 34 };
	vector<vector<int>> ma = { a,b,c,d,e,f };
	s.rotate(ma);
}
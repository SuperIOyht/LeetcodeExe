#include"headfile.h"
using namespace std;

class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		vector<unordered_map<int, int>> col(9);
		vector<unordered_map<int, int>> row(9);
		vector<unordered_map<int, int>> box(9);

		for (int i = 0; i < board.size(); ++i) {
			for (int j = 0; j < board[0].size(); ++j) {
				if (board[i][j] == '.') {
					continue;
				}
				int num = board[i][j] - '0';
				int box_index = (i / 3) * 3 + j / 3;
				++row[i][num];
				++col[j][num];
				++box[box_index][num];
				if (row[i][num] > 1 || col[j][num] > 1 || box[box_index][num] > 1) {
					return false;
				}
			}
		}
		return true;
	}
};

int main() {
	Solution s;
	vector<vector<char>> a = { {'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6' }, { '.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'} };
	s.isValidSudoku(a);
}
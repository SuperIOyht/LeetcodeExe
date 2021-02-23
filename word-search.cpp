#include"headfile.h"
using namespace std;

class Solution {
public:
	int dy[4] = { 1, -1, 0, 0 };
	int dx[4] = { 0, 0, 1, -1 };
	bool ans = false;
	vector<pair<int,int>> used;
	bool exist(vector<vector<char>>& board, string word) {
		for (int i = 0; i < board.size();i++) {
			for (int j = 0; j < board[0].size();j++) {
				if (board[i][j] == word[0]) {
					used.push_back({ i,j });
					dfs(board, word, i, j, 0);
					used.pop_back();
				}
			}
		}
		return ans;
	}
	bool haveUesd(int x, int y) {
		for (auto it : used) {
			if (it.first == x && it.second == y)
			{
				return false;
			}
		}
		return true;
	}
	void dfs(vector<vector<char>>& board, string word, int x, int y, int num) {
		if (num == word.size() - 1) {
			ans = true;
			return;
		}
		for (int i = 0; i < 4; i++)
		{
			if (!ans && x + dx[i] > -1 && x + dx[i] < board.size() && y + dy[i]>-1 && y + dy[i] < board[0].size() && haveUesd(x + dx[i], y + dy[i])) {
				if (board[x + dx[i]][y + dy[i]] == word[num + 1]) {
					used.push_back({ x + dx[i], y + dy[i] });
					dfs(board, word, x + dx[i], y + dy[i], num + 1);
					used.pop_back();
				}
			}
		}
	}
};
int main() {
	vector<char> b = { 'A', 'B', 'C', 'E' };
	vector<char> c = { 'S', 'F', 'C', 'S' };
	vector<char> d = { 'A', 'D', 'E', 'E' };
	vector<vector<char>> a = { b,c,d };
	Solution s;
	s.exist(a, "ABCCED");
	return 0;
}
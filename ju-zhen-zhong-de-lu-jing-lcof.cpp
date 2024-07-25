#include"headfile.h"
using namespace std;

class Solution {
public:
	vector<int> x_arr{ 1,-1,0,0 };
	vector<int> y_arr{ 0,0,1,-1 };
	bool ans = false;
	bool exist(vector<vector<char>>& board, string word) {
		map<pair<int, int>, bool> used;
		for (int i = 0; i < board.size(); ++i) {
			for (int j = 0; j < board[0].size(); ++j) {
				dfs(i, j, used, board, word, 0);
			}
		}
		return ans;
	}
	void dfs(int x, int y, map<pair<int, int>, bool> used, vector<vector<char>>& board, string word, int num) {
		if (board[x][y] != word[num] || ans) {
			return;
		}
		if (num+1 == word.size()) {
			ans = true;
			return;
		}
		used[pair<int, int>{x, y}] = true;
		for (int i = 0; i < 4; ++i)
		{
			if (x + x_arr[i] >= 0 && x + x_arr[i] < board.size() && y + y_arr[i] >= 0 && y + y_arr[i] < board[0].size()) {
				if (!used.count({ x + x_arr[i], y + y_arr[i] })) {
					dfs(x + x_arr[i], y + y_arr[i], used, board, word, num + 1);
				}
			}
		}
		used.erase(pair<int, int>{x, y});
	}
};

int main() {
	//vector<char> a({ 'A','B','C','E' });
	//vector<char> b({ 'S','F','C','S' });
	//vector<char> c({ 'A','D','E','E' });
	//vector<vector<char>> str({ a, b, c });
	//Solution s;
	//s.exist(str, "ABCCED");
	vector<char> a({ 'a' });
	vector<vector<char>> str({ a });
	Solution s;
	s.exist(str, "a");
}
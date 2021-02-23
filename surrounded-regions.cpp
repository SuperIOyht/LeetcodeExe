#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
using namespace std;

struct node
{
	int x;
	int y;
	//bool isChange;
	node(int x, int y) :x(x), y(y) {};
};

class Solution {
public:
	void solve(vector<vector<char>>& board) {
		stack<node> ns;
		unordered_map<node, bool> nodeList;//是否已经遍历
		/*vector<node> nodeTemp;*/
		int n = board.size();
		int m = board[0].size();
		bool ifChange = false;
		int nx[4] = { 0,0,1,-1 };
		int ny[4] = { 1,-1,0,0 };
		
		//行列大于三
		if (n >= 3 && m >= 3) {
			//遍历所有内部的点
			for (int i = 1; i < n - 1; i++)
			{
				for (int j = 1; j < m - 1; j++) {
					if (board[i][j] == 'O' && nodeList[node(i, j)] != true) {
						ns.push(node(i, j));
						ifChange = false;
						while (!ns.empty())
						{
							node temp = ns.top();
							ns.pop();
							nodeList[temp] = true;
							/*nodeTemp.push_back(temp);*/
							if (temp.x == 0 || temp.x == n - 1 || temp.y == 0 || temp.y == m - 1) {
								ifChange = true;
							}
							for (int k = 0; k < 4; k++) {
								if (board[i + nx[k]][j + ny[k]] == 'O' && nodeList[node(i + nx[k], j + ny[k])] != true) {
									ns.push(node(i + nx[k], j + ny[k]));
								}
							}
						}
						if (ifChange) {
							for (const auto &a : nodeList) {
								board[a.first.x][a.first.x] = 'X';
							}
						}
					}
				}
			}
		}
	}
};



/*
class Solution {
public:
	int n, m;

	void dfs(vector<vector<char>>& board, int x, int y) {
		if (x < 0 || x >= n || y < 0 || y >= m || board[x][y] != 'O') {
			return;
		}
		board[x][y] = 'A';
		dfs(board, x + 1, y);
		dfs(board, x - 1, y);
		dfs(board, x, y + 1);
		dfs(board, x, y - 1);
	}

	void solve(vector<vector<char>>& board) {
		n = board.size();
		if (n == 0) {
			return;
		}
		m = board[0].size();
		for (int i = 0; i < n; i++) {
			dfs(board, i, 0);
			dfs(board, i, m - 1);
		}
		for (int i = 1; i < m - 1; i++) {
			dfs(board, 0, i);
			dfs(board, n - 1, i);
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == 'A') {
					board[i][j] = 'O';
				}
				else if (board[i][j] == 'O') {
					board[i][j] = 'X';
				}
			}
		}
	}
};

//作者：LeetCode - Solution
链接：https ://leetcode-cn.com/problems/surrounded-regions/solution/bei-wei-rao-de-qu-yu-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

*/
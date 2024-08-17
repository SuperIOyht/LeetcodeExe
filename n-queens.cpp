#include"headfile.h"
using namespace std;
//class Solution {
//public:
//	struct queen
//	{
//		int x;
//		int y;
//		queen(int x, int y) :x(x), y(y) {};
//	};
//	vector<queen> list;
//	vector<vector<queen>> ans;
//	void solveNQueens(int n) {
//		//vector<vector<string>> strAns;
//		dfs(0, n);
//		//for (auto& it : ans) {
//		//	vector<string> a(n);
//
//		//}
//	}
//	void dfs(int x,int n){
//		if (list.size() == n && x == n) {
//			ans.push_back(list);
//		}
//		for (int i = 0; i < n; i++) {
//			queen temp = queen(x, i);
//			if (check(temp, n))
//			{
//				list.push_back(temp);
//				dfs(++x, n);
//				list.pop_back();
//			}
//		}
//	}
//	bool check(queen temp, int n) {
//		for (auto& it : list) {
//			int itx = it.x + 1;
//			int ity = it.y + 1;
//			int itx2 = it.x + 1;
//			int ity2 = it.y - 1;
//			if (it.y == temp.y) {
//				return false;
//			}
//			while (ity >= 0 && itx >= 0 && ity < n && itx < n) {
//				if (itx == temp.x && ity == temp.y) {
//					return false;
//				}
//				++itx;
//				++ity;
//			}
//			while (ity2 >= 0 && itx2 >= 0 && ity2 < n && itx2 < n)
//			{
//				if (itx == temp.x && ity == temp.y) {
//					return false;
//				}
//				++itx;
//				--ity;
//			}
//		}
//		return true;
//	}
//};

class Solution {
public:
	vector<vector<int>> res;
	vector<vector<string>> solveNQueens(int n) {
		vector<int> queen_pos(n + 1, 0);
		func(n, 1, queen_pos);
		return to_map(n, res);
	}
	void func(int n, int row, vector<int> queen_pos) {
		for (int i = 1; i <= n; ++i) {
			queen_pos[row] = i;
			if (allowed_queen(queen_pos, row, i)) {
				if (n == row) {
					res.push_back(queen_pos);
				}
				else {
					func(n, row + 1, queen_pos);
				}
			}
			queen_pos[row] = 0;
		}
	}
	bool allowed_queen(vector<int> queens_pos, int row, int col) {
		for (int i = 1; i < row; ++i) {
			if (queens_pos[i] == col ||  i - queens_pos[i] == row - col || queens_pos[i] + i == row + col) {
				return false;
			}
		}
		return true;
	}

	vector<vector<string>> to_map(int n, vector<vector<int>> res) {
		vector<vector<string>> results;
		for (auto temp : res) {
			string row_str(n, '.');
			vector<string> one(n, row_str);
			for (int i = 1; i < temp.size(); ++i) {
				one[i - 1][temp[i] - 1] = 'Q';
			}
			results.push_back(one);
		}
		return results;
	}
};





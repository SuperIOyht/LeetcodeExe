#include"headfile.h"
using namespace std;
class Solution {
public:
	struct queen
	{
		int x;
		int y;
		queen(int x, int y) :x(x), y(y) {};
	};
	vector<queen> list;
	vector<vector<queen>> ans;
	void solveNQueens(int n) {
		//vector<vector<string>> strAns;
		dfs(0, n);
		//for (auto& it : ans) {
		//	vector<string> a(n);

		//}
	}
	void dfs(int x,int n){
		if (list.size() == n && x == n) {
			ans.push_back(list);
		}
		for (int i = 0; i < n; i++) {
			queen temp = queen(x, i);
			if (check(temp, n))
			{
				list.push_back(temp);
				dfs(++x, n);
				list.pop_back();
			}
		}
	}
	bool check(queen temp, int n) {
		for (auto& it : list) {
			int itx = it.x + 1;
			int ity = it.y + 1;
			int itx2 = it.x + 1;
			int ity2 = it.y - 1;
			if (it.y == temp.y) {
				return false;
			}
			while (ity >= 0 && itx >= 0 && ity < n && itx < n) {
				if (itx == temp.x && ity == temp.y) {
					return false;
				}
				++itx;
				++ity;
			}
			while (ity2 >= 0 && itx2 >= 0 && ity2 < n && itx2 < n)
			{
				if (itx == temp.x && ity == temp.y) {
					return false;
				}
				++itx;
				--ity;
			}
		}
		return true;
	}
};

int main() {
	Solution s;
	s.solveNQueens(4);
}
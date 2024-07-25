#include"headfile.h"
using namespace std;

class Solution {
public:
	vector<vector<int>> map;
	vector<int> arr_x{ 1, -1, 0, 0 };
	vector<int> arr_y{ 0, 0, 1, -1 };
	int ans = 0;
	int movingCount(int m, int n, int k) {
		map = vector<vector<int>>(m, vector<int>(n, -1));
		for (int i = 0; i < map.size(); ++i) {
			for (int j = 0; j < map[0].size(); ++j) {
				map[i][j] = get(i, j);
			}
		}
		dfs(0, 0, k, map);
		return ans;
	}
	void dfs(int x, int y, int k, vector<vector<int>>& map) {
		int m = map.size();
		int n = map[0].size();
		if (map[x][y] != -1 && map[x][y] <= k) {
			++ans;
			map[x][y] = -1;
			for (int i = 0; i < 4; ++i) {
				if (x + arr_x[i] < m && x + arr_x[i] >= 0 && y + arr_y[i] < n && y + arr_y[i] >= 0) {
					dfs(x + arr_x[i], y + arr_y[i], k, map);
				}
			}
		}
	}
	int get(int x, int y) {
		int res = 0;
		while (x != 0)
		{
			res += x % 10;
			x = x / 10;
		}
		while (y != 0)
		{
			res += y % 10;
			y = y / 10;
		}
		return res;
	}
};

int main() {
	Solution s;
	s.movingCount(3, 2, 17);
}
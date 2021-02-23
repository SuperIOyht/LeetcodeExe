#include"headfile.h"
using namespace std;


class union_find_set {
public:
	vector<int> parent;
	int n;
	int setCount;
	void init(int x) {
		n = x;
		setCount = x;
		parent.resize(x);
		for (int i = 0; i < x; i++) {
			parent[i] = i;
		}
	}
	int find(int x) {
		return x == parent[x] ? x : parent[x] = find(parent[x]);
	}
	bool union_set(int x, int y) {
		int rootX = find(x);
		int rootY = find(y);
		if (rootX == rootY) {
			return false;
		}
		parent[rootX] = rootY;
		--setCount;
		return true;
	}
	bool connected(int x, int y) {
		x = find(x);
		y = find(y);
		return x == y;
	}
};
class Solution {
public:
	int swimInWater(vector<vector<int>>& grid) {
		int m = grid.size();
		int n = grid[0].size();
		vector<tuple<int, int, int>> edges;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				int id = i * n + j;
				if (i > 0) {
					edges.emplace_back(id - n, id, max(grid[i][j], grid[i - 1][j]));
				}
				if (j > 0) {
					edges.emplace_back(id - 1, id, max(grid[i][j], grid[i][j - 1]));
				}
			}
		}
		sort(edges.begin(), edges.end(), [](const tuple<int, int, int>&e1, const tuple<int, int, int>&e2) {
			return std::get<2>(e1) < get<2>(e2);
		});
		union_find_set uf;
		uf.init(m*n);
		int ans = 0;
		for (const tuple<int, int, int> it : edges) {
			uf.union_set(get<0>(it), get<1>(it));
			if (uf.connected(0, m * n - 1)) {
				ans = get<2>(it);
				break;
			}
		}
		return ans;
	}
};
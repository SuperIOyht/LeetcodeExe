#include"headfile.h"
using namespace std;

class union_find
{
public:
	int setCount = 0;
	vector<int> parent;
	union_find(int n) {
		setCount = n;
		parent.resize(n);
		for (int i = 0; i < n; i++)
		{
			parent[i] = i;
		}
	}
	int find(int x) {
		return x == parent[x] ? x : parent[x] = find(parent[x]);
	}
	void unionSet(int x, int y) {
		int rootX = find(x);
		int rootY = find(y);
		if (rootX == rootY)
		{
			return;
		}
		parent[rootX] = rootY;
		--setCount;
	}
};

class Solution {
public:
	int regionsBySlashes(vector<string>& grid) {
		int n = grid.size();
		int size = 4 * n*n;
		union_find a_union(size);
		for(int i = 0; i < n; i++){
			for (int j = 0; j < n; j++) {
				int index = 4 * (i * n + j);
				char c = grid[i][j];
				if (c == '/') {
					a_union.unionSet(index, index + 3);
					a_union.unionSet(index + 1, index + 2);
				}
				else if (c == '\\')
				{
					a_union.unionSet(index, index + 1);
					a_union.unionSet(index + 2, index + 3);
				}
				else
				{
					a_union.unionSet(index, index + 1);
					a_union.unionSet(index + 1, index + 2);
					a_union.unionSet(index + 2, index + 3);
				}
				if (j + 1 < n) {
					a_union.unionSet(index + 1, 4 * (i * n + j + 1) + 3);
				}
				// 向下合并：2（当前）、0（下一行）
				if (i + 1 < n) {
					a_union.unionSet(index + 2, 4 * ((i + 1) * n + j));
				}
			}
		}
		return a_union.setCount;
	}
};

int main() {
	Solution s;
	vector<string> a = { " /","/ " };
	s.regionsBySlashes(a);
}

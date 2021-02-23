#include"headfile.h"
using namespace std;

class union_find {
public:
	int count = 0;
	vector<int> father;
	void init(int n){
		count = n;
		father.resize(n);
		for (int i = 0; i < n; i++)
		{
			father[i] = i;
		}
	}
	int find(int x) {
		return father[x] == x ? x : father[x] = find(father[x]);
	}
	bool union_set(int x, int y) {
		int rootX = find(x-1);
		int rootY = find(y-1);
		if (rootX == rootY) {
			return false;
		}
		father[rootX] = rootY;
		--count;
		return true;
	}
};

class Solution {
public:
	int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
		int ans = 0;
		union_find union_a, union_b;
		union_a.init(n);
		union_b.init(n);
		for (auto& it : edges) {
			if (it[0] == 3) {
				if (union_a.union_set(it[1], it[2])) {
					union_b.union_set(it[1], it[2]);
				}
				else
				{
					ans++;
				}
			}
		}
		for (auto& it : edges) {
			if (it[0] == 1) {
				if (!union_a.union_set(it[1], it[2])) {
					++ans;
				}
			}
			else if (it[0] == 2) {
				if (!union_b.union_set(it[1], it[2])) {
					++ans;
				}
			}
		}
		if (union_a.count != 1 || union_b.count != 1)
		{
			return -1;
		}
		return ans;
	}
};

int main() {
	Solution s;
	vector<vector<int>> a = { {3,1,2},{3,2,3},{1,1,3},{1,2,4},{1,1,2},{2,3,4} };
	s.maxNumEdgesToRemove(4, a);
}
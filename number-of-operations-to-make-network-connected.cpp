#include"headfile.h"
using namespace std;

class Solution {
private: 
	vector<int> used;
	vector<vector<int>> edges;
public:
	int makeConnected(int n, vector<vector<int>>& connections) {
		if (connections.size() < n-1)
		{
			return -1;
		}
		edges.resize(n);
		for (int i = 0; i < connections.size(); i++)
		{
			edges[connections[i][0]].push_back(connections[i][1]);
			edges[connections[i][1]].push_back(connections[i][0]);
		}
		used.resize(n);
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (!used[i])
			{
				dfs(i);
				ans++;
			}
		}
		return ans-1;
	}
	void dfs(int n) {
		used[n] = true;
		for (int i = 0; i < edges[n].size(); i++)
		{
			if (!used[edges[n][i]])
			{
				dfs(edges[n][i]);
			}
		}
	}
};

class Solution2
{
public:
	int makeConnected(int n, vector<vector<int>>& connections) {
		if (connections.size() < n - 1)
		{
			return -1;
		}
		union_find uf;
		uf.init(n);
		for (const auto& it : connections) {
			uf.unit(it[0], it[1]);
		}
		return uf.setCount - 1;
	}

private:

};

class union_find {
public:
	vector<int> father;
	int setCount;
	int n;
	void init(int n) {
		setCount = n;
		this->n = n;
		for (int i = 0; i < n; i++)
		{
			father[n] = n;
		}
	}
	int findSet(int x) {
		return father[x] == x ? x : father[x] = findSet(father[x]) ;
	}
	bool unit(int x,int y){
		x = findSet(x);
		y = findSet(y);
		if (x==y)
		{
			return false;
		}
		father[y] = x;
		--setCount;
	}
};
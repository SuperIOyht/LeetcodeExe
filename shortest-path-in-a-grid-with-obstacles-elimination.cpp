#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct node
{
	int x;
	int y;
	int count;
	node(int x, int y,int count) :x(x), y(y),count(count) {};
};
class Solution {
public:
	int shortestPath(vector<vector<int>>& grid, int k) {
		int m = grid.size();
		int n = grid[0].size();
		if (n == 1 && m == 1) {
			return 0;
		}
		int minStep = 0;
		vector<vector<bool>> map(grid.size());
		for (int i = 0; i < m; i++) {
			map[i].resize(n);
		}
		map[0][0] = k;
		int dx[] = { 1,-1,0,0 };
		int dy[] = { 0,0,1,-1 };
		queue<node> que;
		que.push(node(0,0,0));
		while (!que.empty())
		{
			minStep++;
			int size = que.size();
			for (int i = 0; i < size; i++) {
				node nowNode = que.front();
				que.pop();
				for (int j = 0; j < 4; j++) {
					int xNew = nowNode.x + dx[j];
					int yNew = nowNode.y + dy[j];
					if (xNew < 0 || xNew >= m || yNew < 0 || yNew >= n) {
						continue;
					}
					if (xNew == m - 1 && yNew == n - 1) {
						return minStep;
					}
					if (grid[xNew][yNew] == 1 && nowNode.count >= k) {
						continue;
					}
					int newCount = grid[xNew][yNew] == 1 ? nowNode.count + 1 : nowNode.count;
					if (map[xNew][yNew] == NULL && map[xNew][yNew] >= k - newCount) {
						continue;
					}
					else
					{
						map[xNew][yNew] = k - newCount;
					}
					que.push(node(xNew, yNew, newCount));
				}
			}
		}
	}
};


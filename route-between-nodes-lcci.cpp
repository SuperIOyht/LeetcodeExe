#include"headfile.h"
using namespace std;

class Solution {
public:
	bool hasfind = false;
	bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
		unordered_map<int, int> path;
		unordered_map<int, vector<int>> map;
		for (int i = 0; i < graph.size(); ++i) {
			map[graph[i][0]].push_back(graph[i][1]);
		}
		bfs(map, start, target, path);
		return hasfind;
	}
	void bfs(unordered_map<int, vector<int>> map, int start, int target, unordered_map<int,int> path) {
		path[start] = 1;
		for (int i = 0; i < map[start].size(); ++i) {
				if (map[start][i] == target) {
					hasfind = true;
					return;
				}
				if (!path.count(map[start][i])) {
					bfs(map, map[start][i], target, path);
				}
		}
	}
};

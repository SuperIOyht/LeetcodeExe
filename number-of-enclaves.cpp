#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
using namespace std;

class Solution {
public:
	int dx[4] = { 0,0,1,-1 };
	int dy[4] = { 1,-1,0,0 };
	int numEnclaves(vector<vector<int>>& A) {
		int ans = 0;
		map<pair<int, int>,bool> have;
		int n = A.size();
		int m = A[0].size();
		if (n < 3 && m < 3) {
			return 0;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				have[{i, j}] = false;
				if (A[i][j]) {
					ans++;
				}
			}
		}
		for (int i = 0; i < m; i++) {
			if (!have[{ 0,i }] && A[0][i]) {
				dfs(0, i, A, ans, have);
			}
		}
		for (int i = 1; i < n - 1; i++) {
			if (!have[{ i,0 }] && A[i][0]) {
				dfs(i, 0, A, ans, have);
			}
			if (!have[{ i,m - 1 }] && A[i][m-1]) {
				dfs(i, m - 1, A, ans, have);
			}
		}
		for (int i = 0; i < m; i++)
		{
			if (!have[{ n - 1,i }] && A[n-1][i]) {
				dfs(n - 1, i, A, ans, have);
			}
		}
		return ans;
	}
	void dfs(int x,int y, vector<vector<int>>& A,int &ans,map<pair<int, int>, bool> &have) {
		int n = A.size();
		int m = A[0].size();
		ans--;
		have[{x, y}] = true;
		for (int i = 0; i < 4; i++) {
			if (x + dx[i] >= 0 && x + dx[i] < n && y + dy[i] >= 0 && y + dy[i] < m) {
				if (!have[{ x + dx[i],y + dy[i] }] && A[x + dx[i]][y + dy[i]]) {
					dfs(x + dx[i], y + dy[i], A, ans, have);
				}
			}
		}
	}
};

int main() {
	Solution s;
	//vector<int> a = { 0, 0, 0, 1, 1, 1, 0, 1, 0, 0 };
	//vector<int> b = { 1, 1, 0, 0, 0, 1, 0, 1, 1, 1 };
	//vector<int> c = { 0, 0, 0, 1, 1, 1, 0, 1, 0, 0 };
	//vector<int> d = { 0,0,0,0 };
	vector<vector<int>> e = {
		{0,0,0,1,1,1,0,1,0,0},
		{1,1,0,0,0,1,0,1,1,1},
		{0,0,0,1,1,1,0,1,0,0},
		{0,1,1,0,0,0,1,0,1,0},
		{0,1,1,1,1,1,0,0,1,0},
		{0,0,1,0,1,1,1,1,0,1},
		{0,1,1,0,0,0,1,1,1,1},
		{0,0,1,0,0,1,0,1,0,1},
		{1,0,1,0,1,1,0,0,0,0},
		{0,0,0,0,1,1,0,0,0,1} 
	};
	s.numEnclaves(e);
	return 0;
}
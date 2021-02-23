#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	int dx[4] = { 0,0,1,-1 };
	int dy[4] = { 1,-1,0,0 };
	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
		dfs(image, newColor, sr, sc,image[sr][sc]);
		return image;
	}
	void dfs(vector<vector<int>>& image, int newColor, int sr, int sc, int oldColor) {
		int n = image.size();
		int m = image[0].size();
		image[sr][sc] = newColor;
		for (int i = 0; i < 4; i++) {
			if (sr + dx[i] >= 0 && sr + dx[i] < n && sc + dy[i] >= 0 && sc + dy[i] < m ) {
				if (image[sr + dx[i]][sc + dy[i]] == oldColor && image[sr + dx[i]][sc + dy[i]] != newColor) {
					dfs(image, newColor, sr + dx[i], sc + dy[i], oldColor);
				}
			}
		}
	}
};
int main() {
	Solution s;
	vector<vector<int>> e = {
		{0,0,0 },
		{ 0,1,1 }
	};
	s.floodFill(e, 1,
		1,
		1);
	return 0;
}
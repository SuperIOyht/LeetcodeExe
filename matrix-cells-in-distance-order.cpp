#include"headfile.h"
using namespace std;

class Solution {
public:
	vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
		int dx[] = { 1,-1,0,0 };
		int dy[] = { 0,0,1,-1 };
		vector<vector<bool>> valid(R, vector<bool>(C,true));
		vector<vector<int>> ans;
		queue<pair<int, int>> que;
		que.push({ r0,c0 });
		valid[r0][c0] = false;
		while (!que.empty())
		{
			pair<int, int> temp = que.front();
			que.pop();
			ans.push_back({ temp.first,temp.second});
			
			for (int i = 0; i < 4; i++)
			{
				if (temp.first + dx[i] >= 0 && temp.first + dx[i] < R && temp.second + dy[i] >= 0 && temp.second + dy[i] < C) {
					if (valid[temp.first + dx[i]][temp.second + dy[i]])
					{
						que.push({ temp.first + dx[i] ,temp.second + dy[i] });
						valid[temp.first + dx[i]][temp.second + dy[i]] = false;
					}
				}
			}
		}
		return ans;
	}
};

int main() {
	Solution s;
	s.allCellsDistOrder(2,2,0,1);
	int a = 0;
}
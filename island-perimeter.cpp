#include"headfile.h"

using namespace std;

class Solution {
public:
	int islandPerimeter(vector<vector<int>>& grid) {
		if (grid.empty())
		{
			return 0;
		}
		int num = 0;
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[0].size(); j++)
			{
				if (grid[i][j])
				{
					num = 4 + num;
					if (j > 0)
					{
						if (j > 0 & grid[i][j - 1])
						{
							num -= 2;
						}
					}
					if (i > 0)
					{
						if (grid[i - 1][j])
						{
							num -= 2;
						}
					}
				}
			}
		}
		return num;
	}
};

int main() {
	vector<vector<int>> a = { {0,1,0,0 }, { 1,1,1,0 }, { 0,1,0,0 }, { 1,1,0,0 } };
	Solution s;
	s.islandPerimeter(a);

}

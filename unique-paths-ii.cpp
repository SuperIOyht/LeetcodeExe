#include<vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> steps(m, vector<int>(n, 0));

        for (int i = m-1; i >= 0; --i) {
            if (obstacleGrid[i][n - 1] == 0) {
                steps[i][n - 1] = 1;
            }
            else {
                break;
            }
        }
        for (int i = n-1; i >= 0; --i) {
            if (obstacleGrid[m - 1][i] == 0) {
                steps[m - 1][i] = 1;
            }
            else {
                break;
            }
        }
        for (int i = m - 2; i >= 0; --i) {
            for (int j = n - 2; j >= 0; --j) {
                if (obstacleGrid[i][j] == 0) {
                    steps[i][j] = steps[i][j + 1] + steps[i + 1][j];
                }
            }
        }
        return steps[0][0];
    }
};
#include<vector>

using namespace std;

//class Solution {
//public:
//    vector<vector<int>> results;
//    int M, N;
//    int func(int x, int y) {
//        if (results[x][y] != 0) {
//            return results[x][y];
//        }
//        int steps = 0;
//        if (x + 1 < M) {
//            steps += func(x + 1, y);
//        }
//        if (y + 1 < N) {
//            steps += func(x, y + 1);
//        }
//        return steps;
//    }
//    int uniquePaths(int m, int n) {
//        results = vector<vector<int>>(m, vector<int>(n, 0));
//        results[m - 1][n - 1] = 1;
//        M = m;
//        N = n;
//        return func(0, 0);
//    }
//};
#include<stack>
#include<queue>
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> path_map(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            path_map[i][n - 1] = 1;
        }
        for (int j = 0; j < n; ++j) {
            path_map[m - 1][j] = 1;
        }
        for (int i = m - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {
                path_map[i][j] = path_map[i + 1][j] + path_map[i][j + 1];
            }
        }
        return path_map[0][0];
    }
};
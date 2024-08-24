#include<vector>

using namespace std;

//class Solution {
//public:
//    int numSquares(int n) {
//        vector<int> dp(n + 1, 0);
//        dp[1] = 1;
//        dp[2] = 2;
//        if (n <= 2) {
//            return dp[n];
//        }
//        for (int i = 3; i <= n; ++i) {
//            if (is_perfect(i)) {
//                dp[i] = 1;
//                continue;
//            }
//            int res = INT_MAX;
//            for (int j = 1; j <= i / 2; ++j) {
//                res = min(res, dp[j] + dp[i - j]);
//            }
//            dp[i] = res;
//        }
//        return dp[n];
//    }
//    bool is_perfect(int num) {
//        int sq = sqrt(num);
//        return sq * sq == num;
//    }
//};

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; ++i) {
            int res = INT_MAX;
            for (int j = 1; j * j <= i; ++j) {
                res = min(res, dp[i - j * j]);
            }
            dp[i] = res + 1;
        }
        return dp[n];
    }
};
int main() {
    Solution s;
    s.numSquares(12);
}
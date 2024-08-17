#include<vector>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> ls(n + 1, 0);
        ls[0] = 1;
        ls[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                ls[i] += ls[j - 1] * ls[i - j];
            }
        }
        return ls[n];
    }
};

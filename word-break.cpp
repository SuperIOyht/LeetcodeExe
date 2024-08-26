#include<vector>
#include<string>
#include<array>
#include<unordered_set>

using namespace std;


class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordset{};
        for (auto it : wordDict) {
            wordset.insert(it);
        }
        int size = s.size();
        vector<bool> dp(size + 1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && wordset.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[size];
    }
};
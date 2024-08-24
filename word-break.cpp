#include<vector>
#include<string>
#include<unordered_set>

using namespace std;


class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordset{};
        for (auto it : wordDict) {
            wordset.insert(it);
        }

    }
};
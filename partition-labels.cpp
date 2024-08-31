#include<vector>
#include<unordered_map>
#include<string>
using namespace std;
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> res;
        unordered_map<char, int> map;
        for (int i = 0; i < s.size(); ++i) {
            map[s[i]] = i;
        }
        int now_pos = 0;
        int max_partition_pos = map[s[now_pos]];
        int partition_size = 0;
        while (now_pos < s.size()) {
            ++partition_size;
            max_partition_pos = max(max_partition_pos, map[s[now_pos]]);
            if (now_pos == max_partition_pos) {
                res.push_back(partition_size);
                partition_size = 0;
            }
            ++now_pos;
        }
        return res;
    }
};

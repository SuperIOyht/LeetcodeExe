#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        if (intervals.size() == 0) {
            res.push_back(newInterval);
            return res;
        }
        bool changed_interval = false;
        for (auto interval : intervals) {
            if (interval[1] < newInterval[0] || interval[0] > newInterval[1]) {
                if (changed_interval) {
                    res.push_back(newInterval);
                }
                res.push_back(interval);
            }
            else if ((newInterval[0] <= interval[0] && newInterval[1] >= interval[0]) || (interval[0] <= newInterval[0] && interval[1] >= newInterval[0])) {
                newInterval[0] = min(newInterval[0], interval[0]);
                newInterval[1] = max(newInterval[1], interval[1]);
                continue;
            }
        }
        auto it = res.begin();
        for (; it != res.end(); ++it) {
            if ((*it)[0] > newInterval[0]) {
                break;
            }
        }
        res.insert(it, newInterval);
        return res;
    }
};
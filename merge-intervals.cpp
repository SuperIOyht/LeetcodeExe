#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
	static bool cmp(vector<int> a, vector<int> b) {
		return a[0] < b[0];
	}
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		sort(intervals.begin(),intervals.end(),cmp);
		vector<vector<int>> ans;
		if (intervals.empty()) {
			return ans;
		}
		else
		{
			for (int i = 1; i < intervals.size(); i++) {
				if (intervals[i][0] <= intervals[i - 1][1]) {
					if (intervals[i][1] <= intervals[i - 1][1]) {
						intervals[i][0] = intervals[i - 1][0];
						intervals[i][1] = intervals[i - 1][1];
					}
					else {
						intervals[i][0] = intervals[i - 1][0];
					}
				}
				else {
					ans.push_back(intervals[i - 1]);
				}
			}
			ans.push_back(intervals[intervals.size() - 1]);
			return ans;
		}
	}
};
#include"headfile.h"
using namespace std;

class Solution {
public:
	int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
		int dis = INT_MAX;
		int ans = INT_MAX;
		bool have_ans = false;
		for (int i = 0; i < points.size();++i) {
			if (x == points[i][0] || y == points[i][1]) {
				if (abs(x - points[i][0]) + abs(y - points[i][1]) < dis) {
					dis = abs(x - points[i][0]) + abs(y - points[i][1]);
					ans = i;
				}
				have_ans = true;
			}
		}
		if (!have_ans) {
			return -1;
		}
		return ans;
	}
};
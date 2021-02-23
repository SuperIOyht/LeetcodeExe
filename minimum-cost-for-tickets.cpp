#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int mincostTickets(vector<int>& days, vector<int>& costs) {
		vector<int> dp(days[days.size() - 1] + 1,0);
		int index = 0;
		for (int i = 1; i <= days[days.size() - 1];i++) {
			if (days[index] == i) {
				int cost = INT_MAX;
				int oneDayAgo = i - 1 < 0 ? 0 : i - 1;
				int sevenDayAgo = i - 7 < 0 ? 0 : i - 7;
				int thirtyDayAgo = i - 30 < 0 ? 0 : i - 30;
				cost = min(dp[oneDayAgo] + costs[0],cost);
				cost = min(dp[sevenDayAgo] + costs[1], cost);
				cost = min(dp[thirtyDayAgo] + costs[2], cost);
				dp[i] = cost;
				index++;
			}
			else
			{
				dp[i] = dp[i - 1];
			}
		}
		return dp[days[days.size() - 1]];
	}
};

int main() {
	Solution sol;
	vector<int> a = { 1, 4, 6, 7, 8, 20 };
	vector<int> b = { 2, 7, 15 };
	sol.mincostTickets(a,b);
}
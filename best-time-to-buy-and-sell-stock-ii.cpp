#include"headfile.h"
using namespace std;

class Solution {
public:
	//greedy
	//also can do with dp
	int maxProfit(vector<int>& prices) {
		int ans = 0;
		for (int i = 2; i < prices.size(); i++) {
			if (prices[i] > prices[i-1])
			{
				ans += prices[i] - prices[i - 1];
			}
		}
		return ans;
	}
};
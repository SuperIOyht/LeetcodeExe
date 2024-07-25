#include"headfile.h"
using namespace std;

class Solution {
public:
	vector<vector<int>> findContinuousSequence(int target) {
		vector<vector<int>> ans;
		if (target < 3) {
			return ans;
		}
		int size = (target + 1) / 2;
		int low = 1, high = 2;
		int sum = low + high;
		vector<int> temp = { 1,2 };
		while (low != high && high <= size)
		{
			if (sum == target) {
				ans.push_back(temp);
				high++;
				sum += high;
				temp.push_back(high);
			}
			if (sum > target) {
				sum -= low;
				temp.erase(temp.begin());
				low++;
			}
			if (sum < target) {
				high++;
				sum += high;
				temp.push_back(high);
			}
		}
		return ans;
	}
};


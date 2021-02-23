#include"headfile.h"
using namespace std;

class Solution {
public:
	bool PredictTheWinner(vector<int>& nums) {
		if (nums.size() % 2 == 0)
		{
			return true;
		}
		else
		{
			return total(nums, 0, nums.size() - 1, 1) >= 0;
		}
	}
	int total(vector<int> &nums, int begin, int end, int turn) {
		if (begin == end) {
			return nums[begin] * turn;
		}
		int beginScore = nums[begin] * turn + total(nums, begin + 1, end, -turn);
		int endScore = nums[end] * turn + total(nums, begin, end - 1, -turn);
		if (turn == -1) {
			return min(beginScore, endScore);
		}
		else
		{
			return max(beginScore, endScore);
		}
	}
};

int main() {
	Solution s;
	vector<int> a = { 1,5,2 };
	s.PredictTheWinner(a);
	return 0;
}
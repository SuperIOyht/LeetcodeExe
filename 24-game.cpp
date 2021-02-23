#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	static constexpr double EX = 0.000001;

	bool judgePoint24(vector<int>& nums) {
		vector<double> temp;
		for (int i = 0; i < nums.size(); i++) {
			temp.push_back(double(nums[i]));
		}
		return it(temp);
	}
	bool it(vector<double> nums) {
		if (nums.size() == 1) {
			return abs(nums[0] - 24) < EX;
		}
		for (int i = 0; i < nums.size(); i++) {
			for (int j = 0; j < nums.size(); j++) {
				if (i != j) {
					vector<double> nextNums;
					for (int k = 0; k < nums.size(); k++) {
						if (k != i && k != j) {
							nextNums.push_back(nums[k]);
						}
					}
					//+
					nextNums.push_back(nums[i] + nums[j]);
					if (it(nextNums)) {
						return true;
					}
					nextNums.pop_back();
					//-
					nextNums.push_back(nums[i] - nums[j]);
					if (it(nextNums)) {
						return true;
					}
					nextNums.pop_back();
					nextNums.push_back(nums[j] - nums[i]);
					if (it(nextNums)) {
						return true;
					}
					nextNums.pop_back();
					//*
					nextNums.push_back(nums[i] * nums[j]);
					if (it(nextNums)) {
						return true;
					}
					nextNums.pop_back();
					// /
					if (nums[i] != 0) {
						nextNums.push_back(nums[j] / nums[i]);
						if (it(nextNums)) {
							return true;
						}
						nextNums.pop_back();
					}
					if (nums[j] != 0) {
						nextNums.push_back(nums[i] / nums[j]);
						if (it(nextNums)) {
							return true;
						}
						nextNums.pop_back();
					}
				}
			}
		}
		return false;
	}
};
int main() {
	Solution s;
	vector<int> a = { 4,1,8,7 };
	s.judgePoint24(a);
	return 0;
}
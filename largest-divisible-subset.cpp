#include"headfile.h"
using namespace std;

class Solution {
public:
	vector<int> largestDivisibleSubset(vector<int>& nums) {
		int size = nums.size();
		sort(nums.begin(), nums.end());
		vector<vector<int>> temp(size);
		for (int i = 0; i < size; i++) {
			temp[i] = vector<int>(1, nums[i]);
			for (int j = i-1; j >-1 ; j--) {
				int ssize = temp[j].size();
				if (nums[i] % temp[j][ssize - 1] == 0) {
					if (temp[j].size() + 1 > temp[i].size()) {
						temp[i] = temp[j];
						temp[i].push_back(nums[i]);
						break;
					}
				}
			}
		}
		vector<int> max;
		for (auto it : temp) {
			if (max.size() <= it.size()) {
				max = it;
			}
		}
		return max;
	}
};
int main() {
	Solution s;
	vector<int> a = { 3,4,16,8 };
	s.largestDivisibleSubset(a);
	return 0;
}
#include"headfile.h"
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> ans;
		unordered_map<int, int> map;
		for (int i = 0; i < nums.size(); i++) {
			auto it = map.find(target - nums[i]);
			if (it != map.end()) {
				return { it->second,i };
			}
			map[nums[i]] = i;
		}	
		return ans;
	}
};

int main() {
	vector<int> a = { 3,2,4 };
	Solution s;
	s.twoSum(a, 6);
}
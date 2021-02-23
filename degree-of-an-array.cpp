#include"headfile.h"
using namespace std;

class Solution {
public:
	int findShortestSubArray(vector<int>& nums) {
		unordered_map<int, int> hash;
		vector<pair<int, int>> temp;
		for (int i = 0; i < nums.size(); i++) {
			hash[nums[i]]++;
		}
		for (auto& it : hash) {
			temp.emplace_back(it);
		}
		sort(temp.begin(), temp.end(), [](pair<int, int>& a, pair<int, int>& b) {return a.second > b.second; });
		auto left = find_first_of(nums.begin(), nums.end(), temp.begin(), temp.begin(), [](int& a, pair<int, int>&b) {return a == b.first; });
		auto right = find_end(nums.begin(), nums.end(), temp.begin(), temp.begin(), [](int& a, pair<int, int>&b) {return a == b.first; });
		return right-left;
	}
};

int main() {
	Solution s;
	vector<int> a({ 1, 2, 2, 3, 1 });
	s.findShortestSubArray(a);
}
#include"headfile.h"
using namespace std;
class Solution {
public:
	int longestSubarray(vector<int>& nums, int limit) {
		multiset<int> set;
		int left = 0, right = 0;
		int cur_ans = 0;
		int ans = 0;
		int size = nums.size();
		while (right < size)
		{
			set.insert(nums[right]);
			if (abs(*set.rbegin() - *set.begin()) > limit) {
				set.erase(set.find(nums[left++]));
			}
			ans = std::max(ans, right - left + 1);
			right++;
		}
		return ans;
	}
};

int main() {
	Solution s;
	vector<int>a({ 4,2,2,2,4,4,2,2 });
	s.longestSubarray(a, 0);
}
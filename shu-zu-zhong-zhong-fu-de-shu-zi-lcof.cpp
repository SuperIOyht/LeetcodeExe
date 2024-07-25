#include"headfile.h"
using namespace std;

class Solution {
public:
	int findRepeatNumber(vector<int>& nums) {
		unordered_map<int, int> hash;
		for (auto& it : nums) {
			if (hash.count(it)) {
				return it;
			}
			else
			{
				hash[it] = 1;
			}
		}
	}
};
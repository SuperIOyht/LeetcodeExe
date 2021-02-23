#include<vector>
using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int res = 0;
		for (int i : nums) {
			res ^= i;
		}
		return res;
	}
};
//异或运算，
//相同数的异或值为0
//0与任何数异或的值为原数
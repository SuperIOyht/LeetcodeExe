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
//������㣬
//��ͬ�������ֵΪ0
//0���κ�������ֵΪԭ��
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	bool checkSubarraySum(vector<int>& nums, int k) {
		vector<int> sumArray;
		for (int i = 0; i < nums.size(); i++) {
			for (int j = 0; j < i ; j++) {
				sumArray[j] += nums[i];
				if (k != 0) {
					if (sumArray[j] % k == 0) {
						return true;
						break;
					}
				}
				else
				{
					if (sumArray[j] == 0) {
						return true;
						break;
					}
				}
			}
			sumArray.push_back(nums[i]);
		}
		return false;
	}
};
int main() {
	vector<int> nums = { 0,1,0 };
	Solution a;
	bool i =  a.checkSubarraySum(nums, 0);
	cout << i;
	system("pause");
	return 0;
}
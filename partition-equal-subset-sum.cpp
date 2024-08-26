#include<vector>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int> nums) {
        return func(0, 0, 0, nums);
    }
    bool func(int sum1, int sum2, int pos, vector<int>& nums) {
        if (pos == nums.size()) {
            if (sum1 == sum2) {
                return true;
            }
            else {
                return false;
            }
        }
        return func(sum1 + nums[pos], sum2, pos + 1, nums) || func(sum1, sum2 + nums[pos], pos + 1, nums);
    }
};

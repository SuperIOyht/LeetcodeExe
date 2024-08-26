#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int> nums) {
        vector<long> dpmax(nums.size(), INT_MIN), dpmin(nums.size(), INT_MAX);
        dpmax[0] = nums[0];
        dpmin[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            dpmax[i] = max(dpmax[i - 1] * nums[i], max((long)nums[i], nums[i] * dpmin[i - 1]));
            dpmin[i] = min(dpmin[i - 1] * nums[i], min((long)nums[i], nums[i] * dpmax[i - 1]));
        }
        return *max_element(dpmax.begin(), dpmax.end());
    }
};

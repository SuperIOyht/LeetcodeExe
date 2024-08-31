#include<vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int s = nums.size();
        vector<int> pre_pro(s, 1);
        vector<int> post_pro(s, 1);
        int pre_pro_val = 1, pos_pro_val = 1;
        for (int i = 1; i < s; ++i) {
            pre_pro_val *= nums[i - 1];
            pre_pro[i] = pre_pro_val;
            pos_pro_val *= nums[s - i];
            post_pro[s - 1 - i] = pos_pro_val;
        }
        for (int i = 0; i < nums.size(); ++i) {
            pre_pro[i] = pre_pro[i] * post_pro[i];
        }
        return pre_pro;
    }
};
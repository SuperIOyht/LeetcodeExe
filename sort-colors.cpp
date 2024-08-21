#include"headfile.h"

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int point = 1;
        int size = nums.size();
        if (size == 1) return;
        for (;point < size;) {
            if (nums[point - 1] > nums[point]) {
                for (int i = 0; i < point; ++i) {
                    if (nums[i] > nums[point]) {
                        swap(nums[i], nums[point]);
                        break;
                    }
                }
            }
            else {
                ++point;
            }
        }
    }
};
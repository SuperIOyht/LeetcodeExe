#include<vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res = { -1,-1 };
        int left = 0, right = nums.size() - 1;
        int mid;
        while (left <= right) {
            mid = (left + right) / 2;
            if (nums[mid] > target) {
                right = mid - 1;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else if (nums[mid] == target) {
                break;
            }
        }
        int res_left = mid, res_right = mid;
        while (res_left >= 0) {
            if (nums[res_left] == target) {
                res[0] = res_left;
                res_left--;
            }
            else {
                break;
            }
        }
        while (res_right <= nums.size() - 1) {
            if (nums[res_right] == target) {
                res[1] = res_right;
                res_right++;
            }
            else {
                break;
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> a = { 5,7,7,8,8,10 };
    s.searchRange(a, 6);
}
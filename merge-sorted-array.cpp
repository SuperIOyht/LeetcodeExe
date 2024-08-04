#include<vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0) {
            return;
        }
        int point1 = 0, point2 = 0;
        while (point1 < m) {
            if (nums1[point1] > nums2[point2]) {
                swap(nums1[point1], nums2[point2]);
                sort(nums2, point2);
            }
            point1++;
        }
        while (point1 < m+n) {
            nums1[point1] = nums2[point2];
            point1++;
            point2++;
        }
    }
    void sort(vector<int>& nums, int start) {
        while (start < nums.size() - 1) {
            if (nums[start] <= nums[start + 1]) {
                return;
            }
            else {
                swap(nums[start], nums[start + 1]);
                ++start;
            }
        }
    }
};


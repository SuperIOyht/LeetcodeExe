#include<vector>
#include<numeric>
using namespace std;

class Solution {
public:
    void rotate(vector<int> nums, int k) {
        int n = nums.size();
        k = k % n;
        if (k == 0) {
            return;
        }
        int lcm_k = lcm(k, n) / k;
        for (int i = 0; i < n / lcm_k; ++i) {
            int temp = nums[i];
            int pre = i;
            for (int j = 0; j < lcm_k / k; ++j) {
                int next = (pre + k) % n;
                swap(nums[next], temp);
                pre = next;
            }
        }
    }
};

int main() {
    Solution s;
    s.rotate(vector<int>{1, 2, 3, 4, 5, 6, 7}, 3);
}
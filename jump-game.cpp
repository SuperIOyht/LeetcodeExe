#include<vector>
#include<queue>
using namespace std;


class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        if (size == 1) {
            return true;
        }
        int top_pos = 0;
        for (int pos = 0; pos <= top_pos; ++pos) {
            if (top_pos >= size - 1) {
                return true;
            }
            top_pos = std::max(top_pos, pos + nums[pos]);
        }
        return false;
        //std::queue<int> arrv_pos;
        //arrv_pos.push(0);
        //while (!arrv_pos.empty())
        //{
        //    int now_pos = arrv_pos.front();
        //    arrv_pos.pop();
        //    for (int jump_len = 0; jump_len <= nums[now_pos]; jump_len++) {
        //    }
        //}
    }
};
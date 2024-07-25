#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> result;
        result.reserve(m * n);
        int loop_time = std::min(m, n) % 2 ? std::min(m, n)/2 + 1: std::min(m, n) / 2;
        int left = 0, right = n -1 , top = 0, bottom = m -1;
        for (int i = 0; i < loop_time; ++i) {
            int top_now = top + i;
            int bottom_now  = bottom - i;
            int left_now = left + i;
            int right_now = right - i;
            //top row
            for (int temp = left_now ; temp <= right_now; temp++) {
                result.push_back(matrix[top_now][temp]);
            }
            //right col
            for (int temp = top_now + 1; temp <= bottom_now; temp++) {
                result.push_back(matrix[temp][right_now]);
            }
            //bottom row
            for (int temp = right_now - 1; temp >= left_now && top_now != bottom_now; temp--) {
                result.push_back(matrix[bottom_now][temp]);
            }
            //left col
            for (int temp = bottom_now - 1; temp > top_now && right_now!=left_now; temp--) {
                result.push_back(matrix[temp][left_now]);
            }
        }
        return result;
    }
};

//int main() {
//    vector<vector<int>> matrix = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };
//    Solution s;
//    s.spiralOrder(matrix);
//}
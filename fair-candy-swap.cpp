#include"headfile.h"
using namespace std;

class Solution {
public:
	vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
		vector<int> ans;
		sort(A.begin(), A.end());
		sort(B.begin(), B.end());
		int sum_A = accumulate(A.begin(), A.end(), 0);
		int sum_B = accumulate(B.begin(), B.end(), 0);
		int target = (sum_A - sum_B) / 2;
		int point_A = 0;
		int point_B = 0;
		int len_A = A.size();
		int len_B = B.size();
		while (point_A < len_A && point_B < len_B)
		{
			int cur = A[point_A] - B[point_B];
			if (cur == target) {
				ans.push_back(A[point_A]);
				ans.push_back(B[point_B]);
				break;
			}
			else if (cur < target) {
				++point_A;
			}
			else if (cur > target) {
				++point_B;
			}
		}
		return ans;
	}
};
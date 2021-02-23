#include"headfile.h"
using namespace std;

class Solution {
public:
	int longestOnes(vector<int>& A, int K) {
		int size = A.size();
		int left = 0, right = 0;
		int ans = 0;
		int re_K = K;
		int cur_ans = 0;
		while (right < size)
		{
			if (A[right] == 1) {
				++cur_ans;
				++right;
			}
			else if (A[right] == 0) {
				if (re_K > 0) {
					--re_K;
					++cur_ans;
					++right;
				}
				else
				{
					ans = max(ans, cur_ans);
					if (A[left] == 0) {
						++re_K;
					}
					--cur_ans;
					++left;
				}
			}
		}
		return max(cur_ans,ans);
	}
};

int main() {
	vector<int> A({ 0,0,0,1 });
	Solution s;
	s.longestOnes(A, 4);
}
#include"headfile.h"
using namespace std;


class Solution {
public:
	int atMostWithKDistance(vector<int>& A, int K) {
		int n = A.size();
		int left = 0, right = 0;
		int count = 0;
		int res = 0;
		vector<int> freq(n+1, 0);
		while (right < n)
		{
			if (freq[A[right]] == 0) {
				count++;
			}
			freq[A[right]]++;
			right++;
			while (count > K) {
				freq[A[left]]--;
				if (freq[A[left]] == 0) {
					count--;
				}
				left++;
			}
			res += right - left;
		}
		return res;
	}
	int subarraysWithKDistinct(vector<int>& A, int K) {
		return atMostWithKDistance(A, K) - atMostWithKDistance(A, K - 1);
	}
};

int main()
{
	Solution s;
	vector<int> a({ 1,2,1,2,3 });
	s.subarraysWithKDistinct(a, 2);
}
#include"headfile.h"
using namespace std;

class Solution {
public:
	void merge(vector<int>& A, int m, vector<int>& B, int n) {
		int size = m + n - 1;
		m--;
		n--;
		while (m >= 0 && n >= 0) {
			if (A[m] > B[n]) {
				A[size] = A[m];
				m--;
			}
			else
			{
				A[size] = B[n];
				n--;
			}
			size--;
		}
		while (m >=0)
		{
			A[size] = A[m];
			m--;
			size--;
		}
		while (n >= 0)
		{
			A[size] = B[n];
			n--;
			size--;
		}
	}
};


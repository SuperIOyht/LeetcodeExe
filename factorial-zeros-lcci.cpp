#include"headfile.h"
using namespace std;
class Solution {
public:
	int trailingZeroes(int n) {
		int res = 0;
		int logn = log(n) / log(5);
		for (int i = 1; i <= logn; i++)
		{
			res += n / pow(5, i);
		}
		return res;
	}
};

int main() {
	Solution s;
	s.trailingZeroes(125);
}
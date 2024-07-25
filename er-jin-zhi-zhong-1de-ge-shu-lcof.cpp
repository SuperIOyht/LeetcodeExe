#include"headfile.h"
using namespace std;

class Solution {
public:
	int hammingWeight(uint32_t n) {
		int sum = 0;
		while (n != 0)
		{
			n &= n - 1;
			++sum;
		}
		return sum;
	}
};
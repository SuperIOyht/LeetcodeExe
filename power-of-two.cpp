#include<iostream>
#include<cmath>
#include<bitset>
using namespace std;

class Solution {
public:
	bool isPowerOfTwo(int n) {
		return n > 0 && (n & n - 1) == 0;
	}
};

int main() {
	Solution s;
	s.isPowerOfTwo(1024);
	return 0;
}
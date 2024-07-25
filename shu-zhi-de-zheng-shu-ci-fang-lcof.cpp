#include"headfile.h"
using namespace std;

class Solution {
public:
	double myPow(double x, int n) {
		if (n == 0) {
			return 1;
		}
		if (x == 0) {
			return 0;
		}
		return getPow(x, n);
	}
	double getPow(double x, int n) {
		if (n == 0) {
			return 1;
		}
		if (n == 1) {
			return x;
		}
		if (n == -1) {
			return 1 / x;
		}
		double a = getPow(x, n / 2);
		return a * a * getPow(x, n % 2);
	}
};

int main() {
	Solution s;
	s.myPow(2.10000,3);
}
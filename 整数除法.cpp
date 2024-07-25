#include"headfile.h"
using namespace std;

class Solution {
public:
	int divide(int a, int b) {
		int result = 0;
		if (a == 0) {
			return result;
		}
		bool flag = false;
		if (a < 0 ^ b < 0) {
			flag = true;
		}
		a = abs(a);
		b = abs(b);
		while (a > b) {
			a -= b;
			result++;
		}
		if (flag) {
			result = -result;
		}
		return result;
	}
};
int main() {
	Solution a;
	a.divide(
		-2147483648, -1);
}
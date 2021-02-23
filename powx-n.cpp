#include<iostream>
using namespace std;
//¶þ·Ö·¨
class Solution {
public:
	double myPow(double x, int n) {
		double multi;
		if (n == 0) {
			return 1.0;
		}
		else if (n == 1) {
			return x;
		}
		else if(n == -1)
		{
			return 1 / x;
		}
		if (n > 1) {
			if (n % 2 == 1) {
				return myPow(x, n / 2) * myPow(x, n / 2 + 1);
			}
			else
			{
				multi = myPow(x, n / 2);
				return multi * multi;
			}
		}
		else if (n < -1) {
			if (n % 2 == -1) {
				return myPow(x, n / 2) * myPow(x, n / 2 - 1);
			}
			else
			{
				multi = myPow(x, n / 2);
				return multi * multi;
			}
		}
	}
};
int main() {
	Solution a;
	cout << a.myPow(34.00515
		,- 3);
	system("pause");
}
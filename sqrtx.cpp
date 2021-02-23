#include<iostream>
using namespace std;
class Solution {
public:
	int mySqrt(int x) {
		int  left = 0, right = x;
		long mid;
 		while (right >= left)
		{
			mid = left + (right - left) / 2;
			unsigned long int square = mid * mid ;
			if (square == x) {
				return mid;
			}
			else if (square < x) {
				left = mid + 1;
			}
			else if (square > x) {
				right = mid - 1;
			}
		}
		return right;
	}
};
int main() {
	Solution sol;
	int b = sol.mySqrt(6);
	int a = sol.mySqrt(2147395599);
	system("pause");
}
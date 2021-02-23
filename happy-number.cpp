#include<iostream>
using namespace std;

class Solution {
public:
	bool isHappy(int n) {
		int fast = n, slow = n;
		do
		{
			fast = opNum(fast);
			fast = opNum(fast);
			slow = opNum(slow);
		} while (fast != slow);
		return slow == 1;
	}
	int opNum(int n) {
		int res = 0;
		while (n != 0)
		{
			res += (n % 10)*(n % 10);
			n = n / 10;
		}
		return res;
	}
};
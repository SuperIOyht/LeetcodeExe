#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int rangeBitwiseAnd(int m, int n) {
		while (m<=n)
		{
			n = n & (n - 1);
		}
		return n;
	}
};
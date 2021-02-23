#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	bool canWinNim(int n) {
		return (n % 4 != 0);
	}
};

int main() {
	Solution s;
	bool a = s.canWinNim(100);
	cout << a;
	system("pause");
}


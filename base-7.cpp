#include"headfile.h"
using namespace std;


class Solution {
public:
	string convertToBase7(int num) {
		string ans;
		bool flag = false;
		if (num < 0) {
			flag = true;
			num = abs(num);
		}
		ans.append(to_string(num % 7));
		if (num >= 7) {
			if (num / 7 > 7) {
				ans.insert(0, convertToBase7(num / 7));
			}
			else
			{
				ans.insert(0, convertToBase7(num / 7));
			}
		}
		if (flag) {
			ans.insert(0, "-");
		}
		return ans;
	}
};

int main() {
	Solution s;
	s.convertToBase7(100);
}
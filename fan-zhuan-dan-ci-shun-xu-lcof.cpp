#include"headfile.h"
using namespace std;
class Solution {
public:
	string reverseWords(string s) {
		string ans;
		s.erase(0, s.find_first_not_of(' '));
		s.erase(s.find_last_not_of(' ')+1);
		s.insert(s.begin(), ' ');
		int size = s.size();
		int high = size -1, low= size - 1;
		while (low >= 0) {
			if (s[low] == ' ')
			{
				for (int i = low + 1; i <= high; ++i) {
					ans.push_back(s[i]);
				}
				ans.push_back(' ');
				while (s[low] == ' ') {
					low--;
				}
				high = low ;
				continue;
			}
			low--;
		}
		ans.erase(ans.end()-1);
		return ans;
	}
};

int main() {
	Solution s;
	s.reverseWords("  the sky is   blue  ");
}
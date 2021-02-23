#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		vector<string> ans;
		ipAddress(s, 1, ans, "", 0, 1);
		for (int i = 0; i < ans.size(); i++) {
			ans[i].pop_back();
		}
		return ans;
	}
	void ipAddress(string s,int num,vector<string>& ans,string temp,int left,int right) {
		if (num == 5 && right > s.size()) {
			ans.insert(ans.begin(),temp);
		}
		else if (num < 5)
		{
			if (right <= s.size()) {
				string subString = s.substr(left, right - left);
				int ippart = stoi(subString);
				if (ippart <= 255 && !(subString.substr(0,1) == "0" && subString.size() > 1)) {
					ipAddress(s, num, ans,temp,left,right+1);
					temp += s.substr(left, right - left) +".";
					ipAddress(s, num + 1, ans, temp, right, right + 1);
				}
			}
		}
	}
};

int main() {
	Solution s;
	s.restoreIpAddresses("010010");
	return 0;
}
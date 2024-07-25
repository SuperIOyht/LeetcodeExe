#include"headfile.h"
using namespace std;

class Solution {
public:
	void splite(string IP, vector<string>& strs, const char delim) {
		istringstream sstream(IP);
		string temp;
		while (getline(sstream, temp, delim))
		{
			strs.push_back(temp);
		}
		if (!IP.empty() && IP.back() == delim) {
			strs.push_back("");
		}
	}
	bool valid_IPv6(string IP) {
		vector<string> strs;
		splite(IP, strs, ':');
		if (strs.size() != 8) {
			return false;
		}
		for (auto it : strs) {
			if (it.empty() || it.size() > 4) {
				return false;
			}
			for (auto c : it) {
				if (!(isdigit(c) || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'))) {
					return false;
				}
			}
		}
		return true;
	}
	bool valid_IPv4(string IP) {
		vector<string> strs;
		splite(IP, strs, '.');
		if (strs.size() != 4) {
			return false;
		}
		for (auto it : strs) {
			if (it.empty() || (it.size() > 1 && it[0] == '0') || it.size() > 3) {
				return false;
			}
			for (auto c : it) {
				if (!isdigit(c)) {
					return false;
				}
			}
			int num = stoi(it);
			if (num < 0 || num >255) {
				return false;
			}
		}
		return true;
	}
	string validIPAddress(string IP) {
		if (valid_IPv4(IP)) {
			return "IPv4";
		}
		else if (valid_IPv6(IP)) {
			return "IPv6";
		}
		else
		{
			return "Neither";
		}
	}
};
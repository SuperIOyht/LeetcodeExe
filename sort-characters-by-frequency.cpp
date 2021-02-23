#include<iostream>
#include<unordered_map>
#include<queue>
using namespace std;

class Solution {
public:
	string frequencySort(string s) {
		unordered_map<char, int> charMap;
		for (int i = 0; i < s.size(); i++) {
			if (charMap.count(s[i])) {
				++charMap[s[i]];
			}
			else
			{
				charMap[s[i]] = 1;
			}
		}
		priority_queue<pair<int, char>> pq;
		for (const auto &n : charMap) {
			pq.push({ n.second,n.first });
		}
		string ans = "";
		while (!pq.empty())
		{
			for (int i = 0; i < pq.top().first; i++) {
				ans += pq.top().second;
			}
			pq.pop();
		}
		return ans;
	}
};
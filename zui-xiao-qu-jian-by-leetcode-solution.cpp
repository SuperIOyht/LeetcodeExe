#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<int> smallestRange(vector<vector<int>>& nums) {
		unordered_map<int, vector<int>> indices;
		int numMax = INT_MAX, numMin = INT_MIN;
		for (int i = 0; i < nums.size(); i++) {
			for(const int& x:nums[i]){
				indices[x].push_back(i);
				numMax = max(numMax,x);
				numMin = min(numMin, x); 
			}
		}

	}
};
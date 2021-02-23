//给你一个数组 candies 和一个整数 extraCandies ，其中 candies[i] 代表第 i 个孩子拥有的糖果数目。
//
//对每一个孩子，检查是否存在一种方案，将额外的 extraCandies 个糖果分配给孩子们之后，此孩子有 最多 的糖果。注意，允许有多个孩子同时拥有 最多 的糖果数目。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/kids-with-the-greatest-number-of-candies
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
		vector<bool> ans;
		int max = -1;
		for (int i = 0; i < candies.size(); i++) {
			if (candies[i] > max) {
				max = candies[i];
			}
		}
		for (int j = 0; j < candies.size(); j++)
		{
			if (candies[j] + extraCandies >= max) {
				ans.push_back(true);
			}
			else
			{
				ans.push_back(false);
			}
		}
		return ans;
	}
};

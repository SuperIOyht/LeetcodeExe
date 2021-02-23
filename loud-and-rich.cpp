#include<vector>
#include<stack>
#include<iostream>
#include<algorithm>
using namespace std;

/*
class Solution {
public:
	vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
		int n = quiet.size();
		vector<vector<int>> de(n);
		vector<int> ans(n,501);
		int max = INT_MAX;
		for (int i = 0; i < n; i++) {
			if (de[i].empty()) {
				dfs(i, de, n, richer);
			}
			max = INT_MAX;
			for (int j = 0; j < de[i].size(); j++) {
				if (max > quiet[de[i][j]]) {
					max = quiet[de[i][j]];
					ans[i] = de[i][j];
				}
			}
		}
		return ans;
	}
	void dfs(int no,vector<vector<int>>& de, int size, vector<vector<int>>& richer) {
		de[no].push_back(no);//再结果集中加入自己
		//遍历所有
		for (int i = 0; i < richer.size(); i++) {
			//找到所有比自己大的人
			if (richer[i][1] == no) {
				//如果结果集中没有,则递归
				if (de[richer[i][0]].empty()) {
					dfs(richer[i][0], de, size, richer);
					//合并vector
				}
				//合并vector
				de[no].insert(de[no].end(), de[richer[i][0]].begin(), de[richer[i][0]].end());
			}
		}
	}
};
*/

struct pa
{
	int val;
	bool isOver;
	pa(int val = 0, bool isOver = false) :val(val), isOver(isOver) {};
};
class Solution {
public:
	vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
		int n = quiet.size();
		vector<pa> ans(n);
		for (int i = 0; i < n; i++) {
			if (!ans[i].isOver) {
				dfs(i, ans, quiet, richer);
			}
		}
		vector<int> res;
		for (int i = 0; i < ans.size(); i++) {
			res.push_back(ans[i].val);
		}
		return res;
	}
	void dfs(int no, vector<pa>& ans, vector<int>& quiet, vector<vector<int>>& richer) {
		ans[no].val = no;//
		//遍历所有
		for (int i = 0; i < richer.size(); i++) {
			//找到所有比自己大的人
			if (richer[i][1] == no) {
				//如果结果集中没有,则递归找到结果
				if (!ans[richer[i][0]].isOver) {
					dfs(richer[i][0], ans, quiet, richer);
				}
				//自己与找到的对比quite的值
				if (quiet[ans[no].val] > quiet[ans[richer[i][0]].val]) {
					ans[no].val = ans[richer[i][0]].val;
				}
			}
		}
		ans[no].isOver = true;
	}
};


int main() {
	Solution s;
	vector<vector<int>> a = { {1,0},{2,1},{3,1},{3,7},{4,3},{5,3},{6,3} };
	vector<int> b = { 3,2,5,4,6,1,7,0 };
	vector<int> c = s.loudAndRich(a, b);
	return 0;
}
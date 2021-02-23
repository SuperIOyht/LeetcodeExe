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
		de[no].push_back(no);//�ٽ�����м����Լ�
		//��������
		for (int i = 0; i < richer.size(); i++) {
			//�ҵ����б��Լ������
			if (richer[i][1] == no) {
				//����������û��,��ݹ�
				if (de[richer[i][0]].empty()) {
					dfs(richer[i][0], de, size, richer);
					//�ϲ�vector
				}
				//�ϲ�vector
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
		//��������
		for (int i = 0; i < richer.size(); i++) {
			//�ҵ����б��Լ������
			if (richer[i][1] == no) {
				//����������û��,��ݹ��ҵ����
				if (!ans[richer[i][0]].isOver) {
					dfs(richer[i][0], ans, quiet, richer);
				}
				//�Լ����ҵ��ĶԱ�quite��ֵ
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
#include<queue>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
//Ñî»ÔÈý½Ç
class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		queue<int> line;
		int temp;
		vector<vector<int>> ans;
		if (numRows == 0)
		{
			return ans;
		}
		else
		{
			ans.push_back(vector<int>{1});
			line.push(1);
			for (int i = 1; i < numRows; i++) {
				line.push(1);
				ans.push_back(vector<int>{1});
				for (int j = 1; j < i ; j++) {
					temp = line.front();
					line.pop();
					line.push(temp + line.front());
					ans[i].push_back(temp + line.front());
				}
				line.push(1);
				ans[i].push_back(1);
				line.pop();
			}
			return ans;
		}	
	}
};

int main() {
	Solution a;
	a.generate(5);
}

#include"headfile.h"
using namespace std;

class Solution {
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		vector<vector<int>> adjacent(numCourses);
		vector<int> indegree(numCourses, 0);
		queue<int> mQueue;
		int num = numCourses;
		for (auto& it : prerequisites) {
			adjacent[it[1]].push_back(it[0]);
			++indegree[it[0]];
		}
		for (int i = 0; i < numCourses; ++i) {
			if (indegree[i] == 0) {
				mQueue.push(i);
				--num;
			}
		}
		while (!mQueue.empty())
		{
			int temp = mQueue.front();
			mQueue.pop();
			for (int i = 0; i < adjacent[temp].size(); ++i) {
				--indegree[adjacent[temp][i]];
				if (indegree[adjacent[temp][i]] == 0) {
					mQueue.push(adjacent[temp][i]);
					--num;
				}
			}
		}
		if (num == 0) {
			return true;
		}
		return false;
	}
};
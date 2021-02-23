#include"headfile.h"
using namespace std;

class Solution {
public:
	unordered_map<int, int> roomMap;
	bool canVisitAllRooms(vector<vector<int>>& rooms) {
		for (int i = 0; i < rooms.size(); i++)
		{
			roomMap[i] = 1;
		}
		dfs(0, rooms);
		return roomMap.empty();
	}
	void dfs(int num, vector<vector<int>>& rooms) {
		roomMap.erase(num);
		for (auto& it : rooms[num]) {
			if (roomMap.count(it))
			{
				dfs(it, rooms);
			}
		}
	}
};

int main() {
	Solution s;
	vector<vector<int>> a = { {1},{2},{3},{} };
	s.canVisitAllRooms(a);
}

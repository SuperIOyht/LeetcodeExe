#include"headfile.h"

using namespace std;
class Solution {
public:
	unordered_map<string, priority_queue<string, vector<string>, std::greater<string>>> vec;
	vector<string> ans;
	vector<string> findItinerary(vector<vector<string>>& tickets) {
		for (auto& it : tickets) {
			vec[it[0]].emplace(it[1]);
		}
		dfs("JFK");
		reverse(ans.begin(), ans.end());
		return ans;
	}
	void dfs(const string& from) {
		while (vec.count(from) && vec[from].size() > 0) {
			string tmp = vec[from].top();
			vec[from].pop();
			dfs(move(tmp));
		}
		ans.emplace_back(from);
	}
};

int main() {
	Solution s;
	vector<vector<string>> b = { {"JFK", "BBB"},{"JFK", "AAA"},{"BBB", "JFK"} };
	s.findItinerary(b);
	return 0;
}
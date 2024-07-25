#include<unordered_map>
using namespace std;

int solution(vector<int> &A) {
	// write your code in C++14 (g++ 6.2.0)
	unordered_map<int, int> hash;
	for (const auto& it : A) {
		if (hash.count(it)) {
			++hash[it];
		}
		else
		{
			hash[it] = 1;
		}
	}
	int ans = 0;
	while (true)
	{
		if (!hash.count(ans)) {
			return ans;
		}
		else
		{
			++ans;
		}
	}
}
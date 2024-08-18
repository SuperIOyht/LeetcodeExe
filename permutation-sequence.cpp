#include<vector>
#include<string>

using namespace std;
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> flag(n, 0);
        string res = "";
        int remain = k;
        for (int i = n - 1; i >= 0; --i) {
            int fac = factorial(i);
            int pos = ceil((double)remain / (double)fac);
            remain = remain % fac ? remain % fac : fac;
            res.push_back(find(flag, pos) + '0');
        }
        return res;

    }
    int find(vector<int>& flag, int pos) {
        for (int i = 0; i < flag.size(); ++i) {
            if (flag[i] == 0) {
                --pos;
            }
            if (0 == pos) {
                flag[i] = 1;
                return i + 1;
            }
        }
        return 0;
    }
    int factorial(int n) {
        if (n == 0) {
            return 1;
        }
        int res = 1;
        while (n > 0) {
            res *= n;
            n--;
        }
        return res;
    }
};

int main() {
    Solution s;
    s.getPermutation(3, 3);
}
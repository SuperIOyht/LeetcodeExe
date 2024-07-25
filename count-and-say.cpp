#include<string>
using namespace std;


class Solution {
public:
    string countAndSay(int n) {
        if (1 == n) {
            return "1";
        }
        string pre = countAndSay(n - 1);
        char pre_char =pre[0];
        int count = 0;
        string res;
        for (auto ch : pre) {
            if (pre_char == ch) {
                count++;
            }
            else {
                char count_char = count + '0';
                res += count_char;
                res += pre_char;
                pre_char = ch;
                count = 1;
            }
        }
        char count_char = count + '0';
        res += count_char;
        res += pre_char;
        return res;
    }
};

int main() {
    Solution s;
    s.countAndSay(4);
}
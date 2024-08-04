#include<string>
using namespace std;


class Solution {
public:
    string addBinary(string a, string b) {
        int size = min(a.size(), b.size());
        string res;
        int up_num = 0;
        int i = 1;
        for (; i <= size; ++i) {
            int a_num = a[a.size() - i] - '0';
            int b_num = b[b.size() - i] - '0';
            res.push_back('0' + ((a_num + b_num + up_num) % 2));
            up_num = (a_num + b_num + up_num) / 2;
        }

        for (; i <= max(a.size(), b.size()); ++i) {
            if (a.size() > b.size()) {
                int a_num = a[a.size() - i] - '0';
                res.push_back(0+((a_num + up_num) % 2));
                up_num = (a_num + up_num) / 2;
            }
            else {
                int b_num = b[b.size() - i] - '0';
                res.push_back('0' + ((b_num + up_num) % 2));
                up_num = (b_num + up_num) / 2;
            }
        }
        res.push_back('0'+ up_num);
        std::reverse(res.begin(), res.end());
        return res;
    }
};

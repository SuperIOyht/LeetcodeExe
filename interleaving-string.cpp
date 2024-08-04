#include<string>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1 == "" && s2 == "" && s3 == "") {
            return true;
        }
        if (s1[0] != s3[0] && s2[0] != s3[0]) {
            return false;
        }
        bool _s1_first_inter = false, _s2_first_inter = false;
        if (s1 != "" && s2 != "") {
            if (s1[0] == s3[0] && s2[0] == s3[0]) {
                return isInterleave(s1.substr(1, s1.size() - 1), s2, s3.substr(1, s3.size() - 1))
                    || isInterleave(s1, s2.substr(1, s2.size() - 1), s3.substr(1, s3.size() - 1));
            }
            if (s1[0] == s3[0]) {
                for (int i = 0; i < s1.size(); ++i) {
                    if (s1[i] != s3[i]) {
                        _s1_first_inter = isInterleave(s1.substr(i, s1.size() - i), s2, s3.substr(i, s3.size() - i));
                    }
                }
            }
            if (s2[0] == s3[0]) {
                for (int i = 0; i < s2.size(); ++i) {
                    if (s2[i] != s3[i]) {
                        _s2_first_inter = isInterleave(s1, s2.substr(i, s2.size() - i), s3.substr(i, s3.size() - i));
                    }
                }
            }
        }
        if (s1 == "") {
            return s2 == s3;
        }
        if (s2 == "") {
            return s1 == s3;
        }
        return _s1_first_inter || _s2_first_inter;
    }
};

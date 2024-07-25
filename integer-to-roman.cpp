#include<unordered_map>
#include<string>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int, string> mymap = { {1,"I"}, {5, "V"}, {10, "X"}, {50, "L"}, {100, "C"}, {500, "D"}, {1000, "M"}, {4, "IV"}, {9,"IX"}, {40, "XL"}, {90, "XC"}, {400, "CD"}, {900, "CM"}};
        int diglen = 1;
        int temp = num / 10;
        while (temp) {
            temp = temp / 10;
            diglen *=10;
        }
        string next = "";
        if (num / diglen != 0 && num % diglen != 0) {
            next = intToRoman(num % diglen);
        }
        int big_num = num - num % diglen;
        string this_str = "";
        if (mymap.count(big_num)) {
            this_str += mymap[big_num];
        }
        else {
            if (big_num / diglen > 5) {
                this_str += mymap[5 * diglen];
                big_num -= diglen * 5;
            }
            for (int i = 0; i < big_num / diglen; ++i) {
                this_str += mymap[diglen];
            }
        }
        this_str += next;
        return this_str;
    }
};

int main() {
    Solution s;
    s.intToRoman(1994);
}
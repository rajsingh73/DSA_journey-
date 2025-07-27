#include <cctype>
using namespace std;
class Solution {
public:
    bool isNumber(string s) {
        int n = s.size();
        int i = 0;
        while (i < n && s[i] == ' ') i++;
        if (i < n && (s[i] == '+' || s[i] == '-')) i++;
        bool isNumeric = false;
        bool hasDot = false;
        bool hasExp = false;
        while (i < n) {
            char c = s[i];
            if (isdigit(c)) {
                isNumeric = true;
            }
            else if (c == '.') {
                if (hasDot || hasExp) return false;
                hasDot = true;
            }
            else if (c == 'e' || c == 'E') {
                if (hasExp || !isNumeric) return false;
                hasExp = true;
                isNumeric = false;
                if (i + 1 < n && (s[i + 1] == '+' || s[i + 1] == '-')) i++;
            }
            else {
                return false;
            }

            i++;
        }
        return isNumeric;
    }
};

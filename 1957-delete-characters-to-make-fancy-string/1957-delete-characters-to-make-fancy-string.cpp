class Solution {
public:
    string makeFancyString(string s) {
        string result;
        for (int i = 0; i < s.size(); i++) {
            if (result.size() < 2 || !(result[result.size() - 1] == s[i] && result[result.size() - 2] == s[i])) {
                result += s[i];
            }
        }
        
        return result;
    }
};

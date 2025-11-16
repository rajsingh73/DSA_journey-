class Solution {
public:
    int numSub(string s) {
        int n = s.size();
        long long m = 1e9+7;
        int i = 0;
        long long ans = 0;
        while (i < n) {
            if (s[i] == '0') while (i < n && s[i] == '0') i++;
            long long count = 0;
            while (i < n && s[i] == '1') {
                i++;
                count++;
            }
            long long val = (count * (count + 1)) / 2 % m;
            ans = (ans + val) % m;
        }
        return ans;
    }
};

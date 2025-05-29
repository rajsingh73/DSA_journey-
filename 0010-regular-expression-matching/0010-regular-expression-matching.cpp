class Solution {
public:
    bool solve(string &s, string &p, int first, int second, vector<vector<int>> &dp) {
        if (first < 0 && second < 0) return true;
        if (second < 0) return false;
        if (first < 0) {
            // Check if the pattern can match empty string like a*, a*b*, etc.
            if (p[second] == '*') return solve(s, p, first, second - 2, dp);
            else return false;
        }
        if (dp[first][second] != -1) return dp[first][second];

        if (p[second] == '*') {
            bool zero_occurrence = solve(s, p, first, second - 2, dp);
            bool one_or_more = (p[second - 1] == s[first] || p[second - 1] == '.') && solve(s, p, first - 1, second, dp);
            return dp[first][second] = zero_occurrence || one_or_more;
        }

        if (p[second] == s[first] || p[second] == '.') {
            return dp[first][second] = solve(s, p, first - 1, second - 1, dp);
        }

        return dp[first][second] = false;
    }

    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return solve(s, p, n - 1, m - 1, dp);
    }
};

class Solution {
public:
    bool check(int col, int row, vector<int>& r, vector<int>& upper, vector<int>& lower, int n) {
        if (r[row] == 1) return false;
        if (upper[col - row + n] == 1) return false;
        if (lower[col + row] == 1) return false;
        return true;
    }

    void solve(int col, int n, vector<string>& v, int& ans, vector<int>& r, vector<int>& upper, vector<int>& lower) {
        if (col == n) {
            ans++;
            return;
        }
        for (int i = 0; i < n; i++) {
            if (check(col, i, r, upper, lower, n)) {
                v[i][col] = 'Q';
                r[i] = 1;
                upper[col - i + n] = 1;
                lower[col + i] = 1;

                solve(col + 1, n, v, ans, r, upper, lower);

                v[i][col] = '.';
                r[i] = 0;
                upper[col - i + n] = 0;
                lower[col + i] = 0;
            }
        }
    }

    int totalNQueens(int n) {
        vector<string> v(n, string(n, '.'));
        vector<int> r(n, 0);
        vector<int> upper(2 * n, 0);
        vector<int> lower(2 * n, 0);
        int ans = 0;
        solve(0, n, v, ans, r, upper, lower);
        return ans;
    }
};

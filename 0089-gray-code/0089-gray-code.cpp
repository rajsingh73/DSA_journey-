class Solution {
public:
    bool oneBitDiff(int a, int b) {
        return __builtin_popcount(a ^ b) == 1;
    }

    bool solve(vector<int> &visited, vector<int> &ans, int n) {
        if (ans.size() == n) return true;
        for (int i = 0; i < n; ++i) {
            if (visited[i]) continue;

            if (ans.empty()) {
                if (i != 0) continue;        // force start at 0 to reduce branching
                ans.push_back(i);
            } else if (ans.size() == n - 1) {
                if (!oneBitDiff(ans[0], i)) continue; // close the cycle (optional)
                ans.push_back(i);
            } else {
                if (!oneBitDiff(ans.back(), i)) continue;
                ans.push_back(i);
            }

            visited[i] = 1;
            if (solve(visited, ans, n)) return true;
            visited[i] = 0;
            ans.pop_back();
        }
        return false;
    }

    vector<int> grayCode(int p) {
        int n = 1 << p;                      // use bit shift, not pow
        vector<int> visited(n, 0), ans;
        solve(visited, ans, n);
        return ans;
    }
};

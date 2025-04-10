class Solution {
public:
    void solve(vector<int>& digits, int& count, int value, int depth, vector<bool>& used) {
        if (depth == 3) {
            if (value % 2 == 0) {
                count++;
                cout << value << " ";
            }
            return;
        }
        for (int i = 0; i < digits.size(); ++i) {
            if (used[i]) continue;
            if (depth == 0 && digits[i] == 0) continue;
            if (i > 0 && digits[i] == digits[i - 1] && !used[i-1]) continue;
            used[i] = true;
            solve(digits, count, value * 10 + digits[i], depth + 1, used);
            used[i] = false;
        }
    }
    int totalNumbers(vector<int>& digits) {
        int count = 0;
        sort(digits.begin(), digits.end());
        vector<bool> used(digits.size(), false);
        solve(digits, count, 0, 0, used);
        return count;
    }
};

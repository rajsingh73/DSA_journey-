class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        int high = numRows - 1;
        int low = 0;
        string ans = "";
        for (int i = 0; i <= high; i++) {
            int count = 0;
            int index = i;
            while (index < s.size()) {
                ans += s[index];
                int value;
                if (i == 0 || i == high) {
                    value = 2 * high;
                } else if (count % 2 == 0) {
                    value = 2 * (high - i);
                } else {
                    value = 2 * i;
                }
                if (value == 0) {
                    count++;
                    continue;
                }
                index += value;
                count++;
            }
        }
        return ans;
    }
};

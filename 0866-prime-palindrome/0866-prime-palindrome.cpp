class Solution {
public:
    bool isPrime(int n) {
        if (n < 2) return false;
        if (n % 2 == 0) return n == 2;
        for (int i = 3; i * i <= n; i += 2) {
            if (n % i == 0) return false;
        }
        return true;
    }
    int makePalindrome(int x, bool odd) {
        string s = to_string(x);
        string rev = s;
        reverse(rev.begin(), rev.end());
        if (odd) rev.erase(0, 1);
        return stoi(s + rev);
    }
    int primePalindrome(int n) {
        if (n <= 2) return 2;
        if (n <= 3) return 3;
        if (n <= 5) return 5;
        if (n <= 7) return 7;
        if (n <= 11) return 11;
        for (int len = 1; len <= 5; ++len) {
            int start = pow(10, len - 1);
            int end = pow(10, len) - 1;
            for (int i = start; i <= end; ++i) {                       
                int pal = makePalindrome(i, true);
                if (pal >= n && isPrime(pal)) return pal;
            }
        }
        return -1;
    }
};

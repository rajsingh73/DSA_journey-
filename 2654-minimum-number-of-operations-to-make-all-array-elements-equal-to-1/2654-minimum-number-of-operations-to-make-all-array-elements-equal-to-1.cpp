#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int g = nums[0];
        for (int i = 1; i < n; i++)
            g = gcd(g, nums[i]);
        if (g != 1) return -1;

        int cnt1 = count(nums.begin(), nums.end(), 1);
        if (cnt1 > 0) return n - cnt1;

        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            int currGCD = nums[i];
            for (int j = i + 1; j < n; j++) {
                currGCD = gcd(currGCD, nums[j]);
                if (currGCD == 1) {
                    ans = min(ans, j - i + 1);
                    break;
                }
            }
        }

        return ans - 1 + (n - 1);
    }
};

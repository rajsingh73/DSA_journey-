class ATM {
public:
    vector<long long> v;
    vector<int> m;

    ATM() {
        m = {20, 50, 100, 200, 500};
        v = vector<long long>(5, 0);
    }

    void deposit(vector<int> banknotesCount) {
        for (int i = 0; i < 5; i++) {
            v[i] += banknotesCount[i];
        }
    }

    vector<int> withdraw(int amount) {
        vector<int> ans(5, 0);
        int temp = amount;
        for (int i = 4; i >= 0; i--) {
            long long take = min(v[i], (long long)amount / m[i]);
            ans[i] = take;
            amount -= take * m[i];
        }
        if (amount != 0) {
            return {-1};
        }
        for (int i = 0; i < 5; i++) {
            v[i] -= ans[i];
        }
        return ans;
    }
};


// https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/description/

class Solution {
public:
    const int MOD = 1e9+7;
    long long f(int n, vector<long long> &dp){
        if(n == 1) return 1;

        if(dp[n] != -1) return dp[n];

        return dp[n] = (f(n-1, dp) * (2*n-1) % MOD * n % MOD) %  MOD;
    }

    int countOrders(int n) {
        vector<long long> dp(n+1, -1);
        return f(n, dp);
    }
};

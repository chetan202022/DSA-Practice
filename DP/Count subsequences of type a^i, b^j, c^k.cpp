
// https://www.geeksforgeeks.org/problems/count-subsequences-of-type-ai-bj-ck4425/1?track=amazon-dynamic-programming&batchId=192

class Solution {
  public:
  
    long long mod = 1e9 + 7;

    long long f(int i, int stage, string &s, vector<vector<long long>> &dp){
        
        if(i == s.size()){
            return (stage == 3) ? 1 : 0;
        }

        if(dp[i][stage] != -1) return dp[i][stage];

        long long ans = f(i+1, stage, s, dp); // not take

        if(stage == 0 && s[i] == 'a')
            ans = (ans + f(i+1, 1, s, dp)) % mod;

        else if(stage == 1 && s[i] == 'b')
            ans = (ans + f(i+1, 2, s, dp)) % mod;

        else if(stage == 2 && s[i] == 'c')
            ans = (ans + f(i+1, 3, s, dp)) % mod;

        // allow multiple a,b,c
        if(stage == 1 && s[i] == 'a')
            ans = (ans + f(i+1, 1, s, dp)) % mod;

        else if(stage == 2 && s[i] == 'b')
            ans = (ans + f(i+1, 2, s, dp)) % mod;

        else if(stage == 3 && s[i] == 'c')
            ans = (ans + f(i+1, 3, s, dp)) % mod;

        return dp[i][stage] = ans % mod;
    }

    int fun(string &s) {
        
        int n = s.size();
        vector<vector<long long>> dp(n, vector<long long>(4, -1));
        
        return f(0, 0, s, dp);
    }
};

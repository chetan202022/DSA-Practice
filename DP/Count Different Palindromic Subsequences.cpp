
// https://leetcode.com/problems/count-different-palindromic-subsequences/description/

class Solution {
public:
    
    const long long MOD = 1e9 + 7;

    long long f(int i, int j, string &s, vector<vector<long long>> &dp){
        if(i > j) return 0;
        if(i == j) return 1;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == s[j]){
            
            int low = i + 1;
            int high = j - 1;

            while(low <= high && s[low] != s[i]) low++;
            while(low <= high && s[high] != s[j]) high--;

            if(low > high){
                return dp[i][j] =
                (2LL * f(i+1, j-1, s, dp) + 2) % MOD;
            }
            else if(low == high){
                return dp[i][j] =
                (2LL * f(i+1, j-1, s, dp) + 1) % MOD;
            }
            else{
                return dp[i][j] =
                (2LL * f(i+1, j-1, s, dp)
                 - f(low+1, high-1, s, dp) + MOD) % MOD;
            }
        }
        else{
            return dp[i][j] =
            (f(i+1, j, s, dp)
             + f(i, j-1, s, dp)
             - f(i+1, j-1, s, dp) + MOD) % MOD;
        }
    }

    int countPalindromicSubsequences(string s) {
        int n = s.size();
        vector<vector<long long>> dp(n, vector<long long>(n, -1));
        return f(0, n-1, s, dp);
    }
};

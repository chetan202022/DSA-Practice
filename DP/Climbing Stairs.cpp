
// https://leetcode.com/problems/climbing-stairs/description/

class Solution {
public:

    int f(int idx, int n, vector<int> &dp){

        if(idx > n) return 0;
        if(idx == n) return 1;

        if(dp[idx] != -1) return dp[idx];

        int left = f(idx + 1, n, dp);
        int right = f(idx + 2, n, dp);

        return dp[idx] = left + right;
    }

    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return f(0, n, dp);
    }
};

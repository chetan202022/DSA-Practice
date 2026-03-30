
// https://www.geeksforgeeks.org/problems/cutted-segments1642/1

class Solution {
  public:
  
    int f(int n, int x, int y, int z, vector<int> &dp){
        if(n == 0) return 0;
        if(n < 0) return -1e9;
        
        if(dp[n] != -1) return dp[n];
        
        int a = 1 + f(n-x, x, y, z, dp);
        int b = 1 + f(n-y, x, y, z, dp);
        int c = 1 + f(n-z, x, y, z, dp);
        
        return dp[n] = max(a, max(b, c));
    }
  
    int maximizeTheCuts(int n, int x, int y, int z) {
        vector<int> dp(n+1, -1);
        return max(0, f(n, x, y, z, dp));
        
    }
};

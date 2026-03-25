
// https://www.geeksforgeeks.org/problems/ways-to-tile-a-floor5836/1

class Solution {
  public:
  
  int f(int idx, int n, vector<int> &dp){
      if(idx > n) return 0;
      if(idx == n) return 1;
      
      if(dp[idx] != -1) return dp[idx];
      
      int hori = f(idx+2, n, dp);
      int verti = f(idx+1, n, dp);
      
      return dp[idx] = hori + verti;
  }
  
    int numberOfWays(int n) {
        vector<int> dp(n+1, -1);
        return f(0, n, dp);
    }
};

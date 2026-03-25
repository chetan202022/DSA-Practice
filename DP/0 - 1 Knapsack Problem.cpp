
// https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

class Solution {
  public:
  
    int f(int idx, int W, vector<int> &val, vector<int> &wt, vector<vector<int>> &dp){
        if(W == 0) return 0;
        if(idx >= wt.size()) return 0;
        
        if(dp[idx][W] != -1) return dp[idx][W];
        
        int take=INT_MIN;
        if(wt[idx] <= W){
            take = val[idx] + f(idx+1, W-wt[idx], val, wt, dp);
        }
        int not_take = f(idx+1, W, val, wt, dp);
        
        return dp[idx][W] = max(take, not_take);
    }
  
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n=wt.size();
        vector<vector<int>> dp(n+1, vector<int>(W+1, -1));
        return f(0, W, val, wt, dp);
        
    }
};

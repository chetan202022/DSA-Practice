
// https://leetcode.com/problems/coin-change/

class Solution {
public:

    int f(int idx, int amount, vector<int>& coins, vector<vector<int>> &dp){
        if(idx == coins.size()){
            if(amount == 0) return 0;
            return 1e9;
        }

        if(dp[idx][amount] != -1) return dp[idx][amount];

        int take = 1e9;
        if(coins[idx] <= amount) take = 1 + f(idx, amount-coins[idx], coins, dp);

        int not_take = f(idx+1, amount, coins, dp);

        return dp[idx][amount] = min(take, not_take);
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1, -1));
        int ans = f(0, amount, coins, dp);
        return ans >= 1e9 ? -1 : ans;
    }
};

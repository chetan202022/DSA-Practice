
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/

class Solution {
public:

    int f(int idx, vector<int>& prices, int can_buy, vector<vector<int>> &dp){
        if(idx >= prices.size()) return 0;

        if(dp[idx][can_buy] != -1) return dp[idx][can_buy];

        int not_take = f(idx+1, prices, can_buy, dp);

        int buy_at = 0;
        if(can_buy) buy_at = -prices[idx] + f(idx + 1, prices, 0, dp);
        int sell_at = 0;
        if(!can_buy) sell_at = prices[idx] + f(idx + 2, prices, 1, dp);

        return dp[idx][can_buy] = max({not_take, sell_at, buy_at});
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return f(0, prices, 1, dp);
    }
};

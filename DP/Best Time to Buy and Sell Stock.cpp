
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=INT_MAX, n=prices.size(), ans=0;
        for(int i=0; i<n; i++){
            if(prices[i] < mini) mini = prices[i];
            ans = max(ans, (prices[i]-mini));
        }
        return ans;
    }
};

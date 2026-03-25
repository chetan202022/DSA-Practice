
// https://leetcode.com/problems/house-robber/description/

class Solution {
public:

    int f(int idx, int n, vector<int>& nums, vector<int> &dp){
        if(idx >= n) return 0;

        if(dp[idx] != -1) return dp[idx];

        int take = nums[idx] + f(idx + 2, n, nums, dp);
        int not_take = f(idx + 1, n, nums, dp);

        return dp[idx] = max(take, not_take);
    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1, -1);
        return f(0, n, nums, dp);
    }
};

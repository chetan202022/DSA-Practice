
// https://leetcode.com/problems/target-sum/

class Solution {
public:

    int f(int idx, int val, vector<int>& nums, int target, vector<vector<int>> &dp){
        if(idx == nums.size()){
            if(val == target) return 1;
            return 0;
        }

        if(dp[idx][val+1000] != -1) return dp[idx][val+1000];

        int ad = f(idx+1, val+nums[idx], nums, target, dp);
        int sub = f(idx+1, val-nums[idx], nums, target, dp);

        return dp[idx][val+1000] = ad + sub;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> dp(n, vector<int>(2001, -1));
        return f(0, 0, nums, target, dp);
    }
};

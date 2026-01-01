
// https://leetcode.com/problems/predict-the-winner/

class Solution {
public:
    int dp[21][21];
    int f(int l, int r, vector<int>& nums){
        if(l > r)return 0;

        if(dp[l][r] != -1)return dp[l][r];

        int takeleft = nums[l] - f(l+1, r, nums);
        int takeright = nums[r] - f(l, r-1, nums);

        return dp[l][r] = max(takeleft, takeright);
    }

    bool predictTheWinner(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return f(0, nums.size()-1, nums) >= 0;
    }
};

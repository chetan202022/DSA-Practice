
// https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/description/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        return (nums[n-1]-1) * (nums[n-2]-1);
    }
};


// https://leetcode.com/problems/subsets/description/

class Solution {
private:
    void f(int i, vector<int>& nums, vector<int>& sans, vector<vector<int>>& ans){
        if(i == nums.size()){
            ans.push_back(sans);
            return;
        }

        // exclude
        f(i+1, nums, sans, ans);

        // include
        sans.push_back(nums[i]);
        f(i+1, nums, sans, ans);
        sans.pop_back();

    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> sans;
        vector<vector<int>> ans;
        f(0, nums, sans, ans);
        return ans;
    }
};

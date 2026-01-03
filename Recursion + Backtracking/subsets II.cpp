
// https://leetcode.com/problems/subsets-ii/description/

class Solution {
private:
    void f(int i, vector<int>& nums, vector<int>& sans, vector<vector<int>>& ans){
        if(i == nums.size()){
            ans.push_back(sans);
            return;
        }

        // include
        sans.push_back(nums[i]);
        f(i+1, nums, sans, ans);
        sans.pop_back();

        // exclude
        while(i+1 < nums.size() && nums[i] == nums[i+1]) i++;
        f(i+1, nums, sans, ans);

    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> sans;
        vector<vector<int>> ans;
        f(0, nums, sans, ans);
        return ans;
    }
};

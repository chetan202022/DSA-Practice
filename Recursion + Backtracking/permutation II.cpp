
// https://leetcode.com/problems/permutations-ii/

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> sans;
    vector<bool> used;
    void f(vector<int>& nums){
        if(sans.size() == nums.size()){
            ans.push_back(sans);
            return;
        }

        for(int i=0; i<nums.size(); i++){
            if(used[i]) continue;
            if(i > 0 && nums[i] == nums[i-1] && !used[i-1]) continue;

            sans.push_back(nums[i]);
            used[i] = true;
            f(nums);
            sans.pop_back();
            used[i] = false;
        }

    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        used.assign(nums.size(), false);
        f(nums);
        return ans;
    }
};

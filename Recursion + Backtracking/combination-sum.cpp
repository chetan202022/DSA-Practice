
// https://leetcode.com/problems/combination-sum/description/

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> sans;
    void f(int index, int sum, vector<int>& candidates, int target){
        if(sum == target){
            ans.push_back(sans);
            return;
        }

        if(index == candidates.size()) return;

        // take
        if(sum+candidates[index] <= target){
            sans.push_back(candidates[index]);
            f(index, sum+candidates[index], candidates, target);
            sans.pop_back();
        }
        // not take
        f(index+1, sum, candidates, target);

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        f(0, 0, candidates, target);
        return ans;
    }
};

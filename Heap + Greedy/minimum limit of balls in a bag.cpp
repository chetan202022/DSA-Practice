
// https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/description/

class Solution {
public:

    bool isPossible(int maxBalls, vector<int>& nums, int maxOperations){
        int total_operations = 0;

        for(int num : nums){
            total_operations += (int)ceil((double)num/maxBalls) - 1;

            if(total_operations > maxOperations) return false;
        }
        return true;
    }

    int minimumSize(vector<int>& nums, int maxOperations) {
        int l=1, r=*max_element(nums.begin(), nums.end());
        int ans = r;
        while(l < r){
            int mid = l + (r-l)/2;
            if(isPossible(mid, nums, maxOperations)){
                ans = mid;
                r = mid;
            }else{
                l = mid+1;
            }
        }
        return ans;
    }
};

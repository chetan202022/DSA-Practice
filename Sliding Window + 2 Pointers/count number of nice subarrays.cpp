
// https://leetcode.com/problems/count-number-of-nice-subarrays/

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        int l=0, r=0;
        int odd = 0, cnt = 0;
        int ans=0;
        while(r < nums.size()){
            if(nums[r] % 2 != 0){
                odd++; cnt = 0;
            }
            while(odd == k){
                cnt++;
                if(nums[l] % 2 != 0) odd--;
                l++;
            }
            ans += cnt;
            r++;
        }
        return ans;
    }
};

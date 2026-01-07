
// https://leetcode.com/problems/count-number-of-nice-subarrays/

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        
        int ans=0;
        int oddCnt=0;
        for(int num : nums){
            if(num & 1) oddCnt++;
            if(mp.count(oddCnt - k)) ans += mp[oddCnt - k];
            mp[oddCnt]++;
        }
        return ans;
    }
};

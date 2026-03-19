
// https://leetcode.com/problems/single-number-iii/description/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorr=0;
        for(int num : nums) xorr ^= num;

        unsigned int temp = xorr;
        int rightmost = (temp & (temp-1)) ^ temp;

        vector<int> ans(2,0);
        for(int num : nums){
            if(num & rightmost){
                ans[0] ^= num;
            }
            else{
                ans[1] ^= num;
            }
        }
        return ans;
    }
};

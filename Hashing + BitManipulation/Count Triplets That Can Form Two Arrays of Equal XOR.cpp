
// https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        unordered_map<int, int> freq, sum;
        int xr = 0;
        int ans=0;

        freq[xr] = 1;
        sum[xr] = 0;

        for(int i=0; i<arr.size(); i++){
            xr ^= arr[i];

            if(freq.count(xr)){
                ans += freq[xr] * i - sum[xr];
            }

            freq[xr]++;
            sum[xr] += (i+1);
        }
        return ans;
    }
};

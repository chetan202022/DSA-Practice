
// https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1

class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        int ans=0;
        int prefix=0;
        for(int i=0; i<arr.size(); i++){
            prefix += arr[i];
            
            if(prefix == k) ans = i+1;
            
            if(mp.find(prefix - k) != mp.end()){
                ans = max(ans, i - mp[prefix-k]);
            }
            if(mp.find(prefix) == mp.end()){
                mp[prefix] = i;
            }
        }
        return ans;
    }
};

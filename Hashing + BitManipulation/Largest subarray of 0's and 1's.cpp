
// https://www.geeksforgeeks.org/problems/largest-subarray-of-0s-and-1s/1

class Solution {
  public:
    int maxLen(vector<int> &arr) {
        
        int prefix_sum=0, ans=0;
        unordered_map<int, int> mp;
        
        for(int i=0; i<arr.size(); i++){
            
            prefix_sum += (arr[i] == 0) ? -1 : 1;
            
            if(prefix_sum == 0) ans = i+1;
            
            if(mp.find(prefix_sum) != mp.end()) ans = max(ans, i-mp[prefix_sum]);
            
            else mp[prefix_sum] = i;
        }
        return ans;
    }
};

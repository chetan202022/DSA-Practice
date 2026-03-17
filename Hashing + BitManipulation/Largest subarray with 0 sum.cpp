
// https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1

class Solution {
  public:
    int maxLength(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int, int> mp;
        int ans=0;
        int prefix=0;
        
        for(int i=0; i<n; i++){
            
            prefix += arr[i];
            
            if(prefix == 0) ans = i+1;
            
            if(mp.find(prefix) != mp.end()){
                ans = max(ans, i-mp[prefix]);
            }
            else{
                mp[prefix] = i;
            }
        }
        return ans;
    }
};

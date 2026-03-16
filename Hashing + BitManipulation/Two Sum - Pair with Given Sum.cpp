
// https://www.geeksforgeeks.org/problems/key-pair5616/1

class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        unordered_map<int, int> mp;
        for(auto &a : arr) mp[a]++;
        
        for(auto &a : arr){
            if(mp.find(target-a) != mp.end()){
                if((target-a) != a || mp[a] > 1) return true;
            }
        }
        return false;
    }
};

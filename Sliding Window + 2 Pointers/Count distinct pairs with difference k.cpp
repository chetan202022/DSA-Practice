class Solution {
  public:
    int TotalPairs(vector<int> nums, int k) {
        int count=0;
        if(k==0){
            unordered_map<int, int> mp;
            for(int num : nums) mp[num]++;
            
            for(auto &p : mp){
                if(p.second > 1) count++;
            }
            return count;
        }
        
        unordered_set<int> st(nums.begin(), nums.end());
        
        for(int num : st){
            int val = k + num;
            if(st.find(val) != st.end()) count++;
        }
        return count;
    }
};


// https://www.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1

class Solution {
  public:
    // Complete this function
    // Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(vector<int>& arr) {
        vector<int> prefix_sum(arr.size());
        unordered_set<int> st;
        for(int i=0; i<arr.size(); i++){
            if(arr[i] == 0 || st.find(0) != st.end()) return true;
            int val = arr[i] + prefix_sum[i-1];
            if(st.find(val) != st.end()) return true;
            st.insert(val); 
            prefix_sum[i] = val;
        }
        
        return false;
    }
};


// https://leetcode.com/problems/sum-of-subarray-minimums/description/

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const int MOD = 1e9+7;
        stack<int> st;
        int n = arr.size();
        vector<int> left(n), right(n);

        // nse
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();

            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        // pse
        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();

            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        int ans=0;
        for(int i=0; i<n; i++){
            int l = i - left[i];
            int r = right[i] - i;
            ans = (ans + (1LL * arr[i] * l * r) % MOD) % MOD;
        }
        return ans;
    }
};

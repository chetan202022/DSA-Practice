
// https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/description/

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefix(n+1, 0);

        for(int i=0; i<n; i++) prefix[i+1] = prefix[i] + nums[i];

        deque<int> dq;
        int len = INT_MAX;

        for(int i=0; i <= n; i++){

            while(!dq.empty() && prefix[i] - prefix[dq.front()] >= k){
                len = min(len, i-dq.front());
                dq.pop_front();
            }

            while(!dq.empty() && prefix[i] <= prefix[dq.back()]) dq.pop_back();

            dq.push_back(i);
        }

        return (len == INT_MAX) ? -1 : len;
    }
};

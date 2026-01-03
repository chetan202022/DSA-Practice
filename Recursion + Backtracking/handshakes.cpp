
// https://www.geeksforgeeks.org/problems/handshakes1303/1

class Solution {
public:
    int count(int N) {
        int n = N / 2;
        vector<long long> dp(n + 1, 0);
        
        dp[0] = 1;  // base case
        
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                dp[i] += dp[j] * dp[i - 1 - j];
            }
        }
        
        return dp[n];
    }
};


// https://www.geeksforgeeks.org/problems/longest-common-substring1452/1

class Solution {
  public:
  
    int ans = 0;
    
    int f(int i, int j, string& s1, string& s2, vector<vector<int>> &dp){
              
        if(i >= s1.size() || j >= s2.size()) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];

        int count=0;

        if(s1[i] == s2[j]){
            count = 1 + f(i+1, j+1, s1, s2, dp);
            ans = max(ans, count);
        }
        
        // explore remaining
        f(i+1, j, s1, s2, dp);
        f(i, j+1, s1, s2, dp);

        return dp[i][j] = count;
    }
  
    int longCommSubstr(string& s1, string& s2) {
        
        int n = s1.size();
        int m = s2.size();
        
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        f(0, 0, s1, s2, dp);
        
        return ans;
    }
};

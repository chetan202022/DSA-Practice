
// https://leetcode.com/problems/wildcard-matching/description/

class Solution {
public:

    bool f(int i, int j, string &s, string &p, vector<vector<int>> &dp){
        // if both exhausted
        if(i < 0 && j < 0) return true;
        // if s exhausted
        if(i < 0 && j >= 0){
            for(int k=0; k<=j; k++){
                if(p[k] != '*') return false;
            }
            return true;
        }
        // if p exhausted
        if(i >= 0 && j < 0) return false;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == p[j] || p[j] == '?') return dp[i][j] = f(i-1, j-1, s, p, dp);

        if(p[j] == '*') return dp[i][j] = f(i-1, j, s, p, dp) || f(i, j-1, s, p, dp);

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {

        vector<vector<int>> dp(s.size(), vector<int>(p.size(), -1));
        return f(s.size()-1, p.size()-1, s, p, dp);
    }
};

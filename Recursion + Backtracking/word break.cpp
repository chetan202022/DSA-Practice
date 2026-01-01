
// https://leetcode.com/problems/word-break/

class Solution {
public:

    bool f(int start, string &s, unordered_set<string> &st, vector<int> &dp){
        if(start == s.size()) return true;

        if(dp[start] != -1)return dp[start];

        for(int end = start+1; end <= s.size(); end++){
            string word = s.substr(start, end-start);

            if(st.find(word) != st.end() && f(end, s, st, dp)){
                return dp[start] = true;
            }
        }
        return dp[start] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        vector<int> dp(s.size(), -1);
        return f(0, s, st, dp);
    }
};

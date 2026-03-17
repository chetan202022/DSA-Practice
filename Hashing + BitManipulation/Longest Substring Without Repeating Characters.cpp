
// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int l=0, ans=0;
        unordered_map<char, int> mp;
        for(int r=0; r<n; r++){
            mp[s[r]]++;
            while(mp[s[r]] > 1){ mp[s[l]]--; if(mp[s[l]] == 0){mp.erase(s[l]);} l++; }
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};

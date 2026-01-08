
// https://leetcode.com/problems/minimum-window-substring/description/

class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size()) return "";

        unordered_map<char, int> mp, tempmp;
        for(auto& a : t) mp[a]++;

        int required=mp.size();
        int formed = 0;
        int l=0, r=0;
        int minLen = INT_MAX, start=0;
        while(r < s.size()){
            
            char ch = s[r];
            tempmp[ch]++;
            if(mp.find(ch) != mp.end() && tempmp[ch] == mp[ch]) formed++;

            while(l <= r && formed == required){
                if(r-l+1 < minLen){
                    minLen = r-l+1;
                    start = l;
                }

                char leftchar = s[l];
                tempmp[leftchar]--;
                if(mp.find(leftchar) != mp.end() && tempmp[leftchar] < mp[leftchar]) formed--;

                l++;
            }
            r++;
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};

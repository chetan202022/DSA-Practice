
// https://leetcode.com/problems/longest-repeating-character-replacement/description/

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);

        int l=0, maxfreq=0;
        int ans = 0;

        for(int r=0; r<s.size(); r++){
            freq[s[r] - 'A']++;
            maxfreq = max(maxfreq, freq[s[r] - 'A']);

            while((r-l+1) - maxfreq > k){
                freq[s[l] - 'A']--;
                l++;
            }

            ans = max(ans, (r-l+1));
        }
        return ans;
    }
};

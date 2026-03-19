
// https://leetcode.com/problems/palindrome-pairs/description/

class Solution {
public:

    bool isPallindrome(string &str, int l, int r){
        while(l < r){
            if(str[l++] != str[r--]) return false;
        }
        return true;
    }

    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n=words.size();
        unordered_map<string, int> mp;
        for(int i=0; i<n; i++) mp[words[i]] = i;
        
        vector<vector<int>> ans;
        for(int i=0; i<n; i++){
            string word = words[i];
            int len = word.size();

            for(int j=0; j<=len; j++){
                string left = word.substr(0, j);
                string right = word.substr(j);

                // case 1
                if(isPallindrome(left, 0, left.size()-1)){
                    string revRight = right;
                    reverse(revRight.begin(), revRight.end());

                    if(mp.count(revRight) && mp[revRight] != i){
                        ans.push_back({mp[revRight], i});
                    }
                }

                // case 2
                if(j != len && isPallindrome(right, 0, right.size()-1)){
                    string revLeft = left;
                    reverse(revLeft.begin(), revLeft.end());

                    if(mp.count(revLeft) && mp[revLeft] != i){
                        ans.push_back({i, mp[revLeft]});
                    }
                }
            }
        }
        return ans;
    }
};

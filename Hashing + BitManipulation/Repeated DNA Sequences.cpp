
// https://leetcode.com/problems/repeated-dna-sequences/description/

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        unordered_map<string, int> mp;
        for(int i=0; i<s.size(); i++){
            string str = s.substr(i, 10);
            mp[str]++;
        }
        for(auto m : mp){
            if(m.second > 1) ans.push_back(m.first);
        }
        return ans;
    }
};

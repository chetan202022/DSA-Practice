
// https://leetcode.com/problems/remove-duplicate-letters/description/

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> last_index(26, 0);
        vector<int> seen(26, false);

        for(int i=0; i<s.size(); i++){ last_index[s[i] - 'a'] = i; }

        stack<int> st;
 
        for(int i=0; i<s.size(); i++){
            int curr = s[i] - 'a';
            if(seen[curr]) continue;
            while(!st.empty() && st.top() > s[i] && i < last_index[st.top() - 'a']){
                seen[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(s[i]);
            seen[curr] = true;
        }

        string ans;
        while(!st.empty()){ ans.push_back(st.top()); st.pop(); }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

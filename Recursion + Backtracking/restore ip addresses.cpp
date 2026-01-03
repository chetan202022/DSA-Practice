
// https://leetcode.com/problems/restore-ip-addresses/description/

class Solution {
public:
    vector<string> ans;

    void dfs(int idx, int parts, string cur, string &s) {
        // If 4 parts formed and string consumed
        if (parts == 4 && idx == s.size()) {
            cur.pop_back();          // remove last '.'
            ans.push_back(cur);
            return;
        }

        if (parts == 4 || idx == s.size())
            return;

        int num = 0;
        for (int i = idx; i < s.size() && i < idx + 3; i++) {
            num = num * 10 + (s[i] - '0');

            if (num > 255) break;

            cur += s[i];
            dfs(i + 1, parts + 1, cur + '.', s);

            if (s[idx] == '0') break;   // no leading zero
        }
    }

    vector<string> restoreIpAddresses(string s) {
        ans.clear();
        if (s.size() < 4 || s.size() > 12)
            return ans;

        string cur = "";
        dfs(0, 0, cur, s);
        return ans;
    }
};


// https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        vector<int> ans;
        if (!root) return ans;

        // hd -> {level, value}
        map<int, pair<int,int>> mp;
        queue<pair<Node*, pair<int,int>>> q;
        // node, {hd, level}
        q.push({root, {0, 0}});

        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            Node* node = it.first;
            int hd = it.second.first;
            int lvl = it.second.second;

            // update if this level is deeper or same (BFS ensures later overwrites are deeper)
            if (mp.find(hd) == mp.end() || mp[hd].first <= lvl) {
                mp[hd] = {lvl, node->data};
            }

            if (node->left)
                q.push({node->left, {hd - 1, lvl + 1}});
            if (node->right)
                q.push({node->right, {hd + 1, lvl + 1}});
        }

        for (auto &x : mp)
            ans.push_back(x.second.second);

        return ans;
    }
};

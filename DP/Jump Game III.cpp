
// https://leetcode.com/problems/jump-game-iii/description/

class Solution {
public:

    bool f(int idx, vector<int>& arr, vector<int> &vis){
        if(idx >= arr.size() || idx < 0) return false;

        if(arr[idx] == 0) return true;

        if(vis[idx]) return false;
        vis[idx] = 1;

        bool right = f(idx + arr[idx], arr, vis);
        bool left = f(idx - arr[idx], arr, vis);

        return vis[idx] = (right || left);
    }

    bool canReach(vector<int>& arr, int start) {
        vector<int> vis(arr.size(), 0);
        return f(start, arr, vis);
    }
};


// https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans=0;
    vector<int> f(TreeNode* root, int distance){
        if(root == NULL) return {};

        if(root -> left == NULL && root -> right == NULL) return {1};

        vector<int> l = f(root -> left, distance);
        vector<int> r = f(root -> right, distance);

        for(int a : l){
            for(int b : r){
                if(a + b <= distance) ans++;
            }
        }

        vector<int> res;
        for(int d : l){ if(d+1 <= distance) res.push_back(d+1); }
        for(int d : r){ if(d+1 <= distance) res.push_back(d+1); }

        return res;
    }

    int countPairs(TreeNode* root, int distance) {
        f(root, distance);
        return ans;
    }
};

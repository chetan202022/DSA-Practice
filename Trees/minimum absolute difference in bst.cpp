
// https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/

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
    int ans = INT_MAX;
    int prev = -1;
    void f(TreeNode* root){
        if(root == NULL) return;

        f(root -> left);
        if(prev != -1){ ans = min(ans, abs(prev - root -> val)); }
        prev = root -> val;
        f(root -> right);
    }

    int getMinimumDifference(TreeNode* root) {
        f(root);
        return ans;
    }
};

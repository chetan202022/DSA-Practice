
// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/

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

    TreeNode* f(int a, int b, vector<int>& nums){
        if(a > b)return NULL;
        int idx = a+(b-a)/2;
        TreeNode* node = new TreeNode(nums[idx]);
        node->left = f(a, idx-1, nums);
        node->right = f(idx+1, b, nums);

        return node;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return f(0, nums.size()-1, nums);
    }
};

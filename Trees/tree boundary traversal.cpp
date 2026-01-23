
// https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution {
  public:
    vector<int> ans;

    bool isLeaf(Node* node) {
        return node && !node->left && !node->right;
    }

    void addLeftBoundary(Node* root) {
        Node* curr = root->left;
        while (curr) {
            if (!isLeaf(curr))
                ans.push_back(curr->data);
            if (curr->left)
                curr = curr->left;
            else
                curr = curr->right;
        }
    }

    void addLeaves(Node* root) {
        if (!root) return;
        if (isLeaf(root)) {
            ans.push_back(root->data);
            return;
        }
        addLeaves(root->left);
        addLeaves(root->right);
    }

    void addRightBoundary(Node* root) {
        Node* curr = root->right;
        vector<int> temp;
        while (curr) {
            if (!isLeaf(curr))
                temp.push_back(curr->data);
            if (curr->right)
                curr = curr->right;
            else
                curr = curr->left;
        }
        for (int i = temp.size() - 1; i >= 0; i--)
            ans.push_back(temp[i]);
    }

    vector<int> boundaryTraversal(Node* root) {
        if (!root) return ans;

        if (!isLeaf(root)) ans.push_back(root->data);
        
        addLeftBoundary(root);
        addLeaves(root);
        addRightBoundary(root);

        return ans;
    }
};


// https://www.geeksforgeeks.org/problems/binary-tree-to-dll/1

/* Structure for tree and linked list
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node()
        : data(0)
        , left(NULL)
        , right(NULL) {}

    Node(int x)
        : data(x)
        , left(NULL)
        , right(NULL) {}
};
 */

// This function should return head to the DLL
class Solution {
  public:
    Node* head = NULL;
    Node* prev = NULL;
  
    void f(Node* root){
        if(root == NULL) return;
        
        f(root -> left);
        
        if(prev == NULL) head = root;
        else{
            root -> left = prev;
            prev -> right = root;
        }
        prev = root;
        
        f(root -> right);
        
    }
  
    Node* bToDLL(Node* root) {
        f(root);
        return head;
    }
};

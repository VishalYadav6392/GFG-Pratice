/* Structure of Binary Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/
class Solution {
  public:
    int ans;

    void dfs(Node* root, int len) {
        if (root == NULL)
            return;

        ans = max(ans, len);

        if (root->left) {
            if (root->left->data == root->data + 1)
                dfs(root->left, len + 1);
            else
                dfs(root->left, 1);
        }

        if (root->right) {
            if (root->right->data == root->data + 1)
                dfs(root->right, len + 1);
            else
                dfs(root->right, 1);
        }
    }

    int longestConsecutive(Node* root) {
        if (root == NULL)
            return -1;

        ans = 1;
        dfs(root, 1);

        return (ans == 1) ? -1 : ans;
    }
};
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
    int dia=0;
    int solve(TreeNode* root){
        if(!root) return 0;
        int leftH = solve(root->left);
        int rightH = solve(root->right);
        int currlen = leftH+rightH;
        dia = max(dia, currlen);
        return 1+max(leftH, rightH);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        solve(root);
        return dia;
    }
};
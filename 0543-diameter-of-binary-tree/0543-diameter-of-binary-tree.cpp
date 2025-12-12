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
    int solve(TreeNode* root, int & maxi){
        if(!root) return 0;
        int lh = solve(root->left,maxi);
        int rh = solve(root->right,maxi);
        maxi = max(maxi, lh+rh);
        return 1+max(rh,lh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans =0;
        solve(root,ans);
        return ans;
    }
};
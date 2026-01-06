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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        int ans = 0, maxsum = INT_MIN,level=1;
        q.push(root);
        while(!q.empty()){
            int s=q.size();
            int sum = 0;
            while(s--){
                sum += q.front()->val;
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            if(maxsum<sum){
                maxsum = sum ;
                ans = level;
            }
            level++;
        }
        return ans;
    }
};
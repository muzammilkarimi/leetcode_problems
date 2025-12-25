/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root)
            return {};
        queue<pair<TreeNode*, int>> q;
        vector<vector<int>> ans;
        q.push({root, root->val});
        int turn = false;
        while (!q.empty()) {
            int s = q.size();
            vector<int> temp;
            while (s--) {
                temp.push_back(q.front().second);
                TreeNode* t = q.front().first;
                q.pop();
                if (t->left)
                    q.push({t->left, t->left->val});
                if (t->right)
                    q.push({t->right, t->right->val});
            }
            if (turn) {
                reverse(temp.begin(), temp.end());
                turn = false;
            } else
                turn = true;
            ans.push_back(temp);
        }
        return ans;
    }
};
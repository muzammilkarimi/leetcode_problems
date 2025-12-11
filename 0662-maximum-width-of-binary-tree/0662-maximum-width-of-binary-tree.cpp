/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     long long val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(long long x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(long long x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    long long widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        long long ans = 0;
        while (!q.empty()) {
            long long s = q.size();
            long long minm = q.front().second;
            long long first, last;
            for (long long i = 0; i < s; i++) {
                long long curr_i = q.front().second - minm;
                TreeNode* temp = q.front().first;
                q.pop();
                if (i == 0)
                    first = curr_i;
                if (i == s - 1)
                    last = curr_i;
                if (temp->left)
                    q.push({temp->left, curr_i * 2 + 1});
                if (temp->right)
                    q.push({temp->right, curr_i * 2 + 2});
            }
            ans = max(ans, last - first + 1);
        }
        return ans;
    }
};
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
    bool isValidBST(TreeNode* temp) {
        TreeNode* root = temp;
        if(!root) return false;
        vector<int> arr;
        stack<TreeNode*> st;
        while(root or !st.empty()){
            while(root){
                st.push(root);
                root=root->left;
            }
            root = st.top();
            st.pop(); 
            arr.push_back(root->val);
            root = root->right;
        }
        for(int i = 1; i<arr.size(); i++) if(arr[i-1]>=arr[i]) return false;
        return true;

        
    }
};
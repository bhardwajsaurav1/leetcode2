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
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* node=root;
        stack<TreeNode*>st;
        while(!st.empty()||node){
            while(node){
                st.push(node);
                node=node->left;
            }
            node=st.top();
            st.pop();
            k--;
            if(k==0) return node->val;
            node=node->right;
        }
        return 0;
    }
};
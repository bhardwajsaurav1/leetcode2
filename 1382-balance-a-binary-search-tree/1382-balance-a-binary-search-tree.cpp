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
    vector<TreeNode*> res;
    void inorder(TreeNode* root){
        if(root==NULL) return ;
        stack<TreeNode*> st;
        TreeNode* node=root;
        while(!st.empty()||node){
            while(node){
                st.push(node);
                node=node->left;
            }
            node=st.top();
            st.pop();
            res.push_back(node);
            node=node->right;
        }
    }
    TreeNode* bst(int i, int j){
        if(i>j) return NULL;
        int mid=(i+j+1)/2;
        TreeNode* root=res[mid];
        root->left=bst(i,mid-1);
        root->right=bst(mid+1,j);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        int n=res.size();
        return bst(0,n-1);
    }
};
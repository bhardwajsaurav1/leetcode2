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
    TreeNode* helper(TreeNode* root, int key){
        if(root==NULL) return NULL;
        if(root->val==key){
            // case 1 : leaf node
            if(!root->left&& !root->right){
                return NULL;
            }
            // case 2: two child
            else if(root->left&& root->right){
                TreeNode* temp=root->left;
                while(temp->right) temp=temp->right;
                temp->right=root->right;
                return root->left;
            }
            else{
                if(root->left) return root->left;
                else return root->right;
            }
        }
        if(root->val>key){
            root->left=helper(root->left,key);
        }
        else root->right=helper(root->right,key);
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        return helper(root,key);
    }
};
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* temp=root;
        TreeNode* prev=NULL;
        while(temp&& temp->val!=key){
            prev=temp;
            temp=(temp->val<key)?temp->right:temp->left;
        }
        if(temp==NULL) return root;// it means there is no key to delete
        // case 1 if the key element is leaf
        if(!temp->left&&!temp->right){
           if(prev==NULL){// means we are deleting the root node
                delete(temp);
                return NULL;
           } 
           if(prev->left==temp) prev->left=NULL;
           else prev->right=NULL;
           delete(temp);

        }
        // case 2 two child
        else if(temp->left&&temp->right){
            TreeNode* curr=temp->left;
            while(curr->right) curr=curr->right;
            curr->right=temp->right;
            if(prev==NULL){// means we are deleting the head
               TreeNode* newR=temp->left;
                delete temp;
                return newR;
            }
            else {
                
                if(prev->left==temp) prev->left=temp->left;
                else prev->right=temp->left;
                delete temp;
            }
        }
        else { //only one child
            if(temp->left){
                if(prev==NULL) {
                    TreeNode* newR= temp->left;
                    delete temp;
                    return newR;
                }
                else if(prev->left==temp) prev->left=temp->left;
                else prev->right=temp->left;
                delete temp;
            }
            else {
                if(prev==NULL) {
                    TreeNode* newR= temp->right;
                    delete temp;
                    return newR;
                }
                else if(prev->left==temp) prev->left=temp->right;
                else prev->right=temp->right;
                delete temp;
            }
        }
        return root;
    }
};
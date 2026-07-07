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
    void inord(TreeNode*root,vector<int>&inorder){
        if(root==NULL) return ;
        stack<TreeNode*>st;
        TreeNode* temp=root;
        while(!st.empty()||temp){
            while(temp){
                st.push(temp);
                temp=temp->left;
            }
            temp=st.top();
            st.pop();
            inorder.push_back(temp->val);
            temp=temp->right;
        }
       
    }
    vector<int> find(vector<int>&inorder,int val){
        int n=inorder.size();
        int low=0;
        int high=n-1;
        int mini=-1;
        int maxi=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(inorder[mid]==val) return {inorder[mid],inorder[mid]};
            else if(inorder[mid]<val){
                mini=inorder[mid];
                low=mid+1;
            }
            else {
                maxi=inorder[mid];
                high=mid-1;
            }
        }
       return{mini, maxi};
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        int n=queries.size();
        vector<vector<int>>ans;
        vector<int>inorder;
        inord(root,inorder);
        for(int i=0;i<n;i++){
            vector<int>temp=find(inorder,queries[i]);
            ans.push_back(temp);
        }
        return ans;
    }
};
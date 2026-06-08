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
    bool solve(TreeNode* root,int k,unordered_set<int>&st){
        if(root==NULL){
            return false;
        }
        if(solve(root->left,k,st)){
            return true;
        }
        int rem=k-root->val;
        if(st.find(rem) != st.end()) {
            return true;
        }
        st.insert(root->val);
        return solve(root->right, k, st);
    }
    bool findTarget(TreeNode* root, int k){
        unordered_set<int>st;
        return solve(root,k,st);
    }
};
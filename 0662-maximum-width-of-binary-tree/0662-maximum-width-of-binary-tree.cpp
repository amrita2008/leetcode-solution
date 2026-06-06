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
    int widthOfBinaryTree(TreeNode* root) {
        long long ans=0;
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        while(!q.empty()){
            int size=q.size();
            long long first,last;
            for(int i=0; i<size; i++){
                auto t=q.front();
                q.pop();
                if(i==0){
                   first=t.second; 
                }
                if(i==size-1){
                    last=t.second;
                }
                if(t.first->left){
                    q.push({t.first->left,2*(t.second)+1-first});
                }
                if(t.first->right){
                    q.push({t.first->right,2*(t.second)+2-first});
                }
            }
            ans=max(ans,last-first+1);
        }
        return ans;
    }
};
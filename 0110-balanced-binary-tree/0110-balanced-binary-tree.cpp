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
    pair<bool,int> fast(TreeNode* &root){
        if(root == NULL){
            return {true,0};
        }
        pair<bool,int> left = fast(root->left);
        pair<bool,int> right = fast(root->right);

        bool left1 = left.first;
        bool right1 = right.first;
        bool curr = abs(left.second-right.second)<=1;
        pair<bool,int> ans;
        ans.second = max(left.second,right.second)+1;
        ans.first = curr&&left1&&right1;
        return ans;
    }
    bool isBalanced(TreeNode* root) {
        return fast(root).first;
    }
};
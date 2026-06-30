class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> answer;
        helper(root, answer);
        return answer;
    }
    void helper(TreeNode* root, vector<int>& answer){
        if(root == nullptr) return;
        helper(root->left, answer);
        answer.push_back(root->val);
        helper(root->right, answer);
    }
};
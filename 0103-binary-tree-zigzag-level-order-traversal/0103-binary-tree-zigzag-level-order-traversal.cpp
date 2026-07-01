/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> store;
        vector<int> temp;

        bool right_left = true;

        queue<TreeNode*> q;

        if (root != NULL)
            q.push(root);

        q.push(NULL);

        while (!q.empty()) {

            TreeNode* top = q.front();
            q.pop();

            if (top == NULL) {

                if (q.empty())
                    break;

                else {

                    q.push(NULL);

                    if (right_left) {
                        store.push_back(temp);
                    } 
                    else {
                        reverse(temp.begin(), temp.end());
                        store.push_back(temp);
                    }

                    right_left = !right_left;

                    temp.clear();
                }

            } 
            else {

                temp.push_back(top->val);

                if (top->left != NULL) {
                    q.push(top->left);
                }

                if (top->right != NULL) {
                    q.push(top->right);
                }
            }
        }

        if (temp.size()) {

            if (right_left) {
                store.push_back(temp);
            } 
            else {
                reverse(temp.begin(), temp.end());
                store.push_back(temp);
            }
        }

        return store;
    }
};
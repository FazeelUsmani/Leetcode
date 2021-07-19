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
    void flatten(TreeNode* A) {
        
        TreeNode* root = A;
    
        while (root) {
            TreeNode* curr = root;
            TreeNode* temp = root->right;

            curr->right = curr->left;
            curr->left = NULL;
            while (curr->right) {
                curr = curr->right;
            }
            curr->right = temp;
            root = root->right;
        }

                
    }
};

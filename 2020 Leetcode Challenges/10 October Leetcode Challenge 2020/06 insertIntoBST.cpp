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
    
    TreeNode* helper (TreeNode* root, int val) {
        if (root == NULL) {
            TreeNode *temp = new TreeNode(val);
            return temp;
        }
        if (val <= root->val) {
            root->left = helper(root->left, val);
        }
        else {
            
            root->right = helper(root->right, val);
        }
        
        return root;
    }
    
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        return helper(root, val);
    }
};

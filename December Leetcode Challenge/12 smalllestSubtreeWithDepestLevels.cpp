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
    int height(TreeNode* root){
        if(!root)
            return 0;
        
        int l = height(root->left);
        int r = height(root->right);
        
        if(l>r)
            return l +1;
        else
            return r+1;
    }
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(height(root->left) == height(root->right))
            return root;
        if(height(root->left) > height(root->right))
            root = root->left;
        else
            root = root->right;
        
        return subtreeWithAllDeepest(root);        
    }
};

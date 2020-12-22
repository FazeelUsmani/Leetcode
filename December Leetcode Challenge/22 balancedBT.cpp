class Solution {
public:
    
    int height (TreeNode* root) {
        if (root == NULL)   return 0;
        
        return 1 + max(height(root->left), height(root->right));
    }
    
    
    bool isBalanced(TreeNode* root) {
        if (root == NULL)   return true;
        
        int lh, rh;
        lh = height(root->left);
        rh = height(root->right);
        
        if (abs(lh-rh)<=1 && isBalanced(root->left) && isBalanced(root->right) )
            return true;
        
        return false;                                
    }
};

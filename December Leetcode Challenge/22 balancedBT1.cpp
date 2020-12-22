class Solution {
public:    
    bool isBalancedHelper(TreeNode* root, int* height) {
        
        int lh = 0, rh = 0;
        int l = 0, r = 0;
        
        if (root == NULL) {
            *height = 0;
            return 1;
        }
        
        l = isBalancedHelper(root->left, &lh);
        r = isBalancedHelper(root->right, &rh);
        
        *height = (lh > rh ? lh : rh) + 1;
        
        if (abs(lh-rh)>1)   return 0;
        else    return l&&r;   
    }
    
    bool isBalanced(TreeNode* root) {
        if (root == NULL)
            return 1;
        int ht = 0;
        
        return isBalancedHelper(root, &ht);
    }
};

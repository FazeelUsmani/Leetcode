class Solution {
public:
    int sumNumbers(TreeNode* root, int num=0) {
        return root->left == root->right ? num * 10 + root->val :
            ((root->left ? sumNumbers(root->left, num * 10 + root->val) : 0) + 
            (root->right ? sumNumbers(root->right, num * 10 + root->val) : 0));
    }
};

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
    
    int ans = 0;
    void root2leafSum (TreeNode* root, int num){
        if (root == NULL)
            return;
        if (root->left == NULL && root->right == NULL){
            num = num*10 + root->val;
            ans += num;
            return;
        }

        root2leafSum(root->left, num*10 + root->val);
        root2leafSum(root->right, num*10 + root->val);
    }
        
    int sumNumbers(TreeNode* root) {
        ans = 0;
        root2leafSum (root, 0);    
        
        return ans;
    }
};

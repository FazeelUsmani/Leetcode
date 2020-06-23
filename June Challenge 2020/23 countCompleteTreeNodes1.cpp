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
    int countNodes(TreeNode* root) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int lh = 0, rh = 0;
        TreeNode* curr = root;
        while (curr != NULL){
            lh++;
            curr = curr->left;
        }
        
        curr = root;
        while (curr != NULL){
            rh++;
            curr = curr->right;
        }
        
        if (lh == rh)
            return pow(2, lh) - 1;
        
        return 1 + countNodes(root->left) + countNodes(root->right);        
    }
};

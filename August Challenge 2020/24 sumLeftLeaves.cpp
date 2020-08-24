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


int sum;

bool isLeaf(TreeNode* root){
    return root && root->left == NULL && root->right == NULL;
}

void addLeft(TreeNode* root){    
    if (root == NULL)
        return;

    if (root->left != NULL){
        if (isLeaf(root->left)){
            sum += root->left->val;            
        }               
    }
    addLeft(root->left);
    addLeft(root->right);
}

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root){                
        sum = 0;
        addLeft(root);
        
        return sum;
    }
};

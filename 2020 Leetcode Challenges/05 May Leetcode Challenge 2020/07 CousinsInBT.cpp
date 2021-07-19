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
    bool isCousins(TreeNode* root, int x, int y) {
        
        queue<TreeNode *> q;
        q.push(root);
        if (root->val == x || root->val == y)
            return false;
        
        while (!q.empty()){
            int size = q.size();
            
            bool found1 = false, found2 = false;
            
            for (int i = 0; i < size; i++){
                TreeNode *curr = q.front();
                q.pop();
                
                if (curr->val == x)
                    found1 = true;
                if (curr->val == y)
                    found2 = true;

                int cnt = 0;
                
                if (curr->left != NULL){
                    q.push(curr->left);
                    if (curr->left->val == x || curr->left->val == y)
                        cnt++;                                      
                }
                
                if (curr->right != NULL){
                    q.push(curr->right);
                    if (curr->right->val == x || curr->right->val == y)
                        cnt++;
                }    
                
                if (cnt == 2)
                    return false;                                                     
            }
            if (found1 && found2)
                return true;            
        }
        return false;        
    }
};

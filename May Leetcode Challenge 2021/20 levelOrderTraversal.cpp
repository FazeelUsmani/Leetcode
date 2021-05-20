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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        if (root == NULL)
            return {};
        
        vector<vector<int>> ans;
        
        queue<TreeNode*> q;
        q.push(root);
        int sz;
        
        while (!q.empty()) {
            sz = q.size();            
            vector<int> temp;
            
            for (int i = 0; i < sz; ++i) {
                
                TreeNode* curr = q.front();
                q.pop();
                
                temp.push_back(curr->val);
                
                if (curr->left)                
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);                                
            }
                        
            ans.push_back(temp);
        }
        
        return ans;              
    }
};

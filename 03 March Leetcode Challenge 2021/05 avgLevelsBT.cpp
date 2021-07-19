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
    vector<double> averageOfLevels(TreeNode* root) {
        
        vector<double> ans;
        if (root == NULL)   return ans;
        
        queue<TreeNode* > q;
        q.push(root);
        
        while (!q.empty()) {
            int sz = q.size();
            double avg = 0;
            for (int i = 0; i < sz; ++i) {
                TreeNode *front = q.front();
                q.pop();
                avg += front->val;
                
                if (front->left)  
                    q.push(front->left);
                if (front->right)
                    q.push(front->right);
            }
            ans.push_back(avg/sz);            
        }
        
        return ans;
    }
};

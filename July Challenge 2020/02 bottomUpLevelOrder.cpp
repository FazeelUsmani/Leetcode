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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        vector<vector<int> > temp;
        if (root == NULL)
            return temp;
        
        queue<TreeNode *> q;
        q.push(root);
        int currLevel = 0;
        
        while (!q.empty()){
            temp.push_back({});
            int size = q.size();
            
            for (int i = 0; i < size; ++i){
                TreeNode *front = q.front();
                q.pop();
                temp[currLevel].push_back(front->val);
                
                if (front->left != NULL)
                    q.push(front->left);
                
                if (front->right != NULL)
                    q.push(front->right);                                
            }
            ++currLevel;
            
        }
        
        vector<vector<int> > ans;
        
        for (int i = temp.size()-1; i >= 0; --i)
            ans.push_back(temp[i]);
        
        return ans;
    }
};

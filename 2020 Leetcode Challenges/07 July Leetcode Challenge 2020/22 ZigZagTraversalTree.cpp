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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;
        
        int toggle = 1;
        
        stack <TreeNode *> s1, s2;
        s1.push(root);
        
        while (!s1.empty() || !s2.empty()){
            vector<int> temp;
            if (toggle){           
                
                while (!s1.empty()){                    
                    TreeNode *top = s1.top();
                    s1.pop();
                    temp.push_back(top->val);
                    if (top->left != NULL)
                        s2.push(top->left);
                    if (top->right != NULL)
                        s2.push(top->right);
                }                              
            }
            
            else{

                while(!s2.empty()){
                    TreeNode *top = s2.top();
                    s2.pop();
                    temp.push_back(top->val);
                    if (top->right != NULL)
                        s1.push(top->right);
                    if (top->left != NULL)
                        s1.push(top->left);
                }                
            }
            ans.push_back(temp);
            toggle ^= 1;        
            temp.clear();
        }           
        
        return ans;        
    }
};

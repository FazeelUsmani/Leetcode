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

vector<int> preOrder(TreeNode* root){
    
    stack<TreeNode *> s;
    TreeNode *x = root;
    vector<int> ans;
    
    while (x != NULL || !s.empty()){
        
        while (x != NULL){
            s.push(x);
            x = x->left;
        }
        
        x = s.top();
        s.pop();
        ans.push_back(x->val);
        x = x->right;
    }
    
    return ans;
}

class Solution {
public:  
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        
        vector<int> list1 = preOrder(root1);
        vector<int> list2 = preOrder(root2);
        vector<int> res;
        
        int i = 0, j = 0, m = list1.size(), n = list2.size();
        while (i < m && j < n){
            if (list1[i] < list2[j]){
                res.push_back(list1[i]);
                i++;
            }
            else{
                res.push_back(list2[j]);
                j++;
            }
        }
        
        while (i < m){
            res.push_back(list1[i++]);
        }
        
        while (j < n){
            res.push_back(list2[j++]);
        }
        
        return res;
    }
};

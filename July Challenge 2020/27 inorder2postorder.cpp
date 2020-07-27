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
    unordered_map<int, int> umap;
    
    TreeNode* inPost(vector<int>& inorder, vector<int>& postorder, int is, int ie, int ps, int pe){
        if (ie < is)
            return NULL;
        
        int rootVal = postorder[pe];
        int index = umap[rootVal];
        
        TreeNode *root = new TreeNode(rootVal);
        
        root->left = inPost(inorder, postorder, is, index-1, ps, ps+(index-is)-1);
        root->right = inPost(inorder, postorder, index+1, ie, ps+(index-is), pe-1);   
        
        return root;
    }
    
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        umap.clear();
        for (int i = 0; i < inorder.size(); ++i)
            umap[inorder[i]] = i;
        
        
        return inPost(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);                 
    }
};

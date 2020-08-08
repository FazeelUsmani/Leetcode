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
    int res = 0, sum;
    // seen set with initial value 0 will help us match from the root
    vector<int> seen = {0};
    void dfs(TreeNode* root, int partialSum = 0) {
        // updating partialSum with the current node
        partialSum += root->val;
        // checking if we already found an interval summing up to that
        for (auto n: seen) if (n == partialSum - sum) res++;
        // updating seen
        seen.push_back(partialSum);
        // searching potential left and right branches
        if (root->left) dfs(root->left, partialSum);
        if (root->right) dfs(root->right, partialSum);
        // clearing seen one level, for backtracking purposes
        seen.pop_back();
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        sum = targetSum;
        if (!root) return res;
        dfs(root);
        return res;
    }
};

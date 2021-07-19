class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        // support variables
        int res, len = 1;
        queue<TreeNode*> q;
        TreeNode *curr;
        // preparing q
        q.push(root);
        // BFS cycle
        while (len) {
            // resetting res if we still have a level to parse
            res = 0;
            while (len--) {
                // reading and popping the front node
                curr = q.front();
                q.pop();
                // updating res and q
                res += curr->val;
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
            // preparing for the next iteration
            len = q.size();
        }
        return res;
    }
};

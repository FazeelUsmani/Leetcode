class Solution {
public:
    Node* connect(Node* root) {
        // leaving if `root` is empty or has no children
		if (!root || !root->left) return root;
        Node *left = connect(root->left), *right = connect(root->right);
        while (left) {
            // merging the left and right branch
            left->next = right;
            // moving to the rightmost node on the left branch and the other way around
            left = left->right;
            right = right->left;
        }
        return root;
    }
};

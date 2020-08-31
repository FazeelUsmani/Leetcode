struct TreeNode* minValueNode(struct TreeNode * node) 
{ 
    struct TreeNode * current = node; 
    while (current && current->left != NULL) 
        	current = current->left; 
  
    return current; 
} 

struct TreeNode* deleteNode(struct TreeNode* root, int key)
{
    if (root == NULL)
		return root; 
  
    // key to delete is smaller than root so go left
    if (key < root->val) 
        root->left = deleteNode(root->left, key); 
 
    // key to delete is greater than root so go right
   	else if (key > root->val) 
        	root->right = deleteNode(root->right, key); 
    
    // we came to node to be deleted
    else
    {   
        // node to be deleted has only right child, so right child takes its place
        if (root->left == NULL) 
        { 
            	struct TreeNode *temp = root->right; 
            	free(root); 
            	return temp; 
        } 
        // node to be deleted has only right child, so left child takes its place
        else if (root->right == NULL) 
        { 
		    struct TreeNode *temp = root->left; 
		    free(root); 
		    return temp; 
        } 
        // node to be deleted has two children, so the successor takes its place
        struct TreeNode * temp = minValueNode(root->right); 
        root->val = temp->val; 
   
        root->right = deleteNode(root->right, temp->val);   	
    } 
    	
    return root; 
} 

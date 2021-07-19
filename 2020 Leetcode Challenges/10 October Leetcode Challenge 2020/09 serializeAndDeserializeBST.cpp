class Codec {
public:

    string serialize(TreeNode* root) 
    {
        return !root ? " null" : " " + to_string(root->val) + serialize(root->left) + serialize(root->right);
    }
	
    TreeNode* deserialize(string data) 
    {
        istringstream ss(data);
		return buildBST(ss);
    }
    
private:
    
    TreeNode* buildBST(istringstream& ss)
    {
        string s;
        ss >> s;
        
        if (s == "null")
			return NULL;
        
        TreeNode* node = new TreeNode(stoi(s));
        node->left = buildBST(ss);
        node->right = buildBST(ss);
            
        return node;
    }
};

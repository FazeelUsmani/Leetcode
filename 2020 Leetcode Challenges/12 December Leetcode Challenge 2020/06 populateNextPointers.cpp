
class Solution {
public:
    Node* connect(Node* root) {
        
        if(!root)return root;
        Node *temp=NULL, *temp1 = NULL;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            while(size--){
                temp = q.front();
                q.pop();
                if(temp->right)q.push(temp->right);
                if(temp->left)q.push(temp->left);
                temp->next = temp1;
                temp1 = temp;
            }
            temp1 = NULL;
        }
        return root;
    }
};

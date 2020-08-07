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
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        map<int,vector<pair<int,int>>> map;
        queue<pair<TreeNode*,int>> q;
        vector<vector<int>> result;
        vector<int> temp;
        int hd=0,vd=0;
        if(!root)return result;
        q.push({root,hd});
        while(!q.empty()){
            int size=q.size();
            vd++;
            for(int i=0;i<size;i++){
                root=q.front().first;
                hd=q.front().second;
                q.pop();
                map[hd].push_back({root->val,vd});
                if(root->left)q.push({root->left,hd-1});
                if(root->right)q.push({root->right,hd+1});
            }
        }
        for(auto itr=map.begin();itr!=map.end();itr++){
            sort(itr->second.begin(),itr->second.end(),[](pair<int,int>& a,pair<int,int>& b){
               if(a.second<b.second)
                    return true;
               else if(a.second==b.second)
                    return a.first<b.first;
                else return false;
            });
         for(int i=0;i<itr->second.size();i++){
             temp.push_back(itr->second[i].first);
         }   
            result.push_back(temp);
            temp.clear();
        }
        return result;        
           
    }
};

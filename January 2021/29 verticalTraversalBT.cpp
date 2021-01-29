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
         
        map<int,vector<pair<int,int>>> mp;   

        void Traverse_Vertically(TreeNode* root , int curr_x , int curr_y)
        {
            if(root==NULL)return;

            mp[curr_x].push_back({curr_y,root->val});
            Traverse_Vertically(root->left , curr_x-1 , curr_y+1);
            Traverse_Vertically(root->right , curr_x+1 , curr_y+1);
        }

        vector<vector<int>> verticalTraversal(TreeNode* root)
        {
            mp.clear();   // clear the map

            vector<int> temp;  // temporary vector 

            Traverse_Vertically(root,0,0);   // start vertical traversal from root

            vector<vector<int>> ans;


            for(auto it:mp)
            {

                temp.clear();

                // sort the pairs {y corrdinates , root->value} in ascending order
                sort(it.second.begin(),it.second.end());

                // store our current ans in temporary vector
                for(auto itr:it.second)
                    temp.push_back(itr.second);

                // store our current traversal
                ans.push_back(temp);
            }

            return ans;
    }
};

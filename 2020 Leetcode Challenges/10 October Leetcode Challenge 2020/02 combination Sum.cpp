class Solution {
public:
    void helper(vector<vector<int>> &ans, vector<int> &path, vector<int> &l, int n, int target, int cur){

        if(target < 0){
            return;
        }
        
        if(target == 0){
            ans.push_back(path);
            return;
        }
        
        for(int i = cur; i < n; i++){
            path.push_back(l[i]);
            helper(ans, path, l, n, target - l[i], i);
            path.pop_back();
        }
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& l, int target) {
        sort(l.begin(), l.end());
        vector<vector<int>> ans;
        vector<int> path;
        if(!l.size()){
            return ans;
        }
        
        helper(ans, path, l, l.size(), target, 0);
        return ans;
        
    }
};

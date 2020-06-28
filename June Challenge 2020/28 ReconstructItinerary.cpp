void dfs(string src,unordered_map<string,vector<string>>& m,vector<string>& ans){
        while(!m[src].empty()){
            string s=m[src].back();
            m[src].pop_back();
            dfs(s,m,ans);
        }
        ans.push_back(src);
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,vector<string>> m;
		// Create Graph
        for(auto i:tickets)
            m[i[0]].push_back(i[1]);
		// Sorting in descending order since we will be popping elements from the end
        for(auto &i:m)
            sort(i.second.begin(),i.second.end(),greater<string>());  

        vector<string> ans;
        dfs("JFK",m,ans);
        reverse(ans.begin(),ans.end());
        return ans;

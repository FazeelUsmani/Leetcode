class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) 
    {
        vector<pair<int,int>> s;
        multiset<int> q;
        vector<vector<int>> ans;
        for (auto building:buildings) {
            s.push_back({building[0],building[2]});
            s.push_back({building[1],-1*building[2]});
        }
        sort(s.begin(),s.end(),[](auto a, auto b){
            if (a.first==b.first) return a.second>=b.second;
            else return a.first<=b.first;
        });
        q.insert(0); int cur_max=0;
        for (auto building:s) {
            if (building.second<0) 
                q.erase(q.find(-1*building.second));
            else q.insert(building.second);
            if (*(q.rbegin())!=cur_max) {
                cur_max=*(q.rbegin());
                ans.push_back({building.first,cur_max});
            }
        }
        return ans;
    }
};

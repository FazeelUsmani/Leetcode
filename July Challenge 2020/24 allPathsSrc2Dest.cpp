class Solution {
public:
    int destination;
    vector<vector<int> > res;
    vector<int> temp;
    
    void dfs(vector<vector<int>> &graph, int curr = 0){
        temp.push_back(curr);
        if (curr == destination)
            res.push_back(temp);
        else
            for (int node: graph[curr])
                dfs(graph, node);
        temp.pop_back();        
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        temp.clear();
        res.clear();
        destination = graph.size() - 1;
        dfs(graph);
        
        return res;        
    }
};

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<int> colors(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (!colors[i] )
            {
                colors[i]=1;
                if (!dfs(graph, colors, i)) return false;
            }
        }
        return true;
    }
     
private:
    bool dfs(vector<vector<int>>& graph, vector<int>& colors, int i)
    {
        for (int neighbor : graph[i])
        {
            if (!colors[neighbor])
            {
                colors[neighbor] = -(colors[i]);
                if (!dfs(graph, colors, neighbor)) return false;
            }
            else if(colors[neighbor] == colors[i])
            {
                return false;
            }
        }
        return true;
    }
};

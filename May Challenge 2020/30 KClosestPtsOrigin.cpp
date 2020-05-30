typedef pair<int, int> PP;

int dist (int i, int j){
        return i*i + j*j;
    }

class Solution {
public:     
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {        
        
        priority_queue<PP> pq;
        
        for (int i = 0; i < K; i++){
            int d = dist(points[i][0], points[i][1]);
            pq.push(make_pair(d, i));            
        }
        
        int n = points.size();
        for (int i = K; i < n; i++){
            int d = dist(points[i][0], points[i][1]);
            if (d < pq.top().first){
                pq.pop();
                pq.push(make_pair(d, i));
            }
        }   
        
        vector<vector<int>> ans;
        while (!pq.empty()){
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }
        
        return ans;        
    }
};

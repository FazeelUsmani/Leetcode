class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        int maxDrop = INT_MIN;
        for (int i = 0; i < trips.size(); ++i){
            maxDrop = max(maxDrop, trips[i][2]);            
        }
        vector<int> cost(maxDrop+1, 0);
        for (int i = 0; i < trips.size(); ++i) {
            int pickup = trips[i][1];
            int dropoff = trips[i][2];
            for (int j = pickup; j < dropoff; ++j) {
                cost[j] += trips[i][0];
            }
        }
        
        for (int x: cost){
            if (x > capacity) {
                return false;
            }
        }
        return true;
    }
};

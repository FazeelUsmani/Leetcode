class Solution {
public:
    int canCompleteCircuit(vector<int>& A, vector<int>& B) {
        
        int n = A.size();
        int deficit = 0, tank = 0, start = 0;

        for (int i = 0; i < n; i++){
            tank += A[i] - B[i];

            if (tank < 0){
                deficit += tank;
                tank = 0;
                start = i+1;
            }
        }

        return (deficit + tank >= 0) ? start : -1;
        
    }
};

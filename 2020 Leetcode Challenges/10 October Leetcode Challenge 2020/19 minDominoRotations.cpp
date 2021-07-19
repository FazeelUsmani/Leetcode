class Solution {
public:
    
    int helper(vector<int>& A,vector<int>& B,int x){
        
        int total = 0;     
        int countA = 0;   /// No. of x in A
        int countB = 0;  /// No. of x in B
        for(int i = 0 ;i<A.size();i++){
            if(A[i] == x || B[i] == x)
                total++;
            if(A[i] == x)
                countA++;
            if(B[i] == x)
                countB++;
        }
        
        if(total != A.size())   /// If total is not equal to A.size(), then it is not possible.
            return -1;
        
        else return min(total - countA,total - countB);      
        
    }
    
    
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        
        int ans = helper(A,B,A[0]);   /// helper function helps find the minimum rotations needed to make all elements of A or B = x.
        if(ans != -1)   /// We return here without checking for B[0] because even if the other row becomes all B[0], minimum rotations wold be the same.
            return ans;
        else return helper(A,B,B[0]);
        
    }
};

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int res=0;
        unordered_map<int,int> m(A.size() * B.size());
        for(int i=0;i<A.size();i++)
        {
            for(int j=0;j<B.size();j++)
            {
                m[A[i]+B[j]]++;
            }
        }
        for(int i=0;i<C.size();i++)
        {
            for(int j=0;j<D.size();j++)
            {
                const auto it=m.find(-C[i]-D[j]);
                if(it!=m.end())
                {
                    res+=it->second;
                }
            }
        }
        return res;}
   
};

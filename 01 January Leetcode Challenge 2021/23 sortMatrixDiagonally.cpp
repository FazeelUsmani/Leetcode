class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        
            int i,j=0,k=0;
            int n=mat.size();
            int m=mat[0].size();

            //First Do for upper triangular part
            for(i=0;j<m;j++)
            {
                vector<int> v;
                k=0;
                while(i+k<n && j+k<m)       // first store the diagonal part in a vector
                {
                    v.push_back(mat[i+k][j+k]);      
                    k++;
                }
                sort(v.begin(),v.end());            // secondly sort the vector

                k=0;
                while(k<v.size())           // and after sorting, push back the sorted
                {                           // vector in the matrix
                    mat[i+k][j+k]=v[k];
                    k++;
                }
            }
            i=1;
            //for lower triangular part
            for(j=0;i<n;i++)
            {
                vector<int> v;
                k=0;
                while(i+k<n && j+k<m)
                {
                    v.push_back(mat[i+k][j+k]);
                    k++;
                }
                sort(v.begin(),v.end());

                k=0;
                while(k<v.size())
                {
                    mat[i+k][j+k]=v[k];
                    k++;
                }
            }


            return mat;
        
        
    }
};

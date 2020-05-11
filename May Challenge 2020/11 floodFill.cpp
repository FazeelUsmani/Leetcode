void fillColour (vector<vector<int>> &A, int i, int j, int M, int N, int reqColour, int newColour){
     
    if (A[i][j] == reqColour){
        A[i][j] = newColour;
        if (i >= 1) fillColour (A, i-1, j, M, N, reqColour, newColour);
        if (i+1 < M) fillColour (A, i+1, j, M, N, reqColour, newColour);
        if (j >= 1) fillColour (A, i, j-1, M, N, reqColour, newColour);
        if (j+1 < N) fillColour (A, i, j+1, M, N, reqColour, newColour);
    }
    return;       
}

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        if (image[sr][sc] == newColor)
            return image;
        
        fillColour (image, sr, sc, image.size(), image[0].size(),image[sr][sc], newColor);
        //cout<<image[0].size()<<" "<<image.size();
        return image;        
        
    }
};

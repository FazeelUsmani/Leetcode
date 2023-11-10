typedef long long ll;
struct Matrix {
    vector<vector<ll>> A;
    int rows, cols;
    Matrix(int rows = 0, int cols = 0) : rows(rows), cols(cols) {
        A.resize(rows);
        for (int i = 0; i < rows; ++i) A[i].assign(cols, 0);
    }
    Matrix(vector<vector<ll>> matrix) : A(matrix), rows(matrix.size()), cols(matrix[0].size()) {}
};

Matrix operator*(const Matrix &A, const Matrix &B) {
    Matrix res(A.rows, B.cols);
    for (int i = 0; i < A.rows; ++i)
        for (int j = 0; j < B.cols; ++j)
            for (int k = 0; k < A.cols; ++k)
                res.A[i][j] += A.A[i][k] * B.A[k][j];
    return res;
}

Matrix fastPow(const Matrix &matrix, int pow) { // return matrix ^ pow
    if (pow == 1) return matrix;
    Matrix half = fastPow(matrix, pow / 2);
    if (pow & 1) return half * half * matrix; // If pow is an odd number
    return half * half;
}

class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        Matrix matrix({
                              {0, 1, 0},
                              {0, 0, 1},
                              {1, 1, 1}
                      });
        Matrix M0({{0}, {1}, {1}});
        Matrix Mn = fastPow(matrix, n) * M0; // Mn = matrix^n * M0
        return Mn.A[0][0];
    }
};

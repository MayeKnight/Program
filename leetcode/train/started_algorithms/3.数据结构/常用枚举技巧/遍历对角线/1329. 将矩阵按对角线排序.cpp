//结合"前言.cpp中的模版"
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        // k = i - j + n
        // k最小为 k = 0 - (n - 1) + n = n, 最大 k = (m - 1) - 0 + n = m + n - 1
        for (int k = 1; k < m + n; k++) {
            //j = i - k + n
            //i取0时, j_min = n - k, i取m-1时, j_max = m + n - 1 - k
            int j_min = max(n - k, 0);
            int j_max = min(m + n - 1 - k, n - 1);
            vector<int> a;
            for (int j = j_min; j <= j_max; j++) {
                a.push_back(mat[k + j - n][j]);  //j知道, i就知道, i = k + j - n
            }
            sort(a.begin(), a.end());
            for (int j = j_min; j <= j_max; j++) {
                mat[k + j - n][j] = a[j - j_min];
            }
        }
        return mat;
    }
};
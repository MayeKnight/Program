class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        //k = i + j
        //k_min = 0, k_max = (m - 1) + (n - 1) = m + n - 2
        vector<int> a;
        for (int k = 0; k < m + n - 1; k++) {
            //j = k - i, i取(m - 1)时, j取最小值, j_min = k - (m - 1) = k - m + 1
            //j = k - i, i取0时, j取最大值, j_max = k
            int j_min = max(k - m + 1, 0);
            int j_max = min(k, n - 1);
            if (k % 2 == 0) {
                for (int j = j_min; j <= j_max; j++) {
                    a.push_back(mat[k - j][j]);  // i = k - j
                }
            }
            else {
                for (int j = j_max; j >= j_min; j--) {
                    a.push_back(mat[k - j][j]);
                }
            }
        }
        return a;
    }
};
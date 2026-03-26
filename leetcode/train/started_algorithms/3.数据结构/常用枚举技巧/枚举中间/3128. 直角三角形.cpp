class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        int n = grid[0].size();
        long long ans = 0;
        vector<int> col(n, -1);  //初始化为-1, 提前-1
        for (auto& row : grid) {
            for (int i = 0; i < n; i++) {
                col[i] += row[i];
            }
        }
        for (auto& row : grid) {
            int row_sum = reduce(row.begin(), row.end()) - 1;
            for (int i = 0; i < n; i++) {
                if (row[i] == 1) {
                    ans += row_sum * col[i];
                }
            }
        }
        return ans;
    }
};
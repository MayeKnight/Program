//结合"前言.cpp中的模版"
class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        //第一排在右上, 最后一排在左下 (这里的排是指对角线)
        //每排从左上到右下
        //令 k = i - j + n, 那么右上角那一排 k = 0 - (n - 1) + n = 1, 左下角那一排 k = (m - 1) - 0 + n = m + n - 1
        //枚举 k = 1, 2, 3, ..., m + n - 1, 相当于从右上到左下, 一条一条的枚举对角线
        for (int k = 1; k < m + n; k++) {
            int min_j = max(n - k, 0);   //求j的取值范围, 且有 j = i - k + n, 知道j就知道了i, i = 0时取 j_min = n - k
            int max_j = min(m + n - 1 - k, n - 1);  //i取 m - 1 时, j取 j_max = (m - 1) - k + n = m + n - 1 - k
            vector<int> a;
            for (int j = min_j; j <= max_j; j++) {
                a.push_back(grid[k + j - n][j]);   //知道j就知道了i, i = k + j - n
            }
            if (min_j > 0) { //右上三角形
                sort(a.begin(), a.end());
            }
            else {   //左下三角形
                sort(a.begin(), a.end(), greater<int>());  //降序排序
            }
            //放回
            for (int j = min_j; j <= max_j; j++) {
                grid[k + j - n][j] = a[j - min_j];
            }
        }
        return grid;
    }
};
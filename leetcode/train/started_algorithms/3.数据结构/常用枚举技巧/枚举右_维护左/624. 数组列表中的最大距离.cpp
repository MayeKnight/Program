class Solution {
public:
    //先用当前数组的最大值最小值与之前的全局最小值，最大值计算差值，更新ans, 再更新全局最小值，最大值
    int maxDistance(vector<vector<int>>& arrays) {
        int min = arrays[0][0], max = arrays[0][arrays[0].size() - 1];
        int ans = -1, recm = -1, recx = -1;
        for (int i = 1; i < arrays.size(); i++) {
            if (abs(arrays[i][arrays[i].size() - 1] - min) > abs(max - arrays[i][0])) {
                if (ans < abs(arrays[i][arrays[i].size() - 1] - min)) {
                    ans = abs(arrays[i][arrays[i].size() - 1] - min);
                }
            }
            else {
                if (ans < abs(max - arrays[i][0])) {
                    ans = abs(max - arrays[i][0]);
                }
            }
            if (arrays[i][0] < min) {
                min = arrays[i][0];
            }
            if (arrays[i][arrays[i].size() - 1] > max) {
                max = arrays[i][arrays[i].size() - 1];
            }
        }
        return ans;
    }
};

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        long long sum = 0, ans = 0, mx = -1;
        long long n = blocks.length();
        for (int i = 0; i < n; i++) {
            // 进入窗口
            if (blocks[i] == 'B') {
                sum++;
            }
            if (i < k - 1) {
                continue;
            }
            // 更新答案
            mx = max(sum, mx);
            // 离开窗口
            if (blocks[i - k + 1] == 'B') {
                sum--;
            }
        }
        return k - mx;
    }
};
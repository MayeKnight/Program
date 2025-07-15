class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        // 环状数组常通过取模避免手动扩展
        int n = code.size(), sum = 0, k2 = abs(k);
        vector<int> ans(n, 0);
        if (k > 0) {
            for (int i = 1; i < k; i++) {
                sum += code[i];
            }
            for (int i = k; i < n + k; i++) {
                //添加
                sum += code[i % n];
                //更新
                ans[(i - k) % n] = sum;
                //移除
                sum -= code[(i - k + 1) % n];
            }
        }
        if (k < 0) {
            for (int i = n - k2; i < n - 1; i++) {
                sum += code[i];
            }
            for (int i = n - 1; i < (n - 1) + n; i++) {
                //添加
                sum += code[i % n];
                //更新
                ans[(i + 1) % n] = sum;
                //移除
                sum -= code[(i - k2 + 1) % n];
            }
        }
        return ans;
    }
};



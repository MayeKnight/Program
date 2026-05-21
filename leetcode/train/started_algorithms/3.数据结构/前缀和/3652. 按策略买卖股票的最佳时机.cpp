class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        vector<long long> sum(n + 1), sumsell(n + 1);
        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + prices[i] * strategy[i];
            sumsell[i + 1] = sumsell[i] + prices[i];
        }
        long long ans = sum[n];
        for (int i = k; i <= n; i++) {
            long long res = sum[i - k] + sum[n] - sum[i] + sumsell[i] - sumsell[i - k / 2];
            ans = max(ans, res);
        }
        return ans;
    }
};

//枚举数组[i - k, i - 1] 
//分三部分
//[0, i - k - 1]   sum[i - k]        //求[left, right]的元素和, 这种表述下则为 前缀和[right + 1] - 前缀和[left]
//[i, n - 1]  sum[n] - sum[i]
//[i - k, i - 1]  sumsell[i] - sumsell[i - k / 2] 
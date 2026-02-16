class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), ans = 0, minprice = 1e9, maxprice = -1, cnt = 0;
        for (int i = 0; i < n; i++) {
            if (prices[i] > maxprice) {
                maxprice = prices[i];
                cnt++;
            }
            if (prices[i] < minprice) {
                minprice = prices[i];
                maxprice = -1;
            }
            if (maxprice != -1 && maxprice - minprice > ans) {
                ans = maxprice - minprice;
            }
        }
        if (cnt > 1 && ans > 0) {
            return ans;
        }
        return 0;
    }
};
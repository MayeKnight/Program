class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long n = nums.size(), ans = INT_MIN;
        vector<int> suf(n, 0);
        suf[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suf[i] = max(nums[i], suf[i + 1]);
        }
        int pre = nums[0];
        for (int i = 1; i < n - 1; i++) {
            ans = max(ans, 1LL * (pre - nums[i]) * suf[i + 1]);
            pre = max(pre, nums[i]);
        }
        if (ans < 0) {
            return 0;
        }
        else return ans;
    }
};
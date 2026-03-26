class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size(), ans = INT_MAX;
        vector<int> suf(n); //后缀最小值
        suf[n - 1] = nums[n - 1];
        for (int i = n - 2; i > 1; i--) {
            suf[i] = min(nums[i], suf[i + 1]);
        }
        int pre = nums[0]; //前缀最小值
        for (int j = 1; j < n - 1; j++) {
            if (nums[j] > pre && nums[j] > suf[j + 1]) {
                ans = min(pre + nums[j] + suf[j + 1], ans);
            }
            pre = min(pre, nums[j]);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), ans = 1e9, res = 0, left = 0;
        for (int i = 0; i < n; i++) {
            res += nums[i];
            if (res < target) {
                continue;
            }
            while (res >= target) {
                res -= nums[left];
                left++;
                ans = min(ans, i - left + 2);
            }
        }
        if (ans == 1e9) {
            ans = 0;
        }
        return ans;
    }
};
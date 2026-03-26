class Solution {
public:
    int sol(vector<int>&nums, int left, int right) {
        int n = nums.size();
        vector<int> res;
        res.resize(nums.size() + 1);
        for (int i = 0; i < nums.size(); i++) {
            res[i + 1] = res[i] + nums[i];
        }
        return res[right + 1] - res[left];
    }
    int subarraySum(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            int start = max(0, i - nums[i]);
            ans += sol(nums, start, i);
        }
        return ans;
    }
};
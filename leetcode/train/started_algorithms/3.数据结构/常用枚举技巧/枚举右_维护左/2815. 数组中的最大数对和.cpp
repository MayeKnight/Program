class Solution {
public:
    int f(int& x) {
        int res = 0;
        for (int i = x; i > 0; i /= 10) {
            res = max(res, i % 10);
        }
        return res;
    }
    int maxSum(vector<int>& nums) {
        int n = nums.size(), ans = -1;
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            if (mp.find(f(nums[i])) != mp.end()) {
                ans = max(ans, nums[i] + mp[f(nums[i])]);
                mp[f(nums[i])] = max(mp[f(nums[i])], nums[i]);
            }
            else {
                mp[f(nums[i])] = nums[i];
            }
        }
        return ans;
    }
};
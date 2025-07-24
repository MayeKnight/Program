class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size(), mx = 0, ans = 0, left = 0;
        unordered_set<int> res;
        for (int i = 0; i < n; i++) {
            if (n == 0) {
                return 0;
            }
            while (res.count(nums[i])) {
                res.erase(res.find(nums[left]));
                ans -= nums[left];
                left++;
            }
            ans += nums[i];
            res.insert(nums[i]);
            mx = max(mx, ans);
        }
        return mx;
    }
};
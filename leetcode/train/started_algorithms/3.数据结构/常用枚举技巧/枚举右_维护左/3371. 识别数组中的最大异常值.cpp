class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int n = nums.size(), total = 0, ans = -1e9;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            total += nums[i];
            mp[nums[i]]++;
        }
        for (int i = 0; i < n; i++) {
            mp[nums[i]]--;
            if ((total - nums[i]) % 2 == 0) {
                if (mp[(total - nums[i]) / 2] > 0) {
                    ans = max(ans, nums[i]);

                }
            }
            mp[nums[i]]++;
        }
        return ans;
    }
};
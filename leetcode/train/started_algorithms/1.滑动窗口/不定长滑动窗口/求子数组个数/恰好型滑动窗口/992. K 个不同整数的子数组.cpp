class Solution {
public:
    int solve(vector<int>& nums, int k) {
        unordered_map<int, int> res;
        int ans = 0, left = 0;
        for (int i = 0; i < nums.size(); i++) {
            res[nums[i]]++;
            while (res.size() >= k) {
                if (--res[nums[left]] == 0) {
                    res.erase(nums[left]);
                }
                left++;
            }
            ans += left;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        if (nums.size() == 0 || k < 0) {
            return 0;
        }
        return solve(nums, k) - solve(nums, k + 1);
    }
};
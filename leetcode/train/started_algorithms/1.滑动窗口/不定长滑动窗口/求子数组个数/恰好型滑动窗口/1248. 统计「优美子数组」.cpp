class Solution {
public:
    int solve(vector<int>& nums, int k) {
        int res = 0, ans = 0, left = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 1) {
                res++;
            }
            while (left <= i && res >= k) {
                if (nums[left] % 2 == 1) {
                    res--;
                }
                left++;
            }
            ans += left;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        if (nums.size() == 0 || k == 0) {
            return 0;
        }
        return solve(nums, k) - solve(nums, k + 1);
    }
};
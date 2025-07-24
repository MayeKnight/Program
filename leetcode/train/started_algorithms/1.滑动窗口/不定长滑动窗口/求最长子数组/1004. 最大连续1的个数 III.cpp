class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0, res = 0, left = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] != 1) {
                res++;
            }
            while (res > k) {
                if (nums[left] != 1) {
                    res--;
                }
                left++;
            }
            ans = max(ans, i - left + 1);
        }
        return ans;
    }
};
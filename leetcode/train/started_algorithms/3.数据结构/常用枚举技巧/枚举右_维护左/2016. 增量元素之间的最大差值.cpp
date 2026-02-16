class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size(), min = 1e9 + 1, recm = 0, max = -1, recx = 0, ans = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] > max && nums[i] > min) {
                max = nums[i];
                recx = i;
            }
            if (nums[i] < min) {
                min = nums[i];
                recm = i;
                max = -1;
            }
            if (recx > recm && max != -1 && max - min > ans) {
                ans = max - min;
            }
        }
        return ans;
    }
};
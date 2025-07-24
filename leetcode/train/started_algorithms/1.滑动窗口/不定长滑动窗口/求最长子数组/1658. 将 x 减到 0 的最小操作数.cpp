class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        //逆向思维转化为滑动窗口, 窗口内元素的和应为sum - x
        int target = accumulate(nums.begin(), nums.end(), 0) - x;  //计算sum - x
        int n = nums.size(), ans = -1, res = 0, left = 0;
        if (target < 0) {  //target < 0 说明x大于数组内所有元素的和, 相减后不可能等于0
            return -1;
        }
        for (int i = 0; i < n; i++) {
            res += nums[i];
            while (res > target) {
                res -= nums[left];
                left++;
            }
            if (res == target) {
                ans = max(ans, i - left + 1);
            }
        }
        if (ans != -1) {
            return n - ans;
        }
        else return -1;
    }
};
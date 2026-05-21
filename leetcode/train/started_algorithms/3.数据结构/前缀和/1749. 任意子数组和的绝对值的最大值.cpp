class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size(), ans = -1;
        vector<int> res(n + 1);
        for (int i = 1; i < n + 1; i++) {
            res[i] = res[i - 1] + nums[i - 1];
        }
        ans = abs(ranges::max(res) - ranges::min(res));
        return ans;
    }
};

//前缀和的最大值-最小值取绝对值，得到子数组和绝对值的最大值
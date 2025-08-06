class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int res = 1, left = 0, ans = 0;
        for (int right = 0; right < nums.size(); right++) {
            if (k <= 1) {
                return 0;  //默认k初始为0, 编译器试运行了一下, 再下面的while陷入死循环报错, 所以要有这一步
            }
            //进入窗口
            res *= nums[right];
            //满足窗口条件
            while (res >= k) {
                //收缩左边界
                res /= nums[left];
                left++;
            }
            ans += right - left + 1;
        }
        return ans;
    }
};
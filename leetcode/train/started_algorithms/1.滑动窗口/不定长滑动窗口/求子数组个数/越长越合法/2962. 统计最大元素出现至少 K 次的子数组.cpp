class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int mx = ranges::max(nums);  //函数ranges::max(nums) 找到数组的最大值
        long long ans = 0;
        int cnt_mx = 0, left = 0; //cnt_mx计数窗口最大值数量
        for (int x : nums) {
            //进入窗口
            cnt_mx += x == mx;  //如果当前元素x是mx, 则cnt_mx加一
            //窗口满足条件
            while (cnt_mx == k) {
                //收缩左边界
                cnt_mx -= nums[left] == mx;
                left++;
            }
            ans += left;
        }
        return ans;
    }
};
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans = 0, left = 0, res = 0, rec = 0;
        for (int i = 0; i < nums.size(); i++) {
            //进入窗口
            res += nums[i];
            rec = res * (i - left + 1);
            //满足窗口条件
            while (rec >= k) {
                //缩小左边界
                res -= nums[left];
                left++;
                rec = res * (i - left + 1);
            }
            ans += i - left + 1;
        }
        return ans;
    }
};
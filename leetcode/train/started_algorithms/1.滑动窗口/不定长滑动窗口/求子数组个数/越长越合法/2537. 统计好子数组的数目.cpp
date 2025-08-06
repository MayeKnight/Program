class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        //如果窗口中有c个元素x， 再进来一个x, 会增加c个相等数对
        //如果窗口中有c个元素x, 再去掉一个x, 会减少c - 1个相等数对
        unordered_map<int, int> res;
        long long pairs = 0, ans = 0, left = 0;
        for (int c : nums) {
            //进入窗口
            pairs += res[c]++;
            //满足窗口条件
            while (pairs >= k) {
                //收缩左边界
                pairs -= --res[nums[left]];
                left++;
            }
            ans += left;
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        long long sum = 0;
        int n = nums.size();
        vector<int> avgs(n, -1); // 将数组avgs各元素初始化为-1
        if (2 * k + 1 > n) {
            return avgs; //无法形成任何窗口时
        }
        //计算初始窗口的和
        for (int i = 0; i < 2 * k + 1; i++) {
            sum += nums[i];
        }
        avgs[k] = sum / (2 * k + 1); //第一个窗口有效值
        //滑动窗口
        for (int i = k + 1; i < n - k; i++) {
            sum -= nums[i - k - 1];
            sum += nums[i + k];
            avgs[i] = sum / (2 * k + 1);
        }
        return avgs;
    }

};
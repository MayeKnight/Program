class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long n = nums.size(), ans = INT_MIN, mi = 0;
        if (nums.size() == 1) {
            return nums[0];
        }
        vector<long long> res(n + 1);
        for (int i = 0; i < n; i++) {
            res[i + 1] = res[i] + nums[i];
            ans = max(ans, res[i + 1] - mi);
            mi = min(mi, res[i + 1]);
        }
        return ans;
    }
};

//动态维护当前的最小前缀和，用当前前缀和-最小前缀和，取最大值，从而得到最大的子数组的和，  求[left, right]的元素和, 这种表述下则为 前缀和[right + 1] - 前缀和[left]
//而不能直接用 ans = ranges::max(res) - ranges::min(res);, 因为这里并没有像 "D:\Tech\Code\Program\leetcode\train\started_algorithms\3.数据结构\前缀和\1749. 任意子数组和的绝对值的最大值.cpp" 取绝对值
//而要考虑 后-前, 否则会影响正负性.
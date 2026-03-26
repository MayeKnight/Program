class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        const int MOD = 1e9 + 7;
        unordered_map<int, int> suf;
        for (int x : nums) {
            suf[x]++;
        }
        unordered_map<int, int> pre;
        for (int x : nums) {
            suf[x]--;
            ans += 1LL * pre[x * 2] * suf[x * 2];
            pre[x]++;
        }
        return ans % MOD;
    }
};






// 方法：枚举中间
// 三变量问题，一般枚举中间的变量最简单。为什么？对比一下：

// 枚举 i, 后续计算中还需保证 j < k。
// 枚举 j, 那么 i 和 k 自动被 j 隔开，互相独立，后续计算中无需关心 i 和 k 的位置关系。
// 枚举中间的 j, 问题变成:

// 在[0, j - 1] 中, nums[j]⋅2 的出现次数。
// 在[j + 1, n - 1] 中, nums[j]⋅2 的出现次数。
// 在这些出现次数中，左右两边各选一个。根据乘法原理，把这两个出现次数相乘，加到答案中。
// 用哈希表（或者数组）统计 j 左右每个数的出现次数。

// 右边的元素出现次数，可以先统计整个数组，然后再次遍历数组，撤销[0, j] 中统计的元素出现次数，即为[j + 1, n−1] 中的元素出现次数。
// 左边的元素出现次数，可以一边遍历 nums, 一边统计。
        
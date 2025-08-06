class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        long long total = reduce(nums.begin(), nums.end(), 0ll), left = 0, sum = 0;
        long long n = nums.size(), ans = 1e9;
        for (int i = 0; i < 2 * n; i++) {
            sum += nums[i % n];  //循环数组
            while (sum > target % total) {
                sum -= nums[left % n];
                left++;
            }
            if (sum == target % total) {
                ans = min(ans, i - left + 1);
            }
        }
        return ans == 1e9 ? -1 : target / total * n + ans; //ans == 1e9则返回-1, 否则返回有效值
    }
};
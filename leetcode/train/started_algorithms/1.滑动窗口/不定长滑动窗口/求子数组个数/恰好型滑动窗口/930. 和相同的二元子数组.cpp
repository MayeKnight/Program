class Solution {
public:
    //越长越合法
    //答案就是元素和 ≥k 的子数组个数，减去元素和 ≥k+1 的子数组个数。这里把 > 转换成 ≥，从而可以把滑窗逻辑封装成一个函数 f, 然后用 f(k) - f(k + 1) 计算，无需编写两份滑窗代码。
    int solve(vector<int>& nums, int goal) {
        int ans = 0, left = 0, res = 0;
        for (int i = 0; i < nums.size(); i++) {
            res += nums[i];
            while (left <= i && res >= goal) {
                res -= nums[left];
                left++;
            }
            ans += left;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        if (goal < 0 || nums.size() == 0) {
            return 0;
        }
        else {
            return solve(nums, goal) - solve(nums, goal + 1);
        }
    }
};

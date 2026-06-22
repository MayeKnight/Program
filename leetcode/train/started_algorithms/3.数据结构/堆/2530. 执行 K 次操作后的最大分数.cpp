class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans = 0, res = 0;
        make_heap(nums.begin(), nums.end());
        while (k--) {
            ans += nums[0];
            res = ceil(static_cast<double>(nums[0]) / 3);
            pop_heap(nums.begin(), nums.end());
            nums.pop_back();
            nums.push_back(res);
            push_heap(nums.begin(), nums.end());
        }
        return ans;
    }
};
class Solution {
public:
    int lower_bound(vector<int>& nums, int target) {
        int left = 0, mid = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            mid = (left + right) / 2;
            if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left;
    }
    int searchInsert(vector<int>& nums, int target) {
        int res = lower_bound(nums, target);
        if (res >= nums.size() || nums[res] != target)
            return res;
        else
            return res;
    }
};
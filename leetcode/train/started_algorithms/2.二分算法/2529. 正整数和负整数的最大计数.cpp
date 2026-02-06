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
    int maximumCount(vector<int>& nums) {
        int start = lower_bound(nums, 0);
        int end = lower_bound(nums, 1) - 1;
        if (start < nums.size() - end - 1) {
            return nums.size() - end - 1;
        }
        else
        {
            return start;
        }
    }
};
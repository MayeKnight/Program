class Solution {
public:
    int lower_bound(vector<int>& nums, int target) {
        int left = 0, mid = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }

        }
        return left;
    }
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> res;
        ranges::sort(nums);
        partial_sum(nums.begin(), nums.end(), nums.begin());  //前缀和原地计算
        for (int i = 0; i < queries.size(); i++) {
            res.push_back(lower_bound(nums, queries[i] + 1) - 1 + 1);
        }
        return res;
    }
};
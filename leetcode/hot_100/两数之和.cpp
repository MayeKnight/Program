class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> res;
        for (int i = 0; i < n; i++) {
            if (res.find(target - nums[i]) != res.end()) {
                return { res[target - nums[i]], i };
            }
            res[nums[i]] = i;
        }
        return {};
    }
};
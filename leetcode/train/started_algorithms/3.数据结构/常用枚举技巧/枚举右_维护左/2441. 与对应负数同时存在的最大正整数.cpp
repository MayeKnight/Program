class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_map<int, int> hash;
        int n = nums.size(), ans = -1;
        for (int i = 0; i < n; i++) {
            if (hash.find(-nums[i]) != hash.end()) {
                if (ans < abs(nums[i])) {
                    ans = abs(nums[i]);
                }
            }
            else {
                hash[nums[i]] = 1;
            }
        }
        return ans;
    }
};
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size(),ans = 0;
        unordered_map<int, int> hashMap;
        for (int i = 0; i < n; i++) {
            if (hashMap.find(nums[i]) != hashMap.end()) {
                ans += hashMap[nums[i]];
                hashMap[nums[i]]++;
            }
            else {
                hashMap[nums[i]] = 1;
            }
        }
        return ans;
    }
};
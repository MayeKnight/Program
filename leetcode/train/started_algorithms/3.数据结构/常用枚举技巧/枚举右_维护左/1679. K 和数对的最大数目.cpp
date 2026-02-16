class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size(), res = 0, ans = 0;
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            if (mp.find(nums[i]) != mp.end()) {
                ans++;
                mp[nums[i]]--;
                if (mp[nums[i]] == 0) {
                    mp.erase(nums[i]);
                }
            }
            else
            {
                res = k - nums[i];
                mp[res]++;
            }
        }
        return ans;
    }
};
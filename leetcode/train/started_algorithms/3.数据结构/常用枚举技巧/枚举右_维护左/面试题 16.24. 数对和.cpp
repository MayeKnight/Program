class Solution {
public:
    vector<vector<int>> pairSums(vector<int>& nums, int target) {
        int n = nums.size();
        int res = 0;
        vector<vector<int>> ans;
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            if (mp.find(nums[i]) != mp.end()) {
                ans.insert({ target - nums[i], nums[i] });
                mp[nums[i]]--;
                if (mp[nums[i]] == 0) {
                    mp.erase(nums[i]);
                }
            }
            else {
                res = target - nums[i];
                mp[res]++;
            }
        }
        return ans;
    }
};
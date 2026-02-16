class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        //nums[i] - i != nums[j] - j
        long long n = nums.size(), res = 0, ans = 0;
        unordered_map<int, int> mp;
        for (long long i = 0; i < n; i++) {
            nums[i] = nums[i] - i;
        }
        sort(nums.begin(), nums.end());
        res = n * (n - 1) / 2;
        for (long long i = 0; i < n; i++) {
            if (mp.find(nums[i]) != mp.end()) {
                ans += mp[nums[i]];
                mp[nums[i]]++;
            }
            else {
                mp[nums[i]]++;
            }
        }
        return res - ans;
    }
};
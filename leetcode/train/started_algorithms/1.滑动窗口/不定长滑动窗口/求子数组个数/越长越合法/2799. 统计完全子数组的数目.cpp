class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_map<int, int> con;
        for (int i = 0; i < nums.size(); i++) {
            con[nums[i]]++;
        }
        int n = con.size(), left = 0, ans = 0;
        unordered_map<int, int> res;
        for (int i = 0; i < nums.size(); i++) {
            //进入窗口
            res[nums[i]]++;
            //满足窗口条件
            while (res.size() == n) {
                //收缩左边界
                if (--res[nums[left]] == 0) {
                    res.erase(nums[left]);
                }
                left++;
            }
            ans += left;
        }
        return ans;
    }
};